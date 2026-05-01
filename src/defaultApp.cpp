#include "defaultApp.hpp"

SDL_AppResult DefaultApp::Init() {
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    if (!SDL_CreateWindowAndRenderer("default app", 400, 300, 0, &this->window, &this->renderer)) {
        return SDL_APP_FAILURE;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult DefaultApp::Iterate() {
    SDL_AppResult appResult;

    Uint64 currentIterationPerfCounter = SDL_GetPerformanceCounter();
    double dt = static_cast<double>(currentIterationPerfCounter - lastIterationPerfCounter) / SDL_GetPerformanceFrequency();
    lastIterationPerfCounter = currentIterationPerfCounter;

    if ((appResult = Update(dt)) != SDL_APP_CONTINUE) return appResult;
    if ((appResult = Draw(dt)) != SDL_APP_CONTINUE) return appResult;
    if (!SDL_RenderPresent(this->renderer)) {
        assert(false && SDL_GetError());
        return SDL_APP_FAILURE;
    }
    return appResult;
}

SDL_AppResult DefaultApp::Update(double dt) {
    return SDL_APP_CONTINUE;
}

SDL_AppResult DefaultApp::Draw(double dt) {
    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(this->renderer);

    float mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    float r = 100;
    SDL_FRect rect = {
        .x = mouse_x - r / 2.0f,
        .y = mouse_y - r / 2.0f,
        .w = r,
        .h = r,
    };
    SDL_SetRenderDrawColor(this->renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderFillRect(this->renderer, &rect);

    return SDL_APP_CONTINUE;
}

SDL_AppResult DefaultApp::Event(SDL_Event *event) {
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
        break;
    
    default:
        break;
    }

    return SDL_APP_CONTINUE;
}

void DefaultApp::DestroyWindowAndRenderer() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}

DefaultApp::~DefaultApp() {
    DestroyWindowAndRenderer();
}