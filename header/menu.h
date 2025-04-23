#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Constants.h"



void renderMenu(SDL_Renderer* renderer, TTF_Font* font, SDL_Texture* menuTexture,
                bool& inMenu, bool& quit, int mouseX, int mouseY, bool mouseDown,
                Mix_Music* gameMusic, Mix_Music* menuMusic);

#endif
