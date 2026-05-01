#pragma once

#include <SDL3/SDL.h>
#include <cassert>

class DefaultApp {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;

protected:
    Uint64 lastIterationPerfCounter = SDL_GetPerformanceCounter();
    double maxDt = 0.1;
public:

    DefaultApp() {}

    virtual SDL_AppResult Init();

    virtual SDL_AppResult Iterate();

    virtual SDL_AppResult Update(double dt);

    virtual SDL_AppResult Draw(double dt);

    virtual SDL_AppResult Event(SDL_Event *event);

    void DestroyWindowAndRenderer();

    virtual ~DefaultApp();
};

DefaultApp* createApp();