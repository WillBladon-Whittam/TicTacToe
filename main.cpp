#include "window.h"

using namespace std;

int main(int argc, char **argv) {

    Window window("TicTacToe", 800, 600);

    while (!window.isClosed()) {
        window.pollEvents();
        window.clear();
    }

    return 0;
}