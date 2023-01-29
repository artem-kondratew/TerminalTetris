//
// Created by user on 1/13/23.
//

#include "Tetris.h"


void Tetris::signalHandler(int signal) {
    if (signal == SIGINT) {
        finish();
    }
    if (signal == SIGWINCH) {
        checkTerminalSize();
    }
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
    signal(SIGWINCH, Tetris::signalHandler);  //  обработка изменения размера окна
    //signal(SIGTSTP, Tetris::signalHandler);  //  обработка Ctrl + Z

    set_escdelay(0);
}


void Tetris::finish() {
    //curs_set(1);  //  показать курсор
    clear();  //  очистка экрана
    refresh();
    resetty();  //  восстановление настроек терминала
    endwin();
    exit(0);
}

/*
void Tetris::checkTerminalSize() {
    if(getLines() < Zones::GY || getColumns() < Zones::X) {
        clear();
        move(0, 0);
        printw("terminal is very small");
        refresh();
        Tetris::gameOver();
    }
    else {
        Engine::resize_flag = 1;
        clear();
        Zones::setXY(getLines(),getColumns());
        setScorePoint();
        Zones::configZones();
        Engine::handleResize();
        readHighscore();
        refresh();
    }
}
*/

void Tetris::checkTerminalSize() {
    clear();
    refresh();
    Zones::paintGameOverZone();
    writeHighscore();
    while (true) {
        if (getch() == KEY_ESC || getch() == KEY_RETURN) {
            break;
        }
    }
    finish();
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
    file.open(".tetris_highscore.txt");
    if (!file.is_open()) {
        return;
    }

    int position = 0;

    while(!file.eof()) {
        file >> highscore[position];
        if (highscore[position] != 0) {
            move(Zones::Y + 13 + position, Zones::X + Zones::field_width * Zones::hor_scale + 3);
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
    Zones::configZones();
    setScore(0);
    readHighscore();
    Engine::Gaming();
}


void Tetris::pause() {
    move(Zones::next_Y + 4, Zones::next_X + 7);
    printw("PAUSE");
    refresh();
    while (true) {
        if (getch() == KEY_RETURN || getch() == KEY_ESC) {
            break;
        }
    }
    move(Zones::next_Y + 4, Zones::next_X + 7);
    printw("     ");
    refresh();
}


void Tetris::writeHighscore() {
    int flag =  -1;
    for (int position = 0; position < score_quantity; position++) {
        if (score > highscore[position]) {
            flag = position;
            break;
        }
    }

    if (flag != -1) {
        for (int position = score_quantity - 2; position >= flag; position--) {
            highscore[position+1] = highscore[position];
        }
        highscore[flag] = score;
    }

    std::ofstream file;
    file.open(".tetris_highscore.txt");
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
    writeHighscore();
    while (true) {
        if (getch() == KEY_ESC) {
            finish();
        }
        if (getch() == KEY_RETURN) {
            clear();
            return;
        }
    }
}
