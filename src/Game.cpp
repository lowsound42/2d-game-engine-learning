#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>

Game::Game()
{
    std::cout << "Game Constructor Called" << "\n";
};

Game::~Game()
{
    std::cout << "Game Destructor Called" << "\n";
};

void Game::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL" << "\n";
        return;
    }
    // Create a window
    window_ = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_RESIZABLE);
    if (!window_)
    {
        std::cerr << "Window failed to initialize" << "\n";
        return;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
    if (!renderer_)
    {
        std::cerr << "Renderer failed to initialize" << "\n";
        return;
    }
    isRunning_ = true;
};

void Game::Run()
{
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

void Game::Update() {
    // TODO: Later
};

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
    SDL_RenderClear(renderer_);
    // Render all game objects here;
    SDL_RenderPresent(renderer_);
};

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
};
