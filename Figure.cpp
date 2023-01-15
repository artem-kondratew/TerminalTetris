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

void Figure::generateFigures() {
    std::vector<int> T_vector = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0};
    Figure T_figure(T_vector);

    std::vector<int> Q_vector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0};
    Figure Q_figure(Q_vector);

    std::vector<int> I_vector = {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0};
    Figure I_figure(I_vector);

    std::vector<int> Z_vector = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0};
    Figure Z_figure(Z_vector);

    std::vector<int> S_vector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0};
    Figure S_figure(S_vector);

    std::vector<int> J_vector = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0};
    Figure J_figure(J_vector);

    std::vector<int> L_vector = {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0};
    Figure L_figure(L_vector);
}
