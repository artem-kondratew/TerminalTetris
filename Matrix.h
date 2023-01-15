//
// Created by user on 1/15/23.
//

#ifndef TETRIS_MATRIX_H
#define TETRIS_MATRIX_H

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
    Matrix(int new_rows, int new_cols);
    ~Matrix();
    void setData(int row, int col, int value);
    void setMatrix(std::vector<int> vector);
};


#endif //TETRIS_MATRIX_H
