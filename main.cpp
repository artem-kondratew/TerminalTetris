#include <ncurses.h>


int main() {
    initscr();
    printw("Hello world!\n");
    refresh();
    endwin();
    return 0;
}