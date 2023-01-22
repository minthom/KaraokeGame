#include "text_manager.h"
#include <iostream>
#include "game.h"

Text::Text(SDL_Renderer *renderer, const char* font_path, int font_size, const char* message_text, const SDL_Color& color) {
	_text_texture = loadFont(renderer, font_path, font_size, message_text, color);
	SDL_QueryTexture(_text_texture, nullptr, nullptr, &_text_rect.w, &_text_rect.h);
}
void Text::Render(SDL_Renderer *renderer, int x, int y) const {
	_text_rect.x = x; 
	_text_rect.y = y;
	SDL_RenderCopy(renderer, _text_texture, nullptr, &_text_rect);
}

SDL_Texture* Text::loadFont(SDL_Renderer *renderer, const char* font_path, int font_size, const char* message_text, const SDL_Color& color) {
	TTF_Font* font = TTF_OpenFont(font_path, font_size);
	if (!font) {
		std::cerr << "failed to load font" << std::endl;
	}
	SDL_Surface *text_surface = TTF_RenderText_Solid(font, message_text, color);
	if (!text_surface) {
		std::cerr << "failed to create text surface" << std::endl;
	}
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture) {
		std::cerr << "failed to create text texture" << std::endl;
	}
	SDL_FreeSurface(text_surface);
	TTF_CloseFont(font);
	return text_texture;
}
