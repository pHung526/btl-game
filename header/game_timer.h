#ifndef GAME_TIMER_H
#define GAME_TIMER_H

class GameTimer {
public:
    GameTimer(float maxTimeSeconds = 120.0f);
    void start();
    void stop();
    float getElapsedSeconds() const;
    int getTimeLeft() const;
    bool isTimeUp() const;

private:
    unsigned int startTime;
    bool running;
    float maxTime;
};

#endif