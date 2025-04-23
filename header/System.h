#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


bool init(SDL_Window*& window, SDL_Renderer*& renderer, TTF_Font*& font);
void close(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font);
