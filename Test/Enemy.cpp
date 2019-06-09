#include "Enemy.hpp"

Enemy::Enemy(){}

Enemy::~Enemy(){}

Enemy::Enemy(WINDOW * win, int y, int x, char c)
{
    curwin = win;
    yloc = y;
    xloc = x;
    xmax = getmaxx(win);
    ymax = getmaxy(win);
    getmaxyx(curwin, ymax, xmax);
    keypad(curwin, true);
    character = c;
}

int    Enemy::mv()
{
    mvwaddch(curwin, yloc, xloc, ' ');
    static int y = 1;
    static int x = 1;

    if (y == 1)
    {
        yloc++;
        if (yloc > ymax - 2)
        {
            yloc--;
            y = -1;
        }
    }
    else
    {
        yloc--;
        if (yloc < 1)
        {
            yloc++;
            y = 1;
        }
    }

    if (x == 1)
    {
        xloc++;
        if (xloc > xmax - 2)
        {
            xloc--;
            x = -1;
        }
    }
    else
    {
        xloc--;
        if (xloc < 1)
        {
            xloc++;
            x = 1;
        }
    }
    return (1);
}

void    Enemy::display()
{
    mvwaddch(curwin, yloc, xloc, character);
}

int     Enemy::getxloc()
{
    return (xloc);
}

int     Enemy::getyloc()
{
    return (yloc);
}