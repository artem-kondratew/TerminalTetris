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
    Figure figure{};
    inline static Engine* Field_pointer{};
private:
    static Figure chooseNext(int randomNumber);
    static int generateRandomNumber();
    void writeBits();
    int compareBits();
    void refreshField();
    int fillChecker();
    static void keyHandler(int key);
public:
    Engine();
    ~Engine() = default;
    static void Gaming();
};


#endif //TETRIS_ENGINE_H
