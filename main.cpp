#include "Tetris.h"


int main() {

    Tetris::initWindow();

    while (true) {
        Tetris::configTetris();
        Tetris::gameOver();
    }
}
