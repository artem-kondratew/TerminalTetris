//
// Created by user on 1/15/23.
//

#include "Zones.h"


void Zones::setXY(int lines, int columns) {
    X = columns / 2 - GX / 2;
    Y = lines / 2 - GY / 2;
}


void Zones::paintHorLine(int len, int x0, int y0) {
    move(Y + y0, X + x0);
    printw("+");
    for (int x = 0; x < len; x++) {
        printw("-");
    }
    printw("+\n");
}


void Zones::paintVerLine(int len, int x0, int y0) {
    move(Y + y0, X + x0);
    printw("+");
    for (int y = 0; y < len; y++) {
        move(Y + y0 + y + 1, X + x0);
        printw("|");
    }
    move(Y + len + 1 + y0, X + x0);
    printw("+");
}


void Zones::paintScoreZone() {
    paintHorLine(width * scale, 0, 0);
    paintHorLine(width * scale, 0, 2);
    paintVerLine(1, 0, 0);
    paintVerLine(1, width * scale + 1, 0);
    move(1 + Y, 2 + X);
    printw("Score:");
    refresh();
}


void Zones::paintGameZone() {
    paintHorLine(width * scale, 0, height + 3);
    paintVerLine(height, 0, 2);
    paintVerLine(height, width * scale + 1, 2);
    refresh();
}


void Zones::paintNextShapeZone() {
    paintHorLine(9 * scale - 1, width * scale + 1, 0);
    paintHorLine(9 * scale - 1, width * scale + 1, 10);
    paintVerLine(9, width * scale + 19, 0);
    next_X = X + width * scale + 1;
    next_Y = Y + 5;
    move(Y + 1, X + width * scale + 5);
    printw("Next shape");
    refresh();
}


void Zones::paintHighscore() {
    paintHorLine(9 * scale - 1, width * scale + 1, height + 3);
    paintVerLine(12, width * scale + 19, 10);
    move(Y + 11, X + width * scale + 5);
    printw("Highscore:");
    refresh();
}


void Zones::configField() {
    paintScoreZone();
    paintGameZone();
    paintNextShapeZone();
    paintHighscore();
}


void Zones::paintGameOverZone() {
    int w = 11;
    int h = 3;
    int x0 = (GX - w) / 2;
    int y0 = (GY - h) / 2 - 4;
    paintHorLine(w + 2, x0, y0);
    paintHorLine(w + 2, x0, y0 + h + 3);
    paintVerLine(h + 2, x0, y0);
    paintVerLine(h + 2, x0 + w + 3, y0);

    for(int row = 0; row < h + 2; row++) {
        for (int col = 0; col < 13; col++) {
            move(Y + y0 + 1 + row, X + x0 + 1 + col);
            printw(" ");
        }
    }

    move(Y + y0 + 2, X + x0 + 3);
    printw("GAME OVER");
    move(Y + y0 + 4, X + x0 + 2);
    printw("Press Enter");
    refresh();
}
