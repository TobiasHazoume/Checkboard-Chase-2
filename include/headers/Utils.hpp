#pragma once
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>

//Utils is short for Utilities.
//This will store printing fns and the elapsed time the program has
//been running in secs

//a name space is a group for your code
namespace utils
{
    //inline is for defineing a fn in the header file
    inline float hireTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t*=0.001f;
        return t;

    }

}