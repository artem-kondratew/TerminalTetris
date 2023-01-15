//
// Created by user on 1/15/23.
//

#include "Matrix.h"


Matrix::Matrix(int new_rows, int new_cols) {
    rows = new_rows;
    cols = new_cols;
    size = rows * cols;
    data = new double *[rows];
    values = new double [size];
    for (int row = 0; row < rows; row++)
        data[row] = values + row * cols;
    for (int cell = 0; cell < size; cell++)
        values[cell] = 0;
}


void Matrix::setData(int row, int col, int value) {
    data[row][col] = value;
}
