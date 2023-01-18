//
// Created by user on 1/15/23.
//

#include "Figure.h"


Figure::Figure(std::vector<int> vector, int nr_row, int nr_col): Matrix(4, 4) {
    setMatrix(std::move(vector));
    rotate_row = nr_row;
    rotate_col = nr_col;
}


void Figure::paint(int x0, int y0, int rows_number) {
    for (int row = rows - 1; row >= 0; row--)
        for (int col = 0; col < cols * 2; col += 2) {
            if (row > 3 - rows_number) {
                if(data[row][col/2] == 1) {
                    move(y0 + row, x0 + col);
                    printw("[]");
                }
            }
            else {
                break;
            }
        }
}


void Figure::erase(int x0, int y0, int rows_number) {
    for (int row = rows - 1; row >= 0; row--)
        for (int col = 0; col < cols; col++) {
            if (row > 3 - rows_number) {
                if (data[row][col] == 1) {
                    move(y0 + row, x0 + col * 2);
                    printw("  ");
                }

            }
            else {
                break;
            }
        }
}


void Figure::rotateLeft() {
    if (rotate_row == -1) {
        return;
    }
    Figure buffer = *this;
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            data[row][col] = buffer.data[col][3-row];
}


void Figure::rotateRight() {
    if (rotate_row == -1) {
        return;
    }
    Figure buffer = *this;
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            data[row][col] = buffer.data[3-col][row];
}
