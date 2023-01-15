//
// Created by user on 1/13/23.
//

#ifndef TETRIS_TETRIS_H
#define TETRIS_TETRIS_H

#include <csignal>
#include <cstdlib>
#include <ncurses.h>
#include "Field.h"


class Tetris {
private:
    inline static int score = {};
    inline static int score_x = {};
    inline static int score_y = {};
private:
    static void sighandler(int s);

public:
    static void init();
    static void finish();
    static void showMenu();
    static void setScore(int new_score);
};


#endif //TETRIS_TETRIS_H
