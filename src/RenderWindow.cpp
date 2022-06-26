#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\RenderWindow.hpp"
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Entity.hpp"
#include <iostream>
//whats win undef https://youtu.be/pjLpipQRMIw?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS&t=991

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    //this is a null pointer to test if this window acually rendered
    // for more info: https://en.cppreference.com/w/cpp/language/constructor
    :window(NULL),renderer(NULL)
{
   //this returns a pointer to the sdl window
   window =  SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,p_w, p_h, SDL_WINDOW_SHOWN);

    //if the nwindow in pointing to nothing and isnt returning a valid memory address show am error message
    if(window ==NULL){
        std::cout << "Window failed to init. ERROR: " << SDL_GetError() <<std:: endl;
    }

    //render it to your window and use the first graphic driver we can use, and if theres a GPU in the users PC then use it!
    //v sync changes the refresh rate of the game to be has many times has the users monitor
    //Difference between | and || :
    //https://stackoverflow.com/questions/34492501/difference-between-and-or-and
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if(texture ==NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() <<std::endl;

    return texture;
}

//hacky vertion of vsync
int RenderWindow::getRefreshRate()
{
    // figure out which screen is our game on since some people use mulitiple monitors
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;

    SDL_GetDisplayMode(displayIndex, 0 , &mode);
    return mode.refresh_rate;

}


void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
}
void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}
void RenderWindow::render(Entity& p_entity){
    // this is a struc that will represent the size of our texture
    //it will store the coordinates of how much of the image to render image(x,y),
    //and the width and height of the image 
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    //this struc will be where we will place our image aka the Desintation
    SDL_Rect dst;
    // the * 4 is forscalling our image
    dst.x = p_entity.getPos().x ;
    dst.y = p_entity.getPos().y ;
    dst.w = p_entity.getCurrentFrame().w ;
    dst.h = p_entity.getCurrentFrame().h ;
   
    // the 2 NULLS are for b/c is the viewable portion of our textre and its tranformations(expanding its size, rotation etc.)
    // if you want to fill the whole screen  set these to null
    //1st parameter:what section of the imgage you wan to render  parameter2: for transformations 
    SDL_RenderCopy(renderer, p_entity.getTex(),&src,&dst);
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}
