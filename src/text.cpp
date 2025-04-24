#include "text.h"
#include <string>

void renderText(SDL_Renderer* renderer, TTF_Font* font, int score, int hp) {
    SDL_Color white = {255, 255, 255, 255};
    std::string scoreText = "Score: " + std::to_string(score);
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), white);
    if (scoreSurface) {
        SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
        if (scoreTexture) {
            SDL_Rect scoreRect = {10, 10, scoreSurface->w, scoreSurface->h};
            SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
            SDL_DestroyTexture(scoreTexture);
        }
        SDL_FreeSurface(scoreSurface);
    }

    std::string hpText = "HP: " + std::to_string(hp);
    SDL_Surface* hpSurface = TTF_RenderText_Solid(font, hpText.c_str(), white);
    if (hpSurface) {
        SDL_Texture* hpTexture = SDL_CreateTextureFromSurface(renderer, hpSurface);
        if (hpTexture) {
            SDL_Rect hpRect = {10, 40, hpSurface->w, hpSurface->h};
            SDL_RenderCopy(renderer, hpTexture, NULL, &hpRect);
            SDL_DestroyTexture(hpTexture);
        }
        SDL_FreeSurface(hpSurface);
    }
}
void renderUIText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y) {
    SDL_Color color = {255, 255, 255}; // màu trắng
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect dest = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
