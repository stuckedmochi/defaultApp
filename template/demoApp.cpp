#include "defaultApp.hpp"

class DemoApp: public DefaultApp {
public:
    DemoApp() {}

    SDL_AppResult Init() override {
        SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
        if (!SDL_CreateWindowAndRenderer("Demo App", 800, 600, SDL_WINDOW_TRANSPARENT, &this->window, &this->renderer)) {
            assert(false && SDL_GetError());
            return SDL_APP_FAILURE;
        }

        return SDL_APP_CONTINUE;
    }

    SDL_AppResult Update(double dt) override {
        SDL_Log("%lf", dt);
        return SDL_APP_CONTINUE;
    }

    SDL_AppResult Draw(double dt) override {
        SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(this->renderer);

        float mouse_x, mouse_y, r = 20;
        SDL_GetMouseState(&mouse_x, &mouse_y);
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
};

DefaultApp* createApp() {
    return new DemoApp();
}