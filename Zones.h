//
// Created by user on 1/15/23.
//

#ifndef TETRIS_ZONES_H
#define TETRIS_ZONES_H

#include <ncurses.h>
#include <vector>


class Zones {
    friend class Tetris;
    friend class Engine;
private:
    inline static int GX = 40;
    inline static int GY = 24;
    inline static int X{};
    inline static int Y{};
    inline static int next_X{};
    inline static int next_Y{};
    inline static int hor_scale = 2;
    inline static int field_width = 10;
    inline static int field_height = 20;
private:
    static void setXY(int LINES, int COLUMNS);
    static void paintHorLine(int len, int x0, int y0);
    static void paintVerLine(int len, int x0, int y0);
public:
    static void paintScoreZone();
    static void paintGameZone();
    static void paintNextShapeZone();
    static void paintHighscore();
    static void configZones();
    static void paintGameOverZone();
};


#endif //TETRIS_ZONES_H
