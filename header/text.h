#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>

#include <SDL2/SDL_ttf.h>
#include<string>
void renderText(SDL_Renderer* renderer, TTF_Font* font, int score, int hp);
void renderUIText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y);
#endif
