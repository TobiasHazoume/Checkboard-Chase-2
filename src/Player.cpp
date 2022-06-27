#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Entity.hpp"
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Player.hpp>
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\LTexture.hpp"
#include<iostream>


Player::Player(Entity p_spawnPoint)
:spawnPoint(p_spawnPoint)
{
    //Initialize the offsets
    mPosX = p_spawnPoint.getPos().x;
    mPosY = p_spawnPoint.getPos().y;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;   

    //inital sprite
    gLinkClips[ PLAYER_DEFAULT ].x = 3;
	gLinkClips[ PLAYER_DEFAULT ].y = 22;
	gLinkClips[ PLAYER_DEFAULT ].w = 20;
	gLinkClips[ PLAYER_DEFAULT ].h = 26;
}

void Player::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity and clip sprite
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: 
            //change velocity
            mVelY -= PLAYER_VEL;  
            //Setup the up sprite
            gLinkClips[ PLAYER_UP ].x = 39;
            gLinkClips[ PLAYER_UP ].y = 184;
            gLinkClips[ PLAYER_UP ].w = 20;
            gLinkClips[ PLAYER_UP ].h = 27;
            break;

            case SDLK_DOWN: 
            mVelY += PLAYER_VEL; 
            gLinkClips[ PLAYER_DOWN ].x = 39;
            gLinkClips[ PLAYER_DOWN ].y = 242;
            gLinkClips[ PLAYER_DOWN ].w = 19;
            gLinkClips[ PLAYER_DOWN ].h = 30;
            break;

            case SDLK_LEFT:
            mVelX -= PLAYER_VEL; 
            gLinkClips[ PLAYER_LEFT ].x = 37;
            gLinkClips[ PLAYER_LEFT ].y = 216;
            gLinkClips[ PLAYER_LEFT ].w = 25;
            gLinkClips[ PLAYER_LEFT ].h = 23;
            break;

            case SDLK_RIGHT: 
            mVelX += PLAYER_VEL;
            gLinkClips[ PLAYER_RIGHT ].x = 32;
            gLinkClips[ PLAYER_RIGHT ].y = 277;
            gLinkClips[ PLAYER_RIGHT ].w = 27;
            gLinkClips[ PLAYER_RIGHT ].h = 25; 
            break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: 
            mVelY += PLAYER_VEL;
            std::cout << "up" << std::endl;
             break;
            case SDLK_DOWN: mVelY -= PLAYER_VEL; 
            std::cout << "down" << std::endl;
            break;
            case SDLK_LEFT: mVelX += PLAYER_VEL; break;
            case SDLK_RIGHT: mVelX -= PLAYER_VEL; break;
        }
    }
}

void Player::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    //FIX: undo the hard coding for this width and height
    if( ( mPosX < 0 ) || ( mPosX > 1080 ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    //FIX: undo the hard coding for this width and height
    if( ( mPosY < 0 ) || ( mPosY > 700 ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

