#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\RenderWindow.hpp"
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Entity.hpp"
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Utils.hpp"
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Player.hpp"
#include "C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\LTexture.hpp"

#include<iostream>
#include <vector>

int main(int argc, char* argv[]){



    //will check if SDL is giving us an error
    //and display the error
    if(SDL_Init(SDL_INIT_VIDEO) > 0){
        std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " 
        << SDL_GetError() << std::endl;
    }

    //check if sdl is unable to get a set of pngs
    //and display the error
    if(!(IMG_Init(IMG_INIT_PNG |IMG_INIT_JPG))){
        std::cout <<"IMG_init has FAILED. Error: " 
        << SDL_GetError() << std::endl;
    }

    //create our render window
    RenderWindow window("GAME v1.0", 1080,700);
    std::cout << window.getRefreshRate() << std::endl;

    //load a texture 
    
    SDL_Texture* link = window.loadTexture("C:/Users/Tobias/Documents/programming_projects/Learning_C++/Checkboard-Chase-2/res/gfx/green_link.png");

    //this creates an dynamic array known as a vector in c++ of enities which is  but doesnt have it shown up on the screen
    //theres was to be an eaier way ;-;
    
 

    //player one entity
    //reminder: remove the vector2f parameter later once rendernig works. its repetitive
    Entity entityPlayer1(Vector2f(600,77), link);
    //make a player object called player one
    Player player1(entityPlayer1);

    //Scene sprites
    SDL_Rect gLinkClips[ player1.PLAYER_ANIMATIONS_TOTAL ];
    LTexture gLinkSkin;
    
    //https://youtu.be/pjLpipQRMIw?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS&t=1340
    bool gamerunning = true;
     
    //create an event
    SDL_Event event;

    //the ammount of time we advance the simulation forward by each frame
    //we dont want to change this number once the program starts so its const
    const float timeStep =0.01f;
    //basicly limits the amount of times the program updates per sec
    //https://youtu.be/RaB60Ujle7o?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS&t=434
    float accumulator = 0.0f;
    
    float currentTime = utils::hireTimeInSeconds();

    //Event handler
	SDL_Event e;

    //while the game check if the event we are poling is
    //SDL_QUIT and if it is than close the gmae
    
    while(gamerunning){
        
        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        //add to accumulator
        accumulator += frameTime;

        while(accumulator >= timeStep)
        {
            //get our controls and events
            while(SDL_PollEvent(&event)){
                if (event.type ==SDL_QUIT)
                {
                    gamerunning =false;
                }

                //this Clears the screen but i probably dont need this
				//SDL_SetRenderDrawColor( gLinkSkin.gRenderer, 0x90, 0xa4, 0xae, 0xFF );
				//SDL_RenderClear( gLinkSkin.gRenderer );

                //Render Link
                //change to default!!
				player1.gLinkSkin.render( 600,77, &gLinkClips[ player1.PLAYER_UP ] );
                //hopefully this will take in inputs
                player1.handleEvent(e);
                //Handle input for the dot
			    player1.move();
				//Update screen
				SDL_RenderPresent( gLinkSkin.gRenderer );
  
            }
            //if the  accumulator reaches it threshhold
            //subtract the timestep since that time steps been prosessed
            accumulator -= timeStep;

        }

        //is the time left in the accumulator as a percentage
        const float  alpha =accumulator / timeStep;

        window.clear();
        window.display();

        int frameTicks = SDL_GetTicks() - startTicks;
        //add a minimum amount of time for a frame to take
        //basiscly is the games running to fast then delay the game
        if(frameTicks < 1000 / window.getRefreshRate()){
            SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
        }

    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}