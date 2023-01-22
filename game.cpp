#include <iostream>
#include "game.h"
#include "text_manager.h"
#include "SDL_ttf.h"
#include "button.h"

Text* text;
Button* button;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {

}
Game::~Game() {

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized!" << std::endl;
		if (TTF_Init() != -1) {
			std::cout << "TTF initialized!" << std::endl;
		}

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	text = new Text(renderer, "assets/arial.ttf", 30, "Rendering Text", { 255, 0, 0, 255 });
	button = new Button(renderer, 0, 0);
	button->setXY(0, 400);
}
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {

	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}
void Game::update() {
	count++;
}
void Game::render() {
	SDL_RenderClear(renderer); // keep this at the start of the function
	text->Render(renderer, 50, 50);
	button->Render(renderer);
	SDL_RenderPresent(renderer); // keep this at the end of the function
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
