//
// Created by user on 1/15/23.
//

#ifndef TETRIS_MATRIX_H
#define TETRIS_MATRIX_H

#include <cmath>
#include <vector>


class Matrix {
    friend class Figure;
protected:
    int rows;
    int cols;
    int size;
    int** data;
    int* values;
public:
    Matrix();
    Matrix(int new_rows, int new_cols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept ;
    ~Matrix();
    void setData(int row, int col, int value);
    void setMatrix(std::vector<int> vector);
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept ;
    [[nodiscard]] int getRows() const;
    [[nodiscard]] int getCols() const;
    void resize(int new_rows, int new_cols);
};


#endif //TETRIS_MATRIX_H
