#include "button.h"
#include "SDL.h"
#include "game.h"

Button::Button(SDL_Renderer* renderer, int x, int y) {
	static SDL_Texture* texture = IMG_LoadTexture(renderer, "assets/button_sheet.png");
	buttonTexture = texture;
	srcRect.x = x;
	srcRect.y = y;
	srcRect.w = 360;
	srcRect.h = 120;
	desRect.w = 360;
	desRect.h = 120;
}
void Button::setXY(int x, int y) {
	desRect.x = x;
	desRect.y = y;
}
void Button::Render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, buttonTexture, &srcRect, &desRect);
}