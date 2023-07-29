#include "renderer.h"
#include "controller.h"
#include "game.h"
#include "text.h"
#include <unistd.h>
#include <iostream>
#include <typeinfo>

using namespace std;

int main(int argc, char **argv) {

    Renderer renderer(800, 600);
    Controller controller;
    Game game;
    game.Run(controller, renderer);

    // Window window("TicTacToe", 800, 600);
    // Rect rect(120, 120, 100, 100, rand()%255, rand()%255, rand()%255, 255);
    // // Rect rect(120, 120, 100, 300, "assets/Cross.png");
    // Text text(Window::renderer, "assets/Russo_One.ttf", 30, "TicTacToe", {255, 0, 0, 255});
    // while (!window.isClosed()) {
    //     // renderer
    //     // controller
    //     // game
    //     window.pollEvents();
    //     rect.grid();
    //     text.display(315, 20, Window::renderer);
    //     window.clear();
    // }

    return 0;
}