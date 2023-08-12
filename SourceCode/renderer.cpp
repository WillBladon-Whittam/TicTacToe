#include <renderer.h>
#include <text.h>
#include <game.h>
#include <rect.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

// Create the window and renderer
Renderer::Renderer(const int width, int height) :
_window_width(width), _window_height(height)
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
                                    SDL_WINDOWPOS_CENTERED, _window_width, _window_height, 0);
    
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

// Displays the grid
void Renderer::grid() { 

    // Get the top left square
    pair <int, int> top_left;
    top_left.first = x_centre-_grid_width-10;
    top_left.second = y_centre-_grid_height-10;

    int x_displacement = 0;
    int y_displacement = 0;

    // Draw the black background
    Rect rect_bg = { _grid_width*3+20, _grid_height*3+20, x_centre-_grid_width-10, y_centre-_grid_height-10, 0, 0, 0, 255 };
    rect_bg.draw();

    // Loop through each square
    for (int i = 0; i < 9; i++) {
        // Store the x and y positions of each square
        positions[i].first = top_left.first+x_displacement;
        positions[i].second = top_left.second+y_displacement;

        // Draw the square
        Rect rect = { _grid_width, _grid_height, positions[i].first, positions[i].second, 129, 133, 137, 255 };
        rect.draw();

        y_displacement += _grid_height+10;
        if (i == 2 or i == 5) {
            y_displacement = 0;
            x_displacement += _grid_width+10;
        }
    }
}

void Renderer::Render() {

    // Clear screen
    SDL_SetRenderDrawColor(_sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(_sdl_renderer);

    // Create text
    Text text(_sdl_renderer, "assets/Russo_One.ttf", 30, "TicTacToe", {255, 0, 0, 255});
    text.display(315, 20, _sdl_renderer);

    // Create grid
    grid();

    // Draw crosses and noughts
    for (int i=0; i < 9; i++) {
        if (Game::grid_toggle[i] == "X") {
            Rect rect(125, 125, positions[i].first, positions[i].second, "assets/Cross.png");
            rect.draw();
        } else if (Game::grid_toggle[i] == "O") {
            Rect rect(125, 125, positions[i].first, positions[i].second, "assets/Nought.png");
            rect.draw();
        }
    }

    // Update screen
    SDL_RenderPresent(_sdl_renderer);
}
