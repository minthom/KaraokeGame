#pragma once
#include "SDL.h"

class Button {
public:

	Button() {};
	~Button() {};
	// pass in the x and y of the top left corner of sprite
	Button(SDL_Renderer* renderer, int x, int y);

	// set the dest rect
	void setXY(int x, int y);

	void Render(SDL_Renderer* renderer);
private:
	SDL_Texture* buttonTexture;
	SDL_Rect srcRect, desRect;
	bool selected;
};