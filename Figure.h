//
// Created by user on 1/15/23.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <curses.h>
#include <string>
#include <vector>
#include "Matrix.h"


class Figure: public Matrix {
    friend class Tetris;
    friend class Engine;
    int X0{};
    int Y0{};
    int deltaX{};
    int deltaY{};
    int left_border{};
    int right_border{};
    int nonrotation{};
public:
    explicit Figure(std::vector<int> vector, int rows, int cols, int nonrotating=0);
    Figure() = default;
    Figure(const Figure& other) = default;
    void paint(int x0, int y0, int rows_number);
    void erase(int x0, int y0, int rows_number);
    void rotateLeft();
    void rotateRight();
    void findLeftBorder();
    void findRightBorder();
    void findBorders();
    void moveFigure(int step);
    int cutEmptyBottom();
};


#endif //TETRIS_FIGURE_H
