//
// Created by user on 1/15/23.
//

#include "T_figure.h"


Matrix T_figure::generateT_figure() {
    Matrix matrix(4, 3);
    matrix.setData(3, 0, 1);
    matrix.setData(3, 1, 1);
    matrix.setData(3, 2, 1);
    matrix.setData(4, 1, 1);
    return matrix;
}
