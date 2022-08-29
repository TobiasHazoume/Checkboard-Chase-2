
#pragma once
//#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
//#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include<iostream>

class Initialize
{
public:
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Starts up SDL and creates window.
    //(init is short for initialize) 
    bool init();

};