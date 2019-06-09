#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.hpp"
#include "Enemy.hpp"

int main(int argc, char ** argv)
{
    /* Ncurses start*/
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);

//get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //create a window for our input
    WINDOW *playwin = newwin(20, 50, (yMax/2)-10, 10);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    Player *p = new Player(playwin, 1,1, '$');
    Enemy *e = new Enemy(playwin, 18,48,'&');

    halfdelay(2);
    while (( p->getmv()) != 27)
    {
        p->display();
        e->mv();
        e->display();
        if (( p->getmv()) == 32)
        {
            if (p->fire(e->getyloc(), e->getxloc()) == -1)
                break;
        }
        wrefresh(playwin);
        if ((p->getxloc() == e->getxloc() && p->getyloc() == e->getyloc()))
            break;
    }

    
//     do{ //print space first
//         p->display();
//       //  e->display();
//         wrefresh(playwin);
//     }while(p->getmv() !='x');
  
// // //Make sure program waits before exiting
//     getch();
    endwin();
/*NCURSES END*/
    return 0;
}