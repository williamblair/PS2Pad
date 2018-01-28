/* demo PS2Pad using SDL */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../PS2Pad.hpp" // for our pad

SDL_Surface *window = NULL; // app window
SDL_Event    event;

SDL_Rect r = {10, 10, 50, 50};
//r.x = 10;
//r.y = 10;
//r.w = 50;
//r.h = 50;

const double SCALER = 0.1;

bool initSDL(void)
{

	/* initialize SDL with video - can also include audio, joystick */
	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		return false;
	}

	/* create a surface that will serve as the application window */
	window = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	if(!window)
	{
		printf("Failed to create window: %s\n", SDL_GetError());
		SDL_Quit();
		return false;
	}


	return true;
}

void pollEvents(PS2Pad *pad)
{

	while(SDL_PollEvent(&event))
	{
		/* normally would exit the application but not in this case */
		if(event.type == SDL_QUIT){
			printf("Quit event!\n");
		}

	}
		/* move the rectangle based on the joystick */
		pad->read();
		printf("Pad X: %d\n", pad->getLeftJoyX());
		printf("Pad Y: %d\n", pad->getLeftJoyY());
		if( pad->getLeftJoyX()  > 200 )
			//r.x += (Sint16)(pad->getLeftJoyX() * SCALER);
			r.x += 1; 

		else if( pad->getLeftJoyX()  < 20 )
			//r.x -= (Sint16)(pad->getLeftJoyX() * SCALER);
			r.x -= 1; 

		if( pad->getLeftJoyY() > 200 )
			//r.y += (Sint16)(pad->getLeftJoyY() * SCALER);
			r.y += 1; 

		else if( pad->getLeftJoyY() < 20 )
			//r.y -= (Sint16)(pad->getLeftJoyY() * SCALER);
			r.y -= 1; 

		/* prevent from going offscreen */
		if( r.x <= 0 ) r.x = 0;
		if( r.x+r.w >= 640) r.x = 640 - r.w - 1;
		if( r.y <= 0 ) r.y = 0;
		if( r.y+r.h >= 480 ) r.y = 480 - r.h - 1; 

	return;
}

void updateScreen(void)
{
	/* clears the screen 
	 * in this case 0,50,50 would be
	 * dark aqua */
	SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 0, 50, 50));

	/* fill in a rectangle on the window with size above
	 * and color given by SDL_MapRGB */
	SDL_FillRect(window, &r, SDL_MapRGB(window->format, 255, 0, 0));

	/* update the screen */
	SDL_Flip(window);

	return;
}

int main(int argc, char *argv[])
{
	/* see if i need this... */
	SifInitRpc(0);

	PS2Pad pad1(0,0);

	/* init and create window */
	if( !initSDL() ){
		SleepThread();
	}

	while(1)
	{
		pollEvents(&pad1);

		updateScreen();
	}

	SDL_FreeSurface(window);
	SDL_Quit();
	return 0;
}

