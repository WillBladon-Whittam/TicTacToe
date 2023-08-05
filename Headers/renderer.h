#pragma once
#include <string>
#include <SDL2/SDL.h>

using namespace std;

// Renderer class - Handles all SDL renders
class Renderer {
public:
    Renderer(const int width, int height);
    ~Renderer();

    void grid() const;
    void Render();
    inline static SDL_Renderer *_sdl_renderer;

private:

    SDL_Window *_sdl_window;

    int x_centre = 325;
    int y_centre = 225;

    int _grid_width = 120;
    int _grid_height = 120;

    void grid();

    pair <int, int> positions[9];  

    const int _window_width = 800;
    const int _window_height = 600;

    bool _closed = false;

};