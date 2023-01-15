//
// Created by user on 1/13/23.
//

#include "Tetris.h"


void Tetris::sighandler(int s) {
    finish();
}


void Tetris::init() {
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

    Field::configField();
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


void Tetris::setScore(int new_score) {
    score = new_score;
}
