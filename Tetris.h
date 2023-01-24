//
// Created by user on 1/13/23.
//

#ifndef TETRIS_TETRIS_H
#define TETRIS_TETRIS_H

#include <csignal>
#include <cstdlib>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <sys/ioctl.h>
#include "Zones.h"
#include "Engine.h"
#include "Figure.h"


class Tetris {
private:
    inline static uint64_t score{};
    inline static int score_x{};
    inline static int score_y{};
    inline static int score_quantity = 10;
    inline static uint64_t highscore[10];
private:
    static void signalHandler(int s);
public:
    static void initWindow();
    static void finish();
    static void setScorePoint();
    static void setScore(uint64_t new_score);
    static void increaseScore(int delta_score);
    static int getLines();
    static int getColumns();
    static void configTetris();
    static void writeHighscore();
    static void readHighscore();
    static void gameOver();
};


#endif //TETRIS_TETRIS_H
