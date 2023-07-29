#pragma once
#include <string>
#include <SDL2/SDL.h>

using namespace std;

// Renderer class - Handles all SDL renders
class Renderer {
public:
    Renderer(const int width, int height);
    ~Renderer();

    void Render();
    inline static SDL_Renderer *_sdl_renderer;

private:

    SDL_Window *_sdl_window;

    const int _width = 800;
    const int _height = 600;

    bool _closed = false;

};