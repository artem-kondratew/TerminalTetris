//
// Created by user on 1/15/23.
//

#ifndef TETRIS_ENGINE_H
#define TETRIS_ENGINE_H

#include <chrono>
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
    Figure figure{};
private:
    static Figure chooseNext(int randomNumber);
    static int generateRandomNumber();
    void writeBits();
    int compareBits();
    void refreshField();
    int fillChecker();
public:
    Engine();
    ~Engine() = default;
    static void Gaming();
};


#endif //TETRIS_ENGINE_H
