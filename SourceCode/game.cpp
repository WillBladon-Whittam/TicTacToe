#include "game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "rect.h"
#include <vector>
#include <thread>
#include <unistd.h>
#include <chrono> 
#include <thread>

void Game::Run(Controller const &controller, Renderer &renderer) {
    bool running = true;

    // Main game loop
    while (running) {
        // Input, Update, Render - the main game loop.
        thread thread_update(Game::Update, this);
        thread thread_render(Renderer::Render, &renderer);
        controller.HandleInput(running);
        thread_update.join();
        thread_render.join();

        SDL_Delay(25);
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
            cross_wins+=1;
            resetGame();

        } else if (grid_toggle[i] == "O" and grid_toggle[i+1] == "O" and grid_toggle[i+2] == "O") {
            cout << "Noughts Wins! \n";
            nought_win+=1;
            resetGame();
        }
    }

    // check horizontal
    for (int i=0; i < 9; i+=1) {
        if (grid_toggle[i] == "X" and grid_toggle[i+3] == "X" and grid_toggle[i+6] == "X") {
            cout << "Crosses Wins! \n";
            cross_wins+=1;
            resetGame();
        } else if (grid_toggle[i] == "O" and grid_toggle[i+3] == "O" and grid_toggle[i+6] == "O") {
            cout << "Noughts Wins! \n";
            nought_win+=1;
            resetGame();
        }
    }
    // check diagonals
    if (grid_toggle[0] == "X" and grid_toggle[4] == "X" and grid_toggle[8] == "X") {
        cout << "Crosses Wins! \n";
        cross_wins+=1;
        resetGame();
    } else if (grid_toggle[0] == "O" and grid_toggle[4] == "O" and grid_toggle[8] == "O") {
        cout << "Noughts Wins! \n";
        nought_win+=1;
        resetGame();
    }
    if (grid_toggle[2] == "X" and grid_toggle[4] == "X" and grid_toggle[6] == "X") {
        cout << "Crosses Wins! \n";
        cross_wins+=1;
        resetGame();
    } else if (grid_toggle[2] == "O" and grid_toggle[4] == "O" and grid_toggle[6] == "O") {
        cout << "Noughts Wins! \n";
        nought_win+=1;
        resetGame();
    }
}

float Game::bestMove(string position[]) {
    // 8 winning scenarios - 3 down on each row, 3 across on each row, 3 in a row on each 2 diagonals
    // check downwards
    for (int i=0; i < 9; i+=3) {
        if (position[i] == "X" and position[i+1] == "X" and position[i+2] == "X") {
            return 1;

        } else if (position[i] == "O" and position[i+1] == "O" and position[i+2] == "O") {
            return -1;
        }
    }

    // check horizontal
    for (int i=0; i < 9; i+=1) {
        if (position[i] == "X" and position[i+3] == "X" and position[i+6] == "X") {
            return 1;
        } else if (position[i] == "O" and position[i+3] == "O" and position[i+6] == "O") {
            return -1;
        }
    }
    // check diagonals
    if (position[0] == "X" and position[4] == "X" and position[8] == "X") {
        return 1;
    } else if (position[0] == "O" and position[4] == "O" and position[8] == "O") {
        return -1;
    }
    if (position[2] == "X" and position[4] == "X" and position[6] == "X") {
        return 1;
    } else if (position[2] == "O" and position[4] == "O" and position[6] == "O") {
        return -1;
    }
    return 0;
}

float Game::minimax(string position[], int depth, bool maximizingPlayer) {
    // cout << "depth = " << depth << "\n";
    // cout << "bestMove = " << bestMove(position) << "\n";
    // cout << "bestIndex = " << bestIndexPos << "\n";
    // cout << position[0] << " " << position[3] << " " << position[6] << "\n";
    // cout << position[1] << " " << position[4] << " " << position[7] << "\n";
    // cout << position[2] << " " << position[5] << " " << position[8] << "\n";
    // cout << "\n";
    if (depth == 0 or bestMove(position) != 0) {
        float eval = bestMove(position);
        return eval;
    }

    if (maximizingPlayer) {
        float maxEval = -1000;
        for (int i=0; i < 9; i++) {
            if (position[i] == " ") {
                position[i] = "X";
                float eval = minimax(position, depth-1, false);
                position[i] = " ";
                if (eval > maxEval) {
                    // cout << "maxEval before = " << maxEval << "\n";
                    maxEval = eval;
                    // cout << "maxEval after = " << maxEval << "\n";
                }
            }
        }
        return maxEval;
    } else {
        float minEval = 1000; 
        for (int i=0; i < 9; i++) {
            if (position[i] == " ") {
                position[i] = "O";
                int eval = minimax(position, depth-1, true);
                position[i] = " ";
                if (eval < minEval) {
                    // cout << "minEval before = " << minEval << "\n";
                    minEval = eval;
                    // cout << "minEval after = " << minEval << "\n";
                    bestIndexPos = i;
                }
            }
        }
        return minEval;
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
        this_thread::sleep_for(chrono::milliseconds(1000));

        if (index_values.size() == 0) {
            cout << "Game Draw";
            resetGame();
        } else {
            minimax(grid_toggle, 2, false);
            cout << "FINAL INDEX = " << bestIndexPos;
            grid_toggle[bestIndexPos] = "O";
            placed = false;

            // Check if game has been won.
            checkWon();
        }

    }

}