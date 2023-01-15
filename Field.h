//
// Created by user on 1/15/23.
//

#ifndef TETRIS_FIELD_H
#define TETRIS_FIELD_H

#include <string>
#include <ncurses.h>


class Field {
    friend class Tetris;
private:
    inline static int X = 1;
    inline static int Y = 1;
    inline static int scale;
    inline static int width;
    inline static int height;
protected:
    static const int SCALE = 2;
    static const int WIDTH = 10;
    static const int HEIGHT = 20;
private:
    static void paintHorLine(int len, int x0, int y0);
    static void paintVerLine(int len, int x0, int y0);
public:
    static void setScale(int new_scale);
    static void setWidth(int new_width);
    static void setHeight(int new_height);
    static void paintGameZone();
    static void paintScoreZone();
    static void paintNextShapeZone();
    static void configField();
};


#endif //TETRIS_FIELD_H
