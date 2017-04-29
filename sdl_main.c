/* Test elf for sdl on ps2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define S_WIDTH  640
#define S_HEIGHT 480

int main(int argc, char *argv[])
{
	SDL_Surface *window = NULL; // main window
	SDL_Event event;

	SDL_Rect r; // test fill in rect
	r.x = 10;
	r.y = 10;
	r.w = 50;
	r.h = 50;

	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	else{
		printf("Initialized SDL!\n");
	}

	window = SDL_SetVideoMode(S_WIDTH, S_HEIGHT, 32, SDL_HWSURFACE);
	if( !window )
	{
		fprintf(stderr, "Failed to set video mode: %s\n", SDL_GetError());
		return 1;
	}
	else{
		printf("Created window!\n");
	}

	int quit = 0;
	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) quit = 1;
		}
	
		/* clear the window */
		SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 0, 0, 0));

		/* draw the rectangle */
		SDL_FillRect(window, &r, SDL_MapRGB(window->format, 255, 255, 255));

		SDL_Flip(window);

	}

	SDL_FreeSurface(window);
	SDL_Quit();

	return 0;
}
