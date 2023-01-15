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
#include "Figure.h"


class Tetris {
private:
    inline static int score = {};
    inline static int score_x = Zones::X + 9;
    inline static int score_y = Zones::Y + 1;

private:
    static void sighandler(int s);
public:
    static void init();
    static void finish();
    static void showMenu();
    static void setScore(int new_score);
    static int getLines();
    static int getColumns();
};


#endif //TETRIS_TETRIS_H
