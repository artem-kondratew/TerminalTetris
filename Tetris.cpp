//
// Created by user on 1/13/23.
//

#include "Tetris.h"

#define KEY_ENTER 13


void Tetris::signalHandler(int s) {
    finish();
}


void Tetris::initWindow() {
    initscr();
    savetty();  //  save terminal settings

    nonl();  //  deny going to the new line
    cbreak();  //  буфер передается без нажатия enter
    noecho();  //  не отображается печать символов
    timeout(0); //  неблокируюшее чтение
    //leaveok(stdscr, TRUE);  //  сдвиг курсора - нормально
    curs_set(0);  //  спрятать курсор
    keypad(stdscr, TRUE);

    signal(SIGINT, Tetris::signalHandler);  //  обработка Ctrl + C
    //signal(SIGQUIT, Tetris::signalHandler);  //  обработка Ctrl + обратный /
    //signal(SIGWINCH, Tetris::signalHandler);  //  обработка изменения размера окна
    //signal(SIGTSTP, Tetris::signalHandler);  //  обработка Ctrl + Z
}


void Tetris::finish() {
    //curs_set(1);  //  показать курсор
    clear();  //  очистка экрана
    refresh();
    resetty();  //  восстановление настроек терминала
    endwin();
    exit(0);
}


void Tetris::setScorePoint() {
    score_x = Zones::X + 9;
    score_y = Zones::Y + 1;
}


void Tetris::setScore(uint64_t new_score) {
    score = new_score;
    move(score_y, score_x);
    printw("%ld", score);
    refresh();
}


void Tetris::increaseScore(int delta_score) {
    setScore(score + delta_score);
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


void Tetris::readHighscore() {
    std::ifstream file;
    file.open("../Highscore.txt");
    if (!file.is_open()) {
        move(0,0);
        printw("oh");
        return;
    }

    int position = 0;

    while(!file.eof()) {
        file >> highscore[position];
        if (highscore[position] != 0) {
            move(Zones::Y + 13 + position, Zones::X + Zones::width * Zones::scale + 3);
            printw("%d. %lu", position + 1, highscore[position]);
        }
        position++;
    }
    file.close();
    refresh();
}


void Tetris::configTetris() {
    Zones::setXY(getLines(),getColumns());
    setScorePoint();
    Zones::configField();
    setScore(0);
    readHighscore();
}


void Tetris::writeHighscore() {
    for (int position = 0; position < score_quantity; position++) {
        if (score > highscore[position]) {
            highscore[position] = score;
            break;
        }
    }

    std::ofstream file;
    file.open("../Highscore.txt");
    if (file.is_open()) {
        for (int position = 0; position < score_quantity; position++) {
            file << highscore[position];
            if (position < 9) {
                file << std::endl;
            }
        }
        file.close();
    }
}


void Tetris::gameOver() {
    Zones::paintGameOverZone();

    while (true) {
        if (getch() == KEY_ENTER) {
            break;
        }
    }
    writeHighscore();
}
