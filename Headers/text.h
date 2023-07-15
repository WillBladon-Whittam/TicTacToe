#pragma once
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>

using namespace std;

// Text class - Decalres all attributes used
class Text {
public:
    Text(SDL_Renderer *renderer, const string &font_path, int font_size, const string &message_text,const SDL_Colour &colour);
    void display(int x, int y, SDL_Renderer *renderer) const;

    static SDL_Texture *loadFont(SDL_Renderer *renderer, const string &font_path, int font_size, const string &message_text,const SDL_Colour &colour);

private:
    SDL_Texture *_text_texture = nullptr;
    mutable SDL_Rect _text_rect;
};
