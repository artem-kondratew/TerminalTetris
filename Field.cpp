//
// Created by user on 1/15/23.
//

#include "Field.h"


void Field::setScale(int new_scale) {
    scale = new_scale;
}


void Field::setWidth(int new_width) {
    width = new_width;
}


void Field::setHeight(int new_height) {
    height = new_height;
}


void Field::paintHorLine(int len, int x0, int y0) {
    move(Y + y0, X + x0);
    printw("+");
    for (int x = 0; x < len * scale; x++) {
        printw("-");
    }
    printw("+\n");
}


void Field::paintVerLine(int len, int x0, int y0) {
    move(Y + y0, X + x0);
    printw("+");
    for (int y = 0; y < len; y++) {
        move(Y + y0 + y + 1, X + x0);
        printw("|");
    }
    move(Y + len + 1 + y0, X + x0);
    printw("+");
}


void Field::paintGameZone() {
    paintHorLine(width, 0, 2);
    paintHorLine(width, 0, height + 3);
    paintVerLine(height, 0, 2);
    paintVerLine(height, width * scale + 1, 2);
    refresh();
}


void Field::paintScoreZone() {
    move(0, 0);
    printw("xx\nxx");
    paintHorLine(width, 0, 0);
    paintHorLine(width, 0, 2);
    paintVerLine(1, 0, 0);
    paintVerLine(1, width * scale + 1, 0);
    move(1 + Y, 2 + X);
    printw("Score: 0");
    refresh();
}


void Field::paintNextShapeZone() {

}


void Field::configField() {
    //printw("TEST\n");
    Field::setScale(Field::SCALE);
    Field::setWidth(Field::WIDTH);
    Field::setHeight(Field::HEIGHT);
    Field::paintScoreZone();
    Field::paintGameZone();
}
