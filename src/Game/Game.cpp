#include "Game.h"
#include "../Logger/Logger.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>

Game::Game()
{
    isRunning_ = false;
    Logger::Log("Game Constructor called");
};

Game::~Game()
{
    Logger::Log("Game Destructor Called");
};

void Game::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Logger::Err("Error initializing SDL");
        return;
    }

    // I want to render 800 * 600 but later we can change
    // display mode to full screen (real fullscreen)
    windowWidth_ = 800;
    windowHeight_ = 600;
    // Create a window
    window_ = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowWidth_,
        windowHeight_,
        SDL_WINDOW_RESIZABLE);
    if (!window_)
    {
        Logger::Err("Window failed to initialize");
        return;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer_)
    {
        Logger::Err("Renderer failed to initialize");
        return;
    }
    SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN);
    isRunning_ = true;
};

void Game::Run()
{
    Setup();
    while (isRunning_)
    {
        ProcessInput();
        Update();
        Render();
    }
};

void Game::ProcessInput()
{
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent))
    {
        switch (sdlEvent.type)
        {
        case SDL_QUIT:
            isRunning_ = false;
            break;
        case SDL_KEYDOWN:
            if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning_ = false;
            }
            break;
        }
    };
};

glm::vec2 playerPosition;
glm::vec2 playerVelocity;

void Game::Setup()
{
    playerPosition = glm::vec2(10.0, 20.0);
    playerVelocity = glm::vec2(60.0, 5.0);
}

void Game::Update()
{
    int timeToWait = MILLISECONDS_PER_FRAME - (SDL_GetTicks() - milliSecondsPreviousFrame_);
    if (timeToWait > 0 && timeToWait <= MILLISECONDS_PER_FRAME)
        SDL_Delay(timeToWait);

    // difference in ticks since the last frame in seconds
    double deltaTime = (SDL_GetTicks() - milliSecondsPreviousFrame_) / 1000.0f;
    // store the current game time
    milliSecondsPreviousFrame_ = SDL_GetTicks();

    playerPosition.x += playerVelocity.x * deltaTime;
    playerPosition.y += playerVelocity.y * deltaTime;
};

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer_, 21, 21, 21, 255);
    SDL_RenderClear(renderer_);
    // Render all game objects here:

    // Draw png texture
    SDL_Surface *surface = IMG_Load("./assets/images/tank-tiger-right.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer_, surface);
    SDL_FreeSurface(surface);
    // destination rectangle at which we will place our source texture
    SDL_Rect destRect = {static_cast<int>(playerPosition.x), static_cast<int>(playerPosition.y), 32, 32};
    SDL_RenderCopy(renderer_, texture, NULL, &destRect);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(renderer_); // swaps the back-buffer and front-buffer
};

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
};
