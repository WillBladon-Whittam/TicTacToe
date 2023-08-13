#pragma once

#include <SDL2/SDL.h>

// Rectangle class - Decalres all attributes used
class Controller {
public:
    void HandleInput(bool &running) const;

    inline static SDL_Event e;

};