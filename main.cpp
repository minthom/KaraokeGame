#include "game.h"
#include "SDL.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	//unsigned int 32 bit
	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Casi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running()) { //game is runnning

		frameStart = SDL_GetTicks(); //sets framestart to the num of milliseconds since initialization

		game->handleEvents();
		game->update();
		game->render();

		/*
		handle any user input
		update all object eg. positions etc.
		render changes to the display
		*/

		//milliseconds that it takes to handle our events, update, render
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	return 0;

}