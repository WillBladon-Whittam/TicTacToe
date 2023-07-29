#include "controller.h"
#include "renderer.h"
#include "game.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

// Handle inputs
void Controller::HandleInput(bool &running) const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_MOUSEBUTTONUP:
        if (e.button.button == SDL_BUTTON_LEFT) {
            int xMouse, yMouse;
            SDL_GetMouseState(&xMouse, &yMouse);
            if ((200 < xMouse && xMouse < 315) && (100 < yMouse && yMouse < 215)) {
              if (Game::grid_toggle[1] == " ") {
                Game::grid_toggle[1] = "X";
              } else if (Game::grid_toggle[1] == "X") {
                Game::grid_toggle[1] = " ";
              } 
           break;
        }
      }
    } 
  }
}