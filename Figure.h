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
    int rotate_row{};
    int rotate_col{};
public:
    explicit Figure(std::vector<int> vector, int nr_row, int nr_col);
    Figure() = default;
    Figure(const Figure& other) = default;
    void paint(int x0, int y0, int rows_number);
    void erase(int x0, int y0, int rows_number);
    void rotateLeft();
    void rotateRight();
};


#endif //TETRIS_FIGURE_H
