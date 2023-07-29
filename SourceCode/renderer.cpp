#include <renderer.h>
#include <text.h>
#include <game.h>
#include <rect.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

using namespace std;

// Create the window and renderer
Renderer::Renderer(const int width, int height) :
_width(width), _height(height)
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Initialse SDL_IMG
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        cerr << "Failed to inititalse SDL image.\n";
    }

    // Initialse SDL_TTF
    if (TTF_Init() == -1) {
        cerr << "Failed to inititalse SDL ttf.\n";
    }
  
    // Create Window
    _sdl_window  = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_CENTERED, 
                                    SDL_WINDOWPOS_CENTERED, _width, _height, 0);
    
    if (nullptr == _sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    _sdl_renderer = SDL_CreateRenderer(_sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == _sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

// Destructor for the renderer class
Renderer::~Renderer()
{
    SDL_DestroyRenderer(_sdl_renderer);
    SDL_DestroyWindow(_sdl_window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Renderer::Render() {
    // Clear screen
    SDL_SetRenderDrawColor(_sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(_sdl_renderer);

    // Create text
    Text text(_sdl_renderer, "assets/Russo_One.ttf", 30, "TicTacToe", {255, 0, 0, 255});
    text.display(315, 20, _sdl_renderer);

    // Create grid
    Rect rect(120, 120, 100, 100, 30, 30, 30, 255);
    rect.grid();

    // Draw crosses and noughts
    for (const string &position : Game::grid_toggle) {
        if (position == "X") {
            Rect rect(120, 120, 195, 95, "assets/Cross.png");
            rect.draw();
        }
    }

    // Update screen
    SDL_RenderPresent(_sdl_renderer);
}
