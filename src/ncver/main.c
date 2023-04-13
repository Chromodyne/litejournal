#include<ncurses.h>

int main(int argc, char **argv) {

    initscr();
    printw("Ncurses version.");
    refresh();
    getch();
    endwin();

    return 0;

}