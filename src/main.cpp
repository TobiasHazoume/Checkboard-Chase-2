#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\sdl\SDL_image.h>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Player.hpp>
#include <C:\Users\Tobias\Documents\programming_projects\Learning_C++\Checkboard-Chase-2\include\headers\Initialize.hpp>
#include<iostream>
#include <vector>



//Frees media and shuts down SDL
void close();

Initialize initializer;


//create the player 1 object :)
Player player1;


void close()
{
	//Deallocate Textures
	for( int i = 0; i < player1.KEY_PRESS_TEXTURE_TOTAL; ++i )
	{
		SDL_DestroyTexture( player1.gKeyPressTextures[ i ] );
		player1.gKeyPressTextures[ i ] = NULL;
	}

	//Free loaded image
	SDL_DestroyTexture( player1.gTexture );
	player1.gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer( initializer.gRenderer );
	SDL_DestroyWindow( initializer.gWindow );
	initializer.gWindow = NULL;
	initializer.gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int main(int argv, char** args)
{
	//Start up SDL and create window
	if( !initializer.init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !player1.loadPlayer(initializer))
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Set default current Texture
			player1.gTexture = player1.gKeyPressTextures[ player1.KEY_PRESS_TEXTURE_DEFAULT ];

			//While application is running
			while( !quit )
			{
                //process the event queue until it is empty
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					//checj for if a key is up
					else if( e.type == SDL_KEYUP )
					{
						player1.handleEvent(e);
					}
					// add some switch statements
					else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{
							case SDLK_UP:
							player1.gTexture = player1.gKeyPressTextures[ player1.KEY_PRESS_TEXTURE_UP ];
							break;

							case SDLK_DOWN:
							player1.gTexture = player1.gKeyPressTextures[ player1.KEY_PRESS_TEXTURE_DOWN ];
							break;

							case SDLK_LEFT:
							player1.gTexture = player1.gKeyPressTextures[ player1.KEY_PRESS_TEXTURE_LEFT ];
							break;

							case SDLK_RIGHT:
							player1.gTexture = player1.gKeyPressTextures[ player1.KEY_PRESS_TEXTURE_RIGHT ];
							break;

							// [!]
							//change the gfx to face the proper direction based on the last image displayed
							case SDLK_SPACE:
							player1.gTexture = player1.gKeyPressTextures[ player1.KEY_PRESS_TEXTURE_ATTACK ];
							break;

							default:
							player1.gTexture = player1.gKeyPressTextures[ player1.KEY_PRESS_TEXTURE_DEFAULT ];
							break;
						}
						//player 1 event hanlder
						player1.handleEvent( e );	

						// change the players x and y pos every frame once the queues empty
						player1.move();
					}

                }//when its done processing events do the code below

				//Clear screen
				SDL_RenderClear( initializer.gRenderer );

				//Render texture to screen
				SDL_RenderCopy( initializer.gRenderer, player1.gTexture, NULL, player1.pointRenderQuad );

				//it updates the render every frame with the proper render
				SDL_RenderPresent( initializer.gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}