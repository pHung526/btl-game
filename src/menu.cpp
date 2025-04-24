#include "menu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

void renderMenu(SDL_Renderer* renderer, TTF_Font* font, SDL_Texture* menuTexture, bool& inMenu, bool& quit, int mouseX, int mouseY, bool mouseDown, Mix_Music* gameMusic, Mix_Music* menuMusic) {
    static bool musicPlaying = false;

    if (!musicPlaying) {
        Mix_PlayMusic(menuMusic, -1);
        musicPlaying = true;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (menuTexture) {
        SDL_RenderCopy(renderer, menuTexture, NULL, NULL);
    }

    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface* startSurface = TTF_RenderText_Solid(font, "Start", white);
    if (startSurface) {
        int startW = startSurface->w;
        int startH = startSurface->h;
        SDL_Rect startRect = {SCREEN_WIDTH / 2 - startW / 2, SCREEN_HEIGHT / 2 - 50, startW, startH};
        bool startHovered = (mouseX >= startRect.x && mouseX <= startRect.x + startRect.w &&
                             mouseY >= startRect.y && mouseY <= startRect.y + startRect.h);
        if (startHovered) {
            startRect.w = static_cast<int>(startW * 0.9);
            startRect.h = static_cast<int>(startH * 0.9);
            startRect.x += (startW - startRect.w) / 2;
            startRect.y += (startH - startRect.h) / 2;
            if (mouseDown) {
                inMenu = false;
                Mix_PlayMusic(gameMusic, -1);
                musicPlaying = false;
            }
        }
        SDL_Texture* startTexture = SDL_CreateTextureFromSurface(renderer, startSurface);
        if (startTexture) {
            SDL_RenderCopy(renderer, startTexture, NULL, &startRect);
            SDL_DestroyTexture(startTexture);
        }
        SDL_FreeSurface(startSurface);
    }

    SDL_Surface* exitSurface = TTF_RenderText_Solid(font, "Exit", white);
    if (exitSurface) {
        int exitW = exitSurface->w;
        int exitH = exitSurface->h;
        SDL_Rect exitRect = {SCREEN_WIDTH / 2 - exitW / 2, SCREEN_HEIGHT / 2 + 50, exitW, exitH};
        bool exitHovered = (mouseX >= exitRect.x && mouseX <= exitRect.x + exitRect.w &&
                            mouseY >= exitRect.y && mouseY <= exitRect.y + exitRect.h);
        if (exitHovered) {
            exitRect.w = static_cast<int>(exitW * 0.9);
            exitRect.h = static_cast<int>(exitH * 0.9);
            exitRect.x += (exitW - exitRect.w) / 2;
            exitRect.y += (exitH - exitRect.h) / 2;
            if (mouseDown) {
                quit = true;
            }
        }
        SDL_Texture* exitTexture = SDL_CreateTextureFromSurface(renderer, exitSurface);
        if (exitTexture) {
            SDL_RenderCopy(renderer, exitTexture, NULL, &exitRect);
            SDL_DestroyTexture(exitTexture);
        }
        SDL_FreeSurface(exitSurface);
    }

    SDL_RenderPresent(renderer);
}
