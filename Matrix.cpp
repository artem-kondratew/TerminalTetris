//
// Created by user on 1/15/23.
//

#include <cstring>
#include "Matrix.h"


Matrix::Matrix() {
    rows = NAN;
    cols = NAN;
    size = NAN;
    data = nullptr;
    values = nullptr;
}


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


Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    size = other.size;
    data = new int* [rows];
    values = new int [size];
    for (int row = 0; row < rows; row++)
        data[row] = values + row * cols;
    std::memcpy(values, other.values, sizeof(int) * other.size);
}


Matrix::Matrix(Matrix&& other) noexcept {
    rows = other.rows;
    cols = other.cols;
    size = other.size;
    data = other.data;
    values = other.values;
    other.data = nullptr;
    other.values = nullptr;
}


Matrix::~Matrix() {
    delete[] data;
    delete[] values;
    rows = NAN;
    cols = NAN;
    size = NAN;
}


Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] data;
        delete[] values;
        rows = other.rows;
        cols = other.cols;
        size = other.size;
        data = new int* [rows];
        values = new int [size];
        for (int row = 0; row < rows; row++)
            data[row] = values + row * cols;
        std::memcpy(values, other.values, sizeof(int) * other.size);
    }
    return *this;
}


Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        delete[] data;
        delete[] values;
        rows = other.rows;
        cols = other.cols;
        size = other.size;
        data = other.data;
        values = other.values;
        other.data = nullptr;
        other.values = nullptr;
    }
    return *this;
}


void Matrix::setData(int row, int col, int value) {
    data[row][col] = value;
}


void Matrix::setMatrix(std::vector<int> vector) {
    for (int cell = 0; cell < size; cell++)
        values[cell] = vector[cell];
}
