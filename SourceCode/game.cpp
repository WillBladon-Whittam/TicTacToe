#include "game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "rect.h"

void Game::Run(Controller const &controller, Renderer &renderer) {
    bool running = true;

    // Main game loop
    while (running) {
        // Input, Update, Render - the main game loop.
        renderer.Render();
        Update();
        controller.HandleInput(running);
    }
}

void Game::Update() {
}