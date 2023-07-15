#pragma once
#include "window.h"

class Rect {
public:
    Rect(int width, int height, int x, int y, int red, int green, int blue, int alpha);
    Rect(int width, int height, int x, int y, const string &image_path);
    ~Rect();

    void draw() const;
    void pollEvents(SDL_Event &event);

private:
    int _width, _height;
    int _x, _y;
    int _red, _green, _blue, _alpha;
    SDL_Texture *_cross_texture = nullptr;
};