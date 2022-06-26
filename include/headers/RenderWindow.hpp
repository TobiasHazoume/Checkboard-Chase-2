// makes sure the header doesnt copy twice to a file
#pragma once 
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Entity.hpp"
class RenderWindow {
    public:
        //contructor
        //this will be the title of our window,its width , and height
        // the p_ is a notation to show that these  are parammeter variables
        RenderWindow(const char* p_title,int p_w, int p_h);
        
        //draw a trexture to the screens?
        SDL_Texture* loadTexture(const char* p_filePath);
        //we need to manuall destroy the window our selfves or we might get a memoryleak.
        //usualy a decontructor is used to do this but he chose to "risk it"
        void cleanUp();

        int getRefreshRate();
        //clear the screen 
        void clear();
        //render a texture
        void render(Entity& p_entity);
        //display the texture to our screen
        void display();
    private:
    //we're using pointers to get the memory address of the
    //variables we're using??
    //the sdl window wont live in this class
    //https://youtu.be/pjLpipQRMIw?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS&t=788
    //our game window
    SDL_Window* window;
    //will turn our game into somthing we can display on to ourscreen
    SDL_Renderer* renderer;
};