#include "rect.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

// Constructor for Rect
Rect::Rect(int width, int height, int x, int y, int red, int green, int blue, int alpha) : 
_width(width), _height(height), _x(x), _y(y), _red(red), _green(green), _blue(blue), _alpha(alpha)
{
}

// Constructor for an image
Rect::Rect(int width, int height, int x, int y, const string &image_path) : 
_width(width), _height(height), _x(x), _y(y)
{
    auto surface = IMG_Load(image_path.c_str());
    if(!surface) {
        cerr << "Failed to create surface.\n";
    }
    _cross_texture = SDL_CreateTextureFromSurface(Renderer::_sdl_renderer, surface);
    if (!_cross_texture) {
        cerr << "Failed to create texture.\n";
    }
    SDL_FreeSurface(surface);
}

// Destrctor for a Rect / Image
Rect::~Rect() {
    SDL_DestroyTexture(_cross_texture);
}

// Displays the image or the rectangle
void Rect::draw() const {
    SDL_Rect rect = { _x, _y, _width, _height };

    if (_cross_texture) {
        SDL_RenderCopy(Renderer::_sdl_renderer, _cross_texture, nullptr, &rect);
    }
    else {
        SDL_SetRenderDrawColor(Renderer::_sdl_renderer, _red, _green, _blue, _alpha);
        SDL_RenderFillRect(Renderer::_sdl_renderer, &rect);
    }
    // SDL_RenderPresent(Renderer::_sdl_renderer);
};
