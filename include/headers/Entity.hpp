#pragma once
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Math.hpp>


//this will be the buidling block for all the draw able thing in our game
//so everything that can be rendered will be a enitiy of some kind
class Entity{
public:

    //i made this default contructor so i dont get errors
    Entity();

    //constructor
    Entity(Vector2f p_pos, SDL_Texture* p_tex);
    
    Vector2f& getPos(){
        return pos;
    }

    SDL_Texture* getTex();

    SDL_Rect getCurrentFrame();
private:
    //will be our vector
    Vector2f pos;
    SDL_Rect currentFrame;    
    //the memory addres of where a texture is on our grafics card
    SDL_Texture* tex;
};