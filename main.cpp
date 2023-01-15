#include <iostream>
#include "Tetris.h"



int main() {

    Tetris::initWindow();
    Tetris::configTetris();
    Engine Field;

    Engine::Gaming(Field);

    //Tetris::finish();


    return 0;
}
