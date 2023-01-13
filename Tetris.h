//
// Created by user on 1/13/23.
//

#ifndef TETRIS_TETRIS_H
#define TETRIS_TETRIS_H

#include <ncurses.h>
#include <csignal>
#include <cstdlib>


class Tetris {
public:
    Tetris() = default;
    ~Tetris() = default;

    static void init();
    static void finish();

    [[noreturn]] static void showMenu();
};


#endif //TETRIS_TETRIS_H
