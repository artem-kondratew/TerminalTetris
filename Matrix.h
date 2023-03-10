//
// Created by user on 1/15/23.
//

#ifndef TETRIS_MATRIX_H
#define TETRIS_MATRIX_H

#include <cstring>
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
    Matrix(Matrix&& other) noexcept;
    ~Matrix();
    void setMatrix(std::vector<int> vector);
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept ;
    [[nodiscard]] int getRows() const;
};


#endif //TETRIS_MATRIX_H
