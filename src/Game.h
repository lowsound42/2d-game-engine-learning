#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game
{
private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    bool isRunning_;

public:
    Game();
    ~Game();
    void ProcessInput();
    void Update();
    void Render();
    void Initialize();
    void Run();
    void Destroy();
};

#endif