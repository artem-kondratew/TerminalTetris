//
// Created by user on 1/15/23.
//

#include "Figure.h"


Figure::Figure(std::vector<int> vector): Matrix(4, 3) {
    rows = 4;
    cols = 3;
    size = rows * cols;
    setMatrix(std::move(vector));
}


void Figure::paintFigure(int x0, int y0) {
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols * 2; col += 2) {
            move(y0 + row, x0 + col);
            if (data[row][col/2] == 1) {
                printw("[]");
            }
            else {
                printw("00");
            }
        }
}
