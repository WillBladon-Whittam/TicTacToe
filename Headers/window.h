#pragma once
#include <string>
#include <SDL2/SDL.h>

using namespace std;

// Window class - Decalres all attributes used
class Window {
public:
    Window(const string &title, int width, int height);
    ~Window();

    void pollEvents();
    void clear() const;

    inline int getWidth() const { return _width; }
    inline int getHeight() const { return _height; }
    inline bool isClosed() const { return _closed; }

    static SDL_Renderer *renderer;
    inline static SDL_Event event;

private:
    string _title;

    int _width = 800;
    int _height = 600;

    bool init();
    bool _closed = false;

    SDL_Window *_window = nullptr;

};