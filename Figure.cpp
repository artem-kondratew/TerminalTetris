//
// Created by user on 1/15/23.
//

#include "Figure.h"


Figure::Figure(std::vector<int> vector): Matrix(4, 4) {
    rows = 4;
    cols = 4;
    size = rows * cols;
    setMatrix(std::move(vector));
}


void Figure::paintFigure(int x0, int y0) {
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols * 2; col += 2) {
            move(y0 + row, x0 + col);
            (data[row][col/2] == 1) ? printw("[]") : printw("00");
        }
}


void Figure::rotateLeft() {
    Matrix buffer = *this;
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            data[row][col] = buffer.data[col][3-row];
}


void Figure::rotateRight() {
    Matrix buffer = *this;
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            data[row][col] = buffer.data[3-col][row];
}
