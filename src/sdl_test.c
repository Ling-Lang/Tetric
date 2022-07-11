#include <SDL.h>
#include <stdio.h>
int main(/*int argc, char *argv[]*/)
{
	int i = 0;
	SDL_Window *window = NULL;
	SDL_Surface *surface;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *texture;
	int count = 4;
	int fallingspeed = 90;
	SDL_Rect rect[count];
	rect[0].x = 30;
	rect[0].y = 0;
	rect[0].h = 10;
	rect[0].w = 10;

	rect[1].x = 40;
	rect[1].y = 10;
	rect[1].h = 10;
	rect[1].w = 10;
	
	rect[2].x = 40;
	rect[2].y = 0;
	rect[2].h = 10;
	rect[2].w = 10;

	rect[3].x = 50;
	rect[3].y = 0;
	rect[3].h = 10;
	rect[3].w = 10;

	SDL_Init(SDL_INIT_VIDEO);
		/*SDL_CreateWindowAndRenderer(
		740,
		480,
		SDL_WINDOW_SHOWN,
		&window,
		&renderer
		);
		*/
	 	window = SDL_CreateWindow(
		"Tetric",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		810,
		960,
		SDL_WINDOW_SHOWN
		);
		renderer = SDL_CreateRenderer(
		window,
		1,
		SDL_RENDERER_ACCELERATED
		);
		
		// Set Window background to #282a2e1
		SDL_SetRenderDrawColor(renderer, 0x28, 0x2a, 0x2e, 0x1);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		
		/*
		 *	TODO Make those lines into SDL_RenderDrawRects();
		 *	After this Fill to make darker 
		 *	Maybe looks better.
		 *
		 */
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x1);
		SDL_RenderDrawLine(renderer, 135, 0, 135, 960);
		SDL_RenderDrawLine(renderer, 675, 0, 675, 960);
		SDL_RenderPresent(renderer);

		SDL_SetRenderDrawColor(renderer, 0xfe, 0xfe, 0x58, 0x1);
		SDL_RenderDrawRects(renderer, &rect[0], count);
		SDL_RenderPresent(renderer);
		
		SDL_SetRenderDrawColor(renderer, 0xfe, 0xff, 0x03, 0x1);
		SDL_RenderFillRects(renderer, &rect[0], count);
		SDL_RenderPresent(renderer);

		// Update stuff 
		SDL_UpdateWindowSurface(window);
		SDL_Delay(2000);
	/*	
		SDL_SetRenderDrawColor(renderer, 0xfe, 0xff, 0x58, 0x1);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	*/
		while(i < 45)
		{
			
		rect[0].y = rect[0].y +10;
		rect[1].y = rect[1].y +10;
		rect[2].y = rect[2].y +10;
		rect[3].y = rect[3].y +10;
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0x1);
		SDL_RenderDrawRects(renderer, &rect[0], count);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);

		SDL_SetRenderDrawColor(renderer, 0x28, 0x2a, 0x2e, 0x1);
		SDL_RenderDrawRects(renderer, &rect[0], count);
		SDL_RenderPresent(renderer);
		i++;
		/*
		/SDL_SetRenderDrawColor(renderer, 0xfe, 0xfe, 0x58, 0x1);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		*/

		SDL_Delay(fallingspeed);
		//printf("%i \n", i);
		}
		SDL_UpdateWindowSurface(window);
		//printf("IT WORKS \n");
		SDL_Delay(200); 
		
	//SDL_Delay(5000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
