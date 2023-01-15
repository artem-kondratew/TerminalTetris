//
// Created by user on 1/13/23.
//

#ifndef TETRIS_TETRIS_H
#define TETRIS_TETRIS_H

#include <csignal>
#include <cstdlib>
#include <ncurses.h>
#include <vector>
#include <sys/ioctl.h>
#include "Zones.h"
#include "GameField.h"
#include "Figure.h"


class Tetris {
private:
    inline static int score = NAN;
    inline static int score_x = NAN;
    inline static int score_y = NAN;
private:
    static void sighandler(int s);
public:
    static void initWindow();
    static void finish();
    static void showMenu();
    static void setScorePoint();
    static void setScore(int new_score);
    static int getLines();
    static int getColumns();
    static void configTetris();
};


#endif //TETRIS_TETRIS_H
