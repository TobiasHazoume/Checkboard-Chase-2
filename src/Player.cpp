#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Entity.hpp"
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Player.hpp>
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
}

void Player::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= PLAYER_VEL; break;
            case SDLK_DOWN: mVelY += PLAYER_VEL; break;
            case SDLK_LEFT: mVelX -= PLAYER_VEL; break;
            case SDLK_RIGHT: mVelX += PLAYER_VEL; break;
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

