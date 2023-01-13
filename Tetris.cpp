//
// Created by user on 1/13/23.
//

#include "Tetris.h"


void Tetris::init() {
    initscr();
    savetty();  //  save terminal settings
    nonl();  //  deny going to the new line
    cbreak();  //  буфер передается без нажатия enter
    noecho();  //  не отображается печать символов
    timeout(0); //  неблокируюшее чтение
    leaveok(stdscr, TRUE);  //  сдвиг курсора - нормально
    curs_set(0);  //  спрятать курсор
    //signal(SIGINT, sighandler);  //  обработка Ctrl + C
    //signal(SIGQUIT, sighandler);  //  обработка Ctrl + обратный /
    //signal(SIGWINCH, sighandler);  //  обработка изменения размера окна
    //signal(SIGTSTP, sighandler);  //  обработка Ctrl + Z
}


void Tetris::finish() {
    curs_set(1);  //  показать курсор
    clear();  //  очистка экрана
    refresh();
    resetty();  //  восстановление настроек терминала
    endwin();  //  подготовка к выходу
    exit(0);
}