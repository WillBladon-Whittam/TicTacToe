#include "window.h"
#include "rect.h"
#include "text.h"
#include <unistd.h>
#include <iostream>
#include <typeinfo>

using namespace std;

// Create the grid 
void Grid(Window &window, Rect* grid_arr[]) {
    int x_centre = (window.getWidth() / 2) - 60;
    int y_centre = (window.getHeight() / 2) - 60;

    Rect rect1(120, 120, 100, 100, "assets/Cross.png");
    Rect rect2(120, 120, 100, 100, "assets/Cross.png");

    grid_arr[0] = &rect1;
    grid_arr[1] = &rect2;
}

// Main Loop
int main(int argc, char **argv) {

    Window window("TicTacToe", 800, 600);
    Rect rect(120, 120, 100, 100, rand()%255, rand()%255, rand()%255, 255);
    // Rect rect(120, 120, 100, 300, "assets/Cross.png");
    Text text(Window::renderer, "assets/Russo_One.ttf", 30, "TicTacToe", {255, 0, 0, 255});
    while (!window.isClosed()) {
        window.pollEvents();
        rect.grid();
        text.display(315, 20, Window::renderer);
        window.clear();
    }

    return 0;
}