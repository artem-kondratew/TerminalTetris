//
// Created by user on 1/15/23.
//

#ifndef TETRIS_MATRIX_H
#define TETRIS_MATRIX_H


class Matrix {
    friend class Tetris;
protected:
    int rows;
    int cols;
    int size;
    double** data;
    double* values;
public:
    Matrix(int new_rows, int new_cols);
};


#endif //TETRIS_MATRIX_H
