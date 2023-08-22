#pragma once

#include "renderer.h"
#include "controller.h"

class Game {
public:
    void Run(Controller const &controller, Renderer &renderer);
    void Update();
    void checkWon();
    void resetGame();
    float minimax(string position[], int depth, bool maximizingPlayer);
    float bestMove(string position[]);

    inline static string grid_toggle[9] = {"X", " ", "O", " ", " ", " ", " ", " ", " "};

    inline static bool placed = false;

    inline static int cross_wins = 0;
    inline static int nought_win = 0;

private:
    int bestIndexPos;


};