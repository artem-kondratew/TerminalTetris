//
// Created by user on 1/15/23.
//

#include <cstring>
#include "Matrix.h"


Matrix::Matrix(int new_rows, int new_cols) {
    rows = new_rows;
    cols = new_cols;
    size = rows * cols;
    data = new int *[rows];
    values = new int [size];
    for (int row = 0; row < rows; row++)
        data[row] = values + row * cols;
    for (int cell = 0; cell < size; cell++)
        values[cell] = 0;
}


Matrix::Matrix(const Matrix &other) {
    rows = other.rows;
    cols = other.cols;
    size = rows * cols;
    data = new int* [rows];
    values = new int [size];
    for (int row = 0; row < rows; row++)
        data[row] = values + row * cols;
    std::memcpy(values, other.values, sizeof(int) * other.size);
}


Matrix::~Matrix() {
    delete[] data;
    delete[] values;
    rows = 0;
    cols = 0;
    size = 0;
}


void Matrix::setData(int row, int col, int value) {
    data[row][col] = value;
}


void Matrix::setMatrix(std::vector<int> vector) {
    for (int cell = 0; cell < size; cell++)
        values[cell] = vector[cell];
}
