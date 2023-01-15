//
// Created by user on 1/15/23.
//

#ifndef TETRIS_GAMEFIELD_H
#define TETRIS_GAMEFIELD_H

#include "cmath"
#include "Matrix.h"
#include "Zones.h"


class GameField: public Matrix {
private:
    int X;
    int Y;
public:
    GameField();
    ~GameField();
};


#endif //TETRIS_GAMEFIELD_H
