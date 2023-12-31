#include "text.h"
#include <iostream>

using namespace std;

// Constructor for text
Text::Text(SDL_Renderer *renderer, const string &font_path, int font_size, const string &message_text,const SDL_Colour &colour) {
    _text_texture = loadFont(renderer, font_path, font_size, message_text, colour);
    SDL_QueryTexture(_text_texture, nullptr, nullptr, &_text_rect.w, &_text_rect.h);
}

// Destrctor for a Text
Text::~Text() {
    SDL_DestroyTexture(_text_texture);
}

// Displays the text
void Text::display(int x, int y, SDL_Renderer *renderer) const {
    _text_rect.x = x;
    _text_rect.y = y;

    SDL_RenderCopy(renderer, _text_texture, nullptr, &_text_rect);
}

// Loads the SDL font, text surface and texture
SDL_Texture *Text::loadFont(SDL_Renderer *renderer, const string &font_path, int font_size, const string &message_text,const SDL_Colour &colour){
    TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
    if (!font) {
        cerr << "Failed to load font.\n";
    }

    auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), colour);
    if (!text_surface) {
        cerr << "Failed to create text surface\n";
    }

    auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (!text_texture) {
                cerr << "Failed to create text texture\n";

    }

    TTF_CloseFont(font);
    SDL_FreeSurface(text_surface);
    return text_texture;
}