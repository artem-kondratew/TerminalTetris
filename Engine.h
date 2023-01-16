//
// Created by user on 1/15/23.
//

#ifndef TETRIS_ENGINE_H
#define TETRIS_ENGINE_H

#include <chrono>
#include <cmath>
#include <iostream>
#include <random>
#include "Figure.h"
#include "Matrix.h"
#include "Zones.h"
#include "Tetris.h"


class Engine: public Matrix {
private:
    int X;
    int Y;
private:
    static Figure chooseNext(int randomNumber);
    static int generateRandomNumber();
    void writeBits(const Figure& figure, int y_add);
    int compareBits(const Figure& figure, int y_add);
public:
    Engine();
    ~Engine();
    static void Gaming(Engine Field);
};


#endif //TETRIS_ENGINE_H
