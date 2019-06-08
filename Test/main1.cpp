#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.hpp"

int main(int argc, char ** argv)
{
    /* Ncurses start*/
    initscr();
    noecho();
    cbreak();

//get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //create a window for our input
    WINDOW *playwin = newwin(20, 50, (yMax/2)-10, 10);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    Player *p = new Player(playwin, 1,1, '$');
    do{ //print space first
        p->display();
        wrefresh(playwin);
    }while(p->getmv() !='x');

//Make sure program waits before exiting
    getch();
    endwin();
/*NCURSES END*/
    return 0;
}