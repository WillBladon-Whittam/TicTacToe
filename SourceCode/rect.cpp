#include "rect.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Rect::Rect(int width, int height, int x, int y, int red, int green, int blue, int alpha) : 
_width(width), _height(height), _x(x), _y(y), _red(red), _green(green), _blue(blue), _alpha(alpha)
{
}

Rect::Rect(int width, int height, int x, int y, const string &image_path) : 
_width(width), _height(height), _x(x), _y(y)
{
    auto surface = IMG_Load(image_path.c_str());
    if(!surface) {
        cerr << "Failed to create surface.\n";
    }
    _cross_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    if (!_cross_texture) {
        cerr << "Failed to create texture.\n";
    }
    SDL_FreeSurface(surface);
}

Rect::~Rect() {
    SDL_DestroyTexture(_cross_texture);
}

void Rect::draw() const {
    SDL_Rect rect = { _x, _y, _width, _height };
    if (_cross_texture) {
        SDL_RenderCopy(Window::renderer, _cross_texture, nullptr, &rect);
    }
    else {
        SDL_SetRenderDrawColor(Window::renderer, _red, _green, _blue, _alpha);
        SDL_RenderFillRect(Window::renderer, &rect);
    }
};

void Rect::pollEvents(SDL_Event &event){
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            _x -= 10;
            break;
        }
    }

}