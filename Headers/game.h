#pragma once

#include "renderer.h"
#include "controller.h"

class Game {
public:
    void Run(Controller const &controller, Renderer &renderer);
    void Update();

    inline static string grid_toggle[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

};