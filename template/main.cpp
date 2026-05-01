#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "defaultApp.hpp"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    SDL_AppResult appResult;
    DefaultApp *app = createApp();
    *appstate = app;
    return app->Init();
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    DefaultApp *app = static_cast<DefaultApp*>(appstate);
    return app->Iterate();
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event* event) {
    DefaultApp *app = static_cast<DefaultApp*>(appstate);
    return app->Event(event);
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    DefaultApp *app = static_cast<DefaultApp*>(appstate);
    delete app;
}