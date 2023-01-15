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
public:
    explicit Figure(std::vector<int> vector);
    Figure() = default;
    Figure(const Figure& other) = default;
    void paintFigure(int x0, int y0);
    void rotateLeft();
    void rotateRight();
};


#endif //TETRIS_FIGURE_H
