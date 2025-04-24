#ifndef GAME_SCORE_H
#define GAME_SCORE_H

#include <string>

int loadHighScore(const std::string& filename);
void saveHighScore(const std::string& filename, int score);

#endif