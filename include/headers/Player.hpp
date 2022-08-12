#pragma once
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Initialize.hpp>
#include<iostream>

class Player
{

public:


    

    //Key press textures constants
    //these help assign pictures to our gKeyPressTextures array
    //these are basicly the pictures for all the "animations" for the player
    enum KeyPressTextures 
    {
        KEY_PRESS_TEXTURE_DEFAULT,
        KEY_PRESS_TEXTURE_UP,
        KEY_PRESS_TEXTURE_DOWN,
        KEY_PRESS_TEXTURE_LEFT,
        KEY_PRESS_TEXTURE_RIGHT,
        KEY_PRESS_TEXTURE_ATTACK,
        KEY_PRESS_TEXTURE_TOTAL
    };

    //The array images that correspond to a keypress
    SDL_Texture* gKeyPressTextures[ KEY_PRESS_TEXTURE_TOTAL ];

    //Current displayed  UNNEEDED
   // SDL_Texture* gCurrentTexture = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;

    //Maximum axis velocity of the player
	static const int PLAYER_VEL = 10;

    //figure out were to spwan the player on the screen

    //make a struc that will hold the point  onthe screen we want
    // the player to be aswell as thier size
    int x,y,mWidth,mHeight;
	SDL_Rect renderQuad = { x,y,mWidth,mHeight};

    //point to SDL_Rect renderQuad 
    SDL_Rect* pointRenderQuad = &renderQuad;
    
    //takes in a path to an image so that it
    //Loads an individual image  as texture later
    SDL_Texture* loadTexture( std::string path, Initialize gameinit );

    //this uses the load Texture funtion so the texture is properly
    //loaded onto gTexture
    bool loadPlayer(Initialize gameinit);
    //render the player texture
    void render();
    //move the player based on user input
    void move();

    //take in key presses from the user which changes the players velocity
    void handleEvent( SDL_Event& e );

    //an emun that stores the diff states the player wil be in

    // a hurtbox for the player

    //collision detection for the player for decteing if the player is at 
    //touching wall,another player an item for has been hit 

    //an attack funtion for the player

    //item state enum, make sure this doesnt conflict with the player state enum

    //a way to handle animations depening on what the player has inputed 

    //a way to figure out what controller or keyboard the player is using

    //a debug switch that shows the direction the player is inputing aswell
    //as thier states




private:


    //the players heatlh ingame
    int mHealth = 5;

    //The X and Y offsets of the player. this is needed for movement
    int mPosX, mPosY;

    //The velocity of the player.this is needed for movement
    int mVelX, mVelY;


};