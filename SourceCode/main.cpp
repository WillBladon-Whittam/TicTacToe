#include "window.h"
#include "rect.h"
#include "text.h"

using namespace std;

// A pollEvents function that uses the same event, so events will work accross everything. (window, rect ...)
void pollEvents(Window &window, Rect &rect) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        rect.pollEvents(event);
        window.pollEvents(event);
    }
}

// Main Loop
int main(int argc, char **argv) {

    Window window("TicTacToe", 800, 600);
    // Rect rect(window, 120, 120, 100, 100, 200, 0, 200, 255);
    Rect rect(120, 120, 100, 100, "assets/Cross.png");
    Text text(Window::renderer, "assets/Russo_One.ttf", 30, "TicTacToe", {255, 0, 0, 255});

    while (!window.isClosed()) {
        pollEvents(window, rect);
        rect.draw();
        text.display(300, 20, Window::renderer);
        window.clear();
    }

    return 0;
}