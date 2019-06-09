#ifndef __ENEMY__
#define __ENEMY__
#include <string>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <ctime>

class Enemy
{
    public:
       Enemy();
       ~Enemy();
       Enemy(WINDOW * win, int y, int x, char c); 

       int  mv();
       void display();
       int  getyloc();
       int  getxloc();

    private:
        int     xloc;
        int     yloc;
        int     xmax;
        int     ymax;
        char    character;
        WINDOW  *curwin;
};
#endif