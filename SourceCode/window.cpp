#include <window.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

using namespace std;

SDL_Renderer *Window::renderer = nullptr;

// Constrctor for window class
Window::Window(const string &title, int width, int height) :
_title(title), _width(width), _height(height)
{
    _closed = !init();
}


// Destructor for the windows class
Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

// Initalises SDL window, images and text
bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "Failed to inititalse SDL.\n";
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        cerr << "Failed to inititalse SDL image.\n";
    }

     if (TTF_Init() == -1) {
        cerr << "Failed to inititalse SDL ttf.\n";
    }

    _window = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _width, _height,
        0
    );

    if (_window == nullptr) {
        cerr << "Failed to create window.\n";
        return false;
    }

    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) {
        cerr << "Failed to create render.\n";
        return false;
    }

    return true;
        
};

// Events for the window (ESC to close)
void Window::pollEvents() {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                _closed = true;
                break;

            default:
                break;
        }
    }
}

// Sets up the window
void Window::clear() const {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 129, 133, 137, 255);
    SDL_RenderClear(renderer);
}