//
// Created by user on 1/15/23.
//

#ifndef TETRIS_ZONES_H
#define TETRIS_ZONES_H

#include <ncurses.h>


class Zones {
    friend class Tetris;
private:
    inline static int X = 1;
    inline static int Y = 1;
    inline static int scale = 2;
    inline static int width = 10;
    inline static int height = 20;
private:
    static void paintHorLine(int len, int x0, int y0);
    static void paintVerLine(int len, int x0, int y0);
public:
    static void paintScoreZone();
    static void paintGameZone();
    static void paintNextShapeZone();
    static void paintHighscore();
    static void configField();
};


#endif //TETRIS_ZONES_H
