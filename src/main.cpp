#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cmath>
#include "System.h"
#include "GameObject.h"
#include "Constants.h"
#include "ObjectType.h"
#include "menu.h"
#include "text.h"
#include "effects(hitbomb).h"
#include "game_timer.h"
#include "game_score.h"

GameTimer timer(20.0f);
int score=0;
int highScore = 0;
bool gameOver = false;
struct Trail {
    std::vector<SDL_Point> points;

    void addPoint(int x, int y) {
        points.push_back({x, y});
        if (points.size() > TRAIL_LENGTH) {
            points.erase(points.begin());
        }
    }
};

int main() {
    srand(time(0));
    timer.start();
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
    SDL_Texture* backgroundTexture = nullptr;
    SDL_Texture* menuTexture = nullptr;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_AllocateChannels(64);
    Mix_Music* menuMusic = Mix_LoadMUS("asset/menusound.mp3");
    Mix_Music* gameMusic = Mix_LoadMUS("asset/themesong.mp3");
    Mix_Music* gameoverMusic = Mix_LoadMUS("asset/gameoversound.mp3");
    Mix_Chunk* sliceEffect = Mix_LoadWAV("asset/slice.wav");
    Mix_Chunk* hitbombEffect = Mix_LoadWAV("asset/hitbomb.wav");
    
    if (!init(window, renderer, font)) {
        return -1;
    }
    SDL_Surface* backgroundSurface = IMG_Load("E:/btl1/asset/background.png");
    if (backgroundSurface) {
        backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
        SDL_FreeSurface(backgroundSurface);
    }
    SDL_Surface* menuSurface = IMG_Load("E:/btl1/asset/menu.PNG");
    if (menuSurface) {
        menuTexture = SDL_CreateTextureFromSurface(renderer, menuSurface);
        SDL_FreeSurface(menuSurface);
    } else {
        std::cout << "Failed to load menu image: " << IMG_GetError() << std::endl;
    }
    SDL_Texture* bomTexture = IMG_LoadTexture(renderer, "E:/btl1/asset/bom2.png");
    SDL_Texture* fruitsTexture = IMG_LoadTexture(renderer, "E:/btl1/asset/watermelon.png");
    SDL_Texture* fragmentTexture = IMG_LoadTexture(renderer, "E:/btl1/asset/sliced.png");
    bool quit = false;
    bool inMenu = true;
    bool gameOver = false;
    SDL_Event e;
    std::vector<GameObject> objects;
    std::vector<GameObject> newObjects;
    int spawnTimer = 0;
    Trail trail;
  
    int hp = 5;
    bool mouseDown = false;
    int mouseX = 0, mouseY = 0, prevMouseX = 0, prevMouseY = 0;
    bool timeup=false;
    while (!quit) {
        
        if (!gameOver && timer.isTimeUp()) {
            gameOver = true;
            timeup=true;
            timer.stop();

            if (score > highScore)
                saveHighScore("highscore.txt", score);
        }
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                mouseDown = true;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (!inMenu) {
                    prevMouseX = mouseX;
                    prevMouseY = mouseY;
                }
            } else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
                mouseDown = false;
            } else if (gameOver && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_r) {
                timer.start();
                objects.clear();
                newObjects.clear();
                score = 0;
                hp = 5;
                spawnTimer = SPAWN_INTERVAL;
                trail.points.clear();
                mouseDown = false;
                gameOver = false;
                timeup=false;
                objects.push_back(GameObject(rand() % (SCREEN_WIDTH - OBJECT_SIZE), SCREEN_HEIGHT, FRUIT));
                if (rand() % 3 == 0) {
                    objects.push_back(GameObject(rand() % (SCREEN_WIDTH - OBJECT_SIZE), SCREEN_HEIGHT, BOMB));
                }
            }
        }

        SDL_GetMouseState(&mouseX, &mouseY);
        if (inMenu) {
            
            renderMenu(renderer, font, menuTexture, inMenu, quit, mouseX, mouseY, mouseDown, gameMusic, menuMusic);
        } 
        else if (!gameOver) {
            
            if (mouseDown) {
                trail.addPoint(mouseX, mouseY);
                
            }

            if (++spawnTimer >= SPAWN_INTERVAL) {
                spawnTimer = 0;
                objects.push_back(GameObject(rand() % (SCREEN_WIDTH - OBJECT_SIZE), SCREEN_HEIGHT, FRUIT));
                if (rand() % 3 == 0) {
                    objects.push_back(GameObject(rand() % (SCREEN_WIDTH - OBJECT_SIZE), SCREEN_HEIGHT, BOMB));
                }
            }

            newObjects.clear();
            for (auto& obj : objects) {
                if (mouseDown && obj.isSliced(prevMouseX, prevMouseY, mouseX, mouseY) && !obj.sliced) {
                    if (obj.type == BOMB) {
                        if (hitbombEffect) {
                            Mix_PlayChannel(-1, hitbombEffect, 0);
                        }
                        shakeScreen(window, 10, 10);
                        hp--;
                        obj.sliced = true;
                        if (hp <= 0) {
                            gameOver = true;
                            Mix_PlayMusic(gameoverMusic, -1);
                        }
                        continue;
                    } else if (obj.type == FRUIT) {
                        obj.sliced = true;
                        if (sliceEffect) {
                            Mix_PlayChannel(-1, sliceEffect, 0);
                        }
                        score += 10;
                        int radius = OBJECT_SIZE / 4;
                        newObjects.push_back(GameObject(obj.x, obj.y, FRAGMENT, -1));
                        newObjects.push_back(GameObject(obj.x + radius, obj.y, FRAGMENT, 1));
                        continue;
                    }
                }
                obj.update();
                if (!(obj.type == FRAGMENT && obj.y > SCREEN_HEIGHT)) {
                    newObjects.push_back(obj);
                }
            }
            objects = newObjects;

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            if (backgroundTexture) {
                SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
            }

            for (auto& obj : objects) {
                if (obj.type == FRUIT){
                    if (fruitsTexture) {
                        int texWidth, texHeight;
                        SDL_QueryTexture(bomTexture, NULL, NULL, &texWidth, &texHeight);
                        SDL_Rect watermelonRect = {obj.x, obj.y, texWidth/3, texHeight/3};
            
                        if (watermelonRect.x >= 0 && watermelonRect.x < SCREEN_WIDTH &&
                            watermelonRect.y >= 0 && watermelonRect.y < SCREEN_HEIGHT) {
                            SDL_RenderCopy(renderer, fruitsTexture, NULL, &watermelonRect);
                        }
                    }
                    continue;
                } 
                else if (obj.type == BOMB) {
                    if (bomTexture) {
                        int texWidth, texHeight;
                        SDL_QueryTexture(bomTexture, NULL, NULL, &texWidth, &texHeight);
                        SDL_Rect bomRect = {obj.x, obj.y, texWidth/2, texHeight/2};
            
                        if (bomRect.x >= 0 && bomRect.x < SCREEN_WIDTH &&
                            bomRect.y >= 0 && bomRect.y < SCREEN_HEIGHT) {
                            SDL_RenderCopy(renderer, bomTexture, NULL, &bomRect);
                        }
                    }
                    continue;
                }
                else if (obj.type == FRAGMENT) {
                    if (fragmentTexture) {
                        int texWidth, texHeight;
                        SDL_QueryTexture(fragmentTexture, NULL, NULL, &texWidth, &texHeight);
                        SDL_Rect fragmentRect = {obj.x, obj.y,(int) (texWidth/3.5),(int)(texHeight/3.5)};
            
                        if (fragmentRect.x >= 0 && fragmentRect.x < SCREEN_WIDTH &&
                            fragmentRect.y >= 0 && fragmentRect.y < SCREEN_HEIGHT) {
                            SDL_RenderCopy(renderer, fragmentTexture, NULL, &fragmentRect);
                        }
                    }
                }
            }
            renderText(renderer, font, score, hp);
            std::string countdown = "Time Left: " + std::to_string(timer.getTimeLeft()) + "s";
            int textWidth, textHeight;
            TTF_SizeText(font, countdown.c_str(), &textWidth, &textHeight);
            int x = SCREEN_HEIGHT + 180 - textWidth;
            int y = 20;
            renderUIText(renderer, font, countdown, x, y);
        }
    

        if (timeup||gameOver && !inMenu) { 
            if(timeup){
                    std::string msg = "Time's up! Your score is: " + std::to_string(score);
                    renderUIText(renderer, font, msg, 200, 250);
                    std::string msg1 = "Press R to Restart";
                    renderUIText(renderer, font, msg1, 260, 300);
                    
                }
            else
            {
            SDL_Color red = {255, 0, 0, 255};
            SDL_Surface* surface = TTF_RenderText_Solid(font, "Game Over! Press R to Restart", red);
            if (surface) {
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                if (texture) {
                    SDL_Rect textRect = {SCREEN_WIDTH / 2 - surface->w / 2, SCREEN_HEIGHT / 2 - surface->h / 2, surface->w, surface->h};
                    SDL_RenderCopy(renderer, texture, NULL, &textRect);
                    SDL_DestroyTexture(texture);
                }
                SDL_FreeSurface(surface);
            }
        }
    }

        if (!inMenu) {
            SDL_RenderPresent(renderer);
        }
        SDL_Delay(16);

        if (!gameOver && !inMenu) {
            prevMouseX = mouseX;
            prevMouseY = mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
        }
    }
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(menuTexture);
    SDL_DestroyTexture(bomTexture);
    SDL_DestroyTexture(fruitsTexture);
    SDL_DestroyTexture(fragmentTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_FreeMusic(menuMusic);
    Mix_FreeMusic(gameMusic);
    Mix_FreeMusic(gameoverMusic);
    Mix_FreeChunk(sliceEffect);
    Mix_FreeChunk(hitbombEffect);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_CloseFont(font);
    SDL_Quit();
    return 0;
}