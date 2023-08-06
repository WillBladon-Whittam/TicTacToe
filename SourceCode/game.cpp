#include "game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "rect.h"
#include <vector>
#include <chrono>
#include <thread>

void Game::Run(Controller const &controller, Renderer &renderer) {
    bool running = true;

    // Main game loop
    while (running) {
        // Input, Update, Render - the main game loop.
        Update();
        renderer.Render();
        controller.HandleInput(running);
    }
}

void Game::resetGame () {
    for (int i=0; i < 9; i++) {
        grid_toggle[i] = " ";
    }
    placed = false;
}

void Game::checkWon() {
    // 8 winning scenarios - 3 down on each row, 3 across on each row, 3 in a row on each 2 diagonals
    // check downwards
    for (int i=0; i < 9; i+=3) {
        if (grid_toggle[i] == "X" and grid_toggle[i+1] == "X" and grid_toggle[i+2] == "X") {
            cout << "Crosses Wins! \n";
            resetGame();

        } else if (grid_toggle[i] == "O" and grid_toggle[i+1] == "O" and grid_toggle[i+2] == "O") {
            cout << "Noughts Wins! \n";
            resetGame();
        }
    }

    // check horizontal
    for (int i=0; i < 9; i+=1) {
        if (grid_toggle[i] == "X" and grid_toggle[i+3] == "X" and grid_toggle[i+6] == "X") {
            cout << "Crosses Wins! \n";
            resetGame();
        } else if (grid_toggle[i] == "O" and grid_toggle[i+3] == "O" and grid_toggle[i+6] == "O") {
            cout << "Noughts Wins! \n";
            resetGame();
        }
    }
    // check diagonals
    if (grid_toggle[0] == "X" and grid_toggle[4] == "X" and grid_toggle[8] == "X") {
        cout << "Crosses Wins! \n";
        resetGame();
    } else if (grid_toggle[0] == "O" and grid_toggle[4] == "O" and grid_toggle[8] == "O") {
        cout << "Noughts Wins! \n";
        resetGame();
    }
    if (grid_toggle[2] == "X" and grid_toggle[4] == "X" and grid_toggle[6] == "X") {
        cout << "Crosses Wins! \n";
        resetGame();
    } else if (grid_toggle[2] == "O" and grid_toggle[4] == "O" and grid_toggle[6] == "O") {
        cout << "Noughts Wins! \n";
        resetGame();
    }
}

void Game::Update() {
    // Has player placed ?
    // If yes -> Place random noght for now, add a bot to generate a better move.
    //           Check if the game has been won by either the crosses or the noughts
    if (placed == true) {
        // Finds the avalable squares
        vector<int> index_values;
        for (int i=0; i < 9; i++) {
            if (grid_toggle[i] == " ") {
                index_values.push_back(i);
            }
        }

        // Selects a random
        if (index_values.size() == 0) {
            cout << "Game Draw";
            resetGame();
        } else {
            int random = rand() % index_values.size();
            grid_toggle[index_values[random]] = "O";
            placed = false;

            // Check if game has been won.
            checkWon();
        }

    }

}