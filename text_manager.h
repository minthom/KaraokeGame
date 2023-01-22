#pragma once
#include "SDL_ttf.h"
#include "SDL.h"

class Text {
public:
	Text(SDL_Renderer *renderer,const char* font_path, int font_size, const char* nessage_text, const SDL_Color &color);

	void Render(SDL_Renderer *renderer, int x, int y) const;

	static SDL_Texture* loadFont(SDL_Renderer *renderer, const char* font_path, int font_size, const char* nessage_text, const SDL_Color& color);

private:
	SDL_Texture* _text_texture = nullptr;
	mutable SDL_Rect _text_rect;
};

