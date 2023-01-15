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
private:
    //inline static const std::string left = "[";
    //inline static const std::string right = "]";
public:
    explicit Figure(std::vector<int> vector);
    void paintFigure(int x0, int y0);
    void rotateLeft();
    void rotateRight();
};


#endif //TETRIS_FIGURE_H
