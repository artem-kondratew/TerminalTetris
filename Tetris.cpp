//
// Created by user on 1/13/23.
//

#include "Tetris.h"


void Tetris::sighandler(int s) {
    finish();
}


void Tetris::initWindow() {
    initscr();
    savetty();  //  save terminal settings

    nonl();  //  deny going to the new line
    cbreak();  //  буфер передается без нажатия enter
    //noecho();  //  не отображается печать символов
    //timeout(0); //  неблокируюшее чтение
    //leaveok(stdscr, TRUE);  //  сдвиг курсора - нормально
    curs_set(0);  //  спрятать курсор

    signal(SIGINT, Tetris::sighandler);  //  обработка Ctrl + C
    //signal(SIGQUIT, Tetris::sighandler);  //  обработка Ctrl + обратный /
    //signal(SIGWINCH, Tetris::sighandler);  //  обработка изменения размера окна
    //signal(SIGTSTP, Tetris::sighandler);  //  обработка Ctrl + Z
}


void Tetris::finish() {
    //curs_set(1);  //  показать курсор
    clear();  //  очистка экрана
    refresh();
    resetty();  //  восстановление настроек терминала
    endwin();
    exit(0);
}


void Tetris::showMenu() {
    while(true) {
        //refresh();
    }
}


void Tetris::setScorePoint() {
    score_x = Zones::X + 9;
    score_y = Zones::Y + 1;
}


void Tetris::setScore(int new_score) {
    score = new_score;
    move(score_y, score_x);
    printw("%d", score);
    refresh();
}


int Tetris::getLines() {
    struct winsize window{};
    ioctl(0, TIOCGWINSZ, &window);
    return window.ws_row;
}


int Tetris::getColumns() {
    struct winsize window{};
    ioctl(0, TIOCGWINSZ, &window);
    return window.ws_col;
}


void Tetris::configTetris() {
    Zones::setXY(getLines(),getColumns());
    setScorePoint();
    Zones::configField();
    setScore(0);
}
