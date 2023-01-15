//
// Created by user on 1/15/23.
//

#ifndef TETRIS_MATRIX_H
#define TETRIS_MATRIX_H


class Matrix {
    friend class Tetris;
    friend class Figure;
protected:
    int rows;
    int cols;
    int size;
    double** data;
    double* values;
public:
    Matrix(int new_rows, int new_cols);
    void setData(int row, int col, int value);
};


#endif //TETRIS_MATRIX_H
