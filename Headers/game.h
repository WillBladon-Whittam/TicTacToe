#pragma once

#include "renderer.h"
#include "controller.h"

class Game {
public:
    void Run(Controller const &controller, Renderer &renderer);
    void Update();
    void checkWon();
    void resetGame();

    inline static string grid_toggle[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

    inline static bool placed = false;

};