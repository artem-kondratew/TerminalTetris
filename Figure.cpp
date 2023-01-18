//
// Created by user on 1/15/23.
//

#include "Figure.h"


Figure::Figure(std::vector<int> vector): Matrix(4, 4) {
    setMatrix(std::move(vector));
    //rot_row = rot_row;
    //rot_col = rot_col;
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
    /*if (rot_row == -1) {
        return;
    }*/
    Figure buffer = *this;
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            data[row][col] = buffer.data[col][3-row];
}


void Figure::rotateRight() {
    /*if (rot_row == -1) {
        return;
    }*/
    Figure buffer = *this;
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            data[row][col] = buffer.data[3-col][row];
}


void Figure::findBorders() {
    left_border = -1;
    right_border = cols - 1;
    int buffer;
    for (int col = 0; col < cols; col++) {
        buffer = 0;
        for (int row = 0; row < rows; row++) {
            if (data[row][col] == 1) {
                buffer = 1;
            }
        }
        if (buffer == 1 && left_border == -1) {
            left_border = col;
        }
        if (buffer == 0 && left_border != -1) {
            right_border = col - 1;
        }
    }
}
