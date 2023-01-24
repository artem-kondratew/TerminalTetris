#include <iostream>
#include "Tetris.h"


int main() {

    Tetris::initWindow();
    Tetris::configTetris();

    Engine::Gaming();
    Tetris::gameOver();

    Tetris::finish();

    return 0;
}
