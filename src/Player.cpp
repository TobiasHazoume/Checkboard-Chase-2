#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Player.hpp>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Initialize.hpp>

#include<iostream>


SDL_Texture* Player::loadTexture( std::string path,Initialize gameinit )
{
	
    //The final texture which will be returned at the end on this
	//function
	SDL_Texture* newTexture = NULL;

	//Loads image at specified path using the SDL_Image api
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	//check if  loadedSurface  has a value in it
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
        Initialize playerInitialzer; //this is the problem!!!!!!
		//if loadedSurface has a value in it then 
		//creates a new texture from an existing surface
        newTexture = SDL_CreateTextureFromSurface( gameinit.gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface we wont need it
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool Player::loadPlayer(Initialize gameinit)
{
    //Loading success flag
	bool success = true;

    //[reminder] put a swith stament here that changes the spite loaded based on if its palyer 1 or 2
	//Load PNG texture
	gTexture = loadTexture( "C:/Users/Tobias/Documents/programming_projects/Learning_C++/Checkboard-Chase-2/res/gfx/wha.png", gameinit );
	
	if( gTexture == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}

	//Load default Texture
	gKeyPressTextures[ KEY_PRESS_TEXTURE_DEFAULT ] = loadTexture( "C:/Users/Tobias/Documents/programming_projects/Learning_C++/Checkboard-Chase-2/res/gfx/green_link_down.png", gameinit );
	if( gKeyPressTextures[ KEY_PRESS_TEXTURE_DEFAULT ] == NULL )
	{
		printf( "Failed to load default image!\n" );
		success = false;
	}

	//Load up Texture
	gKeyPressTextures[ KEY_PRESS_TEXTURE_UP ] = loadTexture( "C:/Users/Tobias/Documents/programming_projects/Learning_C++/Checkboard-Chase-2/res/gfx/green_link_up.png",gameinit );
	if( gKeyPressTextures[ KEY_PRESS_TEXTURE_UP ] == NULL )
	{
		printf( "Failed to load up image!\n" );
		success = false;
	}

	//Load down Texture
	gKeyPressTextures[ KEY_PRESS_TEXTURE_DOWN ] = loadTexture( "C:/Users/Tobias/Documents/programming_projects/Learning_C++/Checkboard-Chase-2/res/gfx/green_link_down.png",gameinit );
	if( gKeyPressTextures[ KEY_PRESS_TEXTURE_DOWN ] == NULL )
	{
		printf( "Failed to load down image!\n" );
		success = false;
	}

	//Load left Texture
	gKeyPressTextures[ KEY_PRESS_TEXTURE_LEFT ] = loadTexture( "C:/Users/Tobias/Documents/programming_projects/Learning_C++/Checkboard-Chase-2/res/gfx/green_link_left.png",gameinit );
	if( gKeyPressTextures[ KEY_PRESS_TEXTURE_LEFT ] == NULL )
	{
		printf( "Failed to load left image!\n" );
		success = false;
	}

	//Load right Texture
	gKeyPressTextures[ KEY_PRESS_TEXTURE_RIGHT ] = loadTexture( "C:/Users/Tobias/Documents/programming_projects/Learning_C++/Checkboard-Chase-2/res/gfx/green_link_right.png",gameinit );
	if( gKeyPressTextures[ KEY_PRESS_TEXTURE_RIGHT ] == NULL )
	{
		printf( "Failed to load right image!\n" );
		success = false;
	}

	//Load attack Texture
	gKeyPressTextures[ KEY_PRESS_TEXTURE_ATTACK ] = loadTexture( "C:/Users/Tobias/Documents/programming_projects/Learning_C++/Checkboard-Chase-2/res/gfx/kirby_shade.png",gameinit );
	if( gKeyPressTextures[ KEY_PRESS_TEXTURE_ATTACK ] == NULL )
	{
		printf( "Failed to load attack image!\n" );
		success = false;
	}

	//me testing the spwan point
	renderQuad.x = 250;
	renderQuad.y = 70;
	renderQuad.w = 50;
	renderQuad.h = 50;
	
	

	return success;
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
            case SDLK_UP: mVelY += PLAYER_VEL; break;
            case SDLK_DOWN: mVelY -= PLAYER_VEL; break;
            case SDLK_LEFT: mVelX += PLAYER_VEL; break;
            case SDLK_RIGHT: mVelX -= PLAYER_VEL; break;
        }
		//this is to stop the y and why position to not build up over time which
		// causes a rubber band like effect
		mPosY =0;
		mPosX= 0;
    }
}

void Player::move()
{
	//[!] set up the if statements so the player cant leave the 
	//checkboard

    //Move the dot left or right
    mPosX += mVelX;
	//change the x pos of the player
	renderQuad.x += mPosX;

    //If the dot went too far to the left or right
    //if( ( mPosX < 0 ) /*|| ( mPosX + PLAYER_WIDTH > gameinit.SCREEN_WIDTH )*/ )
   // {
        //Move back
    //    mPosX -= mVelX;
   // }

    //Move the dot up or down
    mPosY += mVelY;
	//change the x pos of the player
	renderQuad.y += mPosY;

    //If the dot went too far up or down
   // if( ( mPosY < 0 ) /*|| ( mPosY + PLAYER_HEIGHT > gameinit.SCREEN_HEIGHT )*/ )
   // {
        //Move back
   //     mPosY -= mVelY;
	//}
}
 

