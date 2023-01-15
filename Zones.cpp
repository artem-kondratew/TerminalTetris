//
// Created by user on 1/15/23.
//

#include "Zones.h"


void Zones::paintHorLine(int len, int x0, int y0) {
    move(Y + y0, X + x0);
    printw("+");
    for (int x = 0; x < len * scale; x++) {
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
    move(0, 0);
    printw("xx\nxx");
    paintHorLine(width, 0, 0);
    paintHorLine(width, 0, 2);
    paintVerLine(1, 0, 0);
    paintVerLine(1, width * scale + 1, 0);
    move(1 + Y, 2 + X);
    printw("Score:");
    refresh();
}


void Zones::paintGameZone() {
    paintHorLine(width, 0, height + 3);
    paintVerLine(height, 0, 2);
    paintVerLine(height, width * scale + 1, 2);
    refresh();
}


void Zones::paintNextShapeZone() {
    paintHorLine(8, width * scale + 1, 0);
    paintHorLine(8, width * scale + 1, 10);
    paintVerLine(9, width * scale + 18, 0);
    move(2, width * scale + 6);
    printw("Next shape");
    refresh();
}


void Zones::paintHighscore() {
    paintHorLine(8, width * scale + 1, height + 3);
    paintVerLine(12, width * scale + 18, 10);
    move(12, width * scale + 6);
    printw("Highscore:");
    refresh();
}


void Zones::configField() {
    paintScoreZone();
    paintGameZone();
    paintNextShapeZone();
    paintHighscore();
}
