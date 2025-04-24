#include "effects(hitbomb).h"
#include <cstdlib> 

void shakeScreen(SDL_Window* window, int intensity, int duration) {
    if (!window) return;

    int originalX, originalY;
    SDL_GetWindowPosition(window, &originalX, &originalY);

    for (int i = 0; i < duration; ++i) {
        int offsetX = (rand() % (intensity * 2 + 1)) - intensity;
        int offsetY = (rand() % (intensity * 2 + 1)) - intensity;
        SDL_SetWindowPosition(window, originalX + offsetX, originalY + offsetY);
        SDL_Delay(20);
    }

    SDL_SetWindowPosition(window, originalX, originalY);
}
