#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>

const int FPS = 60;
const int MILLISECONDS_PER_FRAME = 1000 / FPS;

class Game
{
private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    bool isRunning_;
    int milliSecondsPreviousFrame_;

public:
    Game();
    ~Game();
    void ProcessInput();
    void Update();
    void Setup();
    void Render();
    void Initialize();
    void Run();
    void Destroy();

    uint windowWidth_;
    uint windowHeight_;
};

#endif