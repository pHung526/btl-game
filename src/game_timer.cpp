#include "game_timer.h"
#include <SDL2/SDL.h>

GameTimer::GameTimer(float maxTimeSeconds)
    : startTime(0), running(false), maxTime(maxTimeSeconds) {}

void GameTimer::start() {
    startTime = SDL_GetTicks();
    running = true;
}

void GameTimer::stop() {
    running = false;
}

float GameTimer::getElapsedSeconds() const {
    if (!running) return 0.0f;
    return (SDL_GetTicks() - startTime) / 1000.0f;
}

int GameTimer::getTimeLeft() const {
    int left = (int)(maxTime - getElapsedSeconds());
    return (left > 0) ? left : 0;
}

bool GameTimer::isTimeUp() const {
    return getElapsedSeconds() >= maxTime;
}