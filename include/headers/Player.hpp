#pragma once
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Entity.hpp"
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\LTexture.hpp"

class Player : public Entity 
{
public:

    //Maximum axis velocity of the player
	static const int PLAYER_VEL = 10;

    //this will represent every frame of animation
    enum PlayerAnimations
    {
        PLAYER_DEFAULT,
        PLAYER_UP,
        PLAYER_DOWN,
        PLAYER_LEFT,
        PLAYER_RIGHT,
        PLAYER_ATTACK,
        PLAYER_FALL1,
        PLAYER_FALL2,
        PLAYER_ANIMATIONS_TOTAL
    };

    //the array of clips sprites USE AN ENUM
    SDL_Rect gLinkClips[ PLAYER_ANIMATIONS_TOTAL ];


    
    //member to hold the texture file
    LTexture gLinkSkin;

    // make a player object using a constuctior and provide its initial
    // initial pos on the screen and itis idle texture  on the screen
    Player(Entity p_spawnPoint);

    //Takes key presses and adjusts the player's velocity
	void handleEvent( SDL_Event& e );

    //Moves the player
    void move();

/*
    //Shows the player on the screen
    void render();*/


 private:
    Entity spawnPoint;

    //The X and Y offsets of the player
    int mPosX, mPosY;

    //The velocity of the player
    int mVelX, mVelY;



};