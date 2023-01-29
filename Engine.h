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

#define KEY_RETURN 13
#define KEY_ESC 27


class Engine: public Matrix {
private:
    int X;
    int Y;
    inline static Figure figure{};
    inline static Figure next_figure{};
public:
    inline static int resize_flag = 0;
private:
    static int generateRandomNumber();
    void setXY();
    static Figure chooseNextFigure(int randomNumber);
    void writeBits();
    int compareBits();
    void moveFigure(int step);
    void refreshField();
    int fillCheck();
    static void eraseNextFigure();
    static void paintNextFigure();
    static void generateNextFigure();
    static int findx0(int is_I_figure);
    static int findy0();
    static void dropFigure();
    void findSeries();
    void shiftField(int series_row);
public:
    Engine();
    ~Engine() = default;
    static void Gaming();
    static void handleResize();
};


#endif //TETRIS_ENGINE_H
