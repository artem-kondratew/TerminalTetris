//
// Created by user on 1/15/23.
//

#include "GameField.h"


GameField::GameField(): Matrix(20, 10) {
    X = Zones::X + 1;
    Y = Zones::Y + 3;
    move(Y, X);
    printw("0");
    refresh();
}

GameField::~GameField() {
    X = NAN;
    Y = NAN;
}
