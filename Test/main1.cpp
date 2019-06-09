#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <ctime>
#include "player.hpp"
#include "Enemy.hpp"

int         main(void)
{
    initscr();
    noecho();
    cbreak();

    int ymax;
    int xmax;
    int input;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW * playwin = newwin(20, 50, (ymax/2) - 10, 10);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);
    curs_set(FALSE);
    Player *p = new Player(playwin, 1, 1, 'x' );
    Enemy *e1 = new Enemy(playwin, 18, 48, 'e' );
    halfdelay(5);
    int s = 0;
    int i = 0;
    int t = 30;
    while ((input = p->getmv()) != 27)
    {
        
        if ((t= (float)clock()) < 300000)
        {
            
            mvwprintw(stdscr, 1, 25, "Time:%d", t );
            refresh();
            sleep(0);
            //break;
        }
        p->Background();
        p->display();

        e1->mv();
        e1->display();
        if (input == 32)
        {
            mvwaddch(p->getwin(), s, i, ' ');
            refresh();
            s = p->getyloc();
            i = p->getxloc();
        }
        i++;
        if (i >= 49)
        {
            mvwaddch(p->getwin(), s, i - 1, ' ');
            refresh();
            s = 0;
            i = 0;
        }
        if (s != 0 && i != 0)
        {
            mvwaddch(p->getwin(), s, i, '-');
            refresh();
            mvwaddch(p->getwin(), s, i - 1, ' ');
            refresh();
        }
        if (s == e1->getyloc() && i == e1->getxloc())//bullet collision
        {
            
            mvwprintw(stdscr, 1, 25, "Winner");
            refresh();
            sleep(2);
            break;
        }
        wrefresh(playwin);
        if ((p->getxloc() == e1->getxloc() && p->getyloc() == e1->getyloc()))
            {
            mvwprintw(stdscr, 1, 25, "Lost,go cry to ur mom");
            refresh();
            sleep(2);
            break;}
    }

    endwin();
    return (0);
}