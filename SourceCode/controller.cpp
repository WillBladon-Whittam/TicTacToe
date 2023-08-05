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
            int x_min = 200;
            int x_max = 315;
            int y_min = 100;
            int y_max = 215;
            int counter = -1;
            SDL_GetMouseState(&xMouse, &yMouse);
            for (int i=0; i < 360; i+=130) {
              for (int j=0; j < 360; j+=130) {
                counter+=1;
                if ((x_min+i < xMouse && xMouse < x_max+i) && (y_min+j < yMouse && yMouse < y_max+j)) {
                  cout << counter << "\n";
                  if (Game::grid_toggle[counter] == " ") {
                    Game::grid_toggle[counter] = "X";
                  } else if (Game::grid_toggle[counter] == "X") {
                    Game::grid_toggle[counter] = " ";
                  }
              }
            }
           } 
          break;
      }
    } 
  }
}