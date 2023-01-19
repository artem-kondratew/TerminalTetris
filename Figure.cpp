//
// Created by user on 1/15/23.
//

#include "Figure.h"


Figure::Figure(std::vector<int> vector, int rows, int cols, int nonrotating): Matrix(rows, cols) {
    nonrotation = nonrotating;
    setMatrix(std::move(vector));
}


void Figure::paint(int x0, int y0, int rows_number) {
    for (int row = rows - 1; row >= 0; row--)
        for (int col = 0; col < cols * 2; col += 2) {
            if (row > rows - 1 - rows_number) {
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
            if (row > rows - 1 - rows_number) {
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
    if (nonrotation) {
        return;
    }
    Figure buffer = *this;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            data[row][col] = buffer.data[col][rows-1-row];
        }
    }
    this->findBorders();
    if (deltaX + left_border < 0 || deltaX + right_border >= 10) {
        *this = buffer;
        return;
    }
}


void Figure::rotateRight() {
    if (nonrotation) {
        return;
    }
    Figure flag = *this;
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            data[row][col] = flag.data[cols - 1 - col][row];
    this->findBorders();
    if (deltaX + left_border < 0 || deltaX + right_border >= 10) {
        *this = flag;
        return;
    }
}


void Figure::findLeftBorder() {
    left_border = -1;
    int flag;
    for (int col = 0; col < cols; col++) {
        flag = 0;
        for (int row = 0; row < rows; row++) {
            if (data[row][col] == 1) {
                flag = 1;
            }
        }
        if (flag == 1) {
            left_border = col;
            return;
        }
    }
}


void Figure::findRightBorder() {
    right_border = cols;
    int buffer;
    for (int col = cols - 1; col >= 0; col--) {
        buffer = 0;
        for (int row = 0; row < rows; row++) {
            if (data[row][col] == 1) {
                buffer = 1;
            }
        }
        if (buffer == 1) {
            right_border = col;
            return;
        }
    }
}


void Figure::findBorders() {
    this->findLeftBorder();
    this->findRightBorder();
}


void Figure::moveFigure(int step) {
    this->findBorders();
    if (deltaX + left_border + step >= 0 && deltaX + right_border + step < 10) {
        deltaX += step;
    }
}


int Figure::cutEmptyBottom() {
    int past = 0;
    int flag;
    for (int row = 0; row < rows; row++) {
        flag = 0;
        for (int col = 0; col < cols; col++) {
            if (data[row][col] == 1) {
                flag = 1;
                past = 1;
            }
        }
        if (flag == 0 && past != 0) {
            return rows - row;
        }
    }
    return 0;
}
