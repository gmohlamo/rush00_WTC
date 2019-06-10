#include "player.hpp"
#include <cstdlib>

Player::Player(Player const & obj)
{
    *this = obj;
}

Player::Player(){}

Player::~Player(){}

Player::Player(WINDOW * win, int y, int x, char c)
{
    curwin = win;
    yloc = y;
    xloc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
}

void    Player::mvdown()
{
    mvwaddch(curwin, yloc, xloc, ' ');
    yloc++;
    if (yloc > yMax - 2)
        yloc = yMax - 2;
}

void    Player::mvup()
{
    mvwaddch(curwin, yloc, xloc, ' ');
    yloc--;
    if (yloc < 1)
        yloc = 1;
}

void    Player::mvright()
{
    mvwaddch(curwin, yloc, xloc, ' ');
    xloc++;
    if (xloc > xMax - 2)
        xloc = xMax - 2;
}

void    Player::mvleft()
{
    mvwaddch(curwin, yloc, xloc, ' ');
    xloc--;
    if (xloc < 1)
        xloc = 1;
}

void    Player::display()
{
    mvwaddch(curwin, yloc, xloc, character);
}

int     Player::getmv()
{
    int     choice = wgetch(curwin);

    switch(choice)
    {
        case KEY_UP:
            mvup();
            break;
        
        case KEY_DOWN:
            mvdown();
            break;

        case KEY_RIGHT:
            mvright();
            break;
        
        case KEY_LEFT:
            mvleft();
            break;

        default:
            break;
    }
    return (choice);
}

int     Player::getxloc()
{
    return (xloc);
}

int     Player::getyloc()
{
    return (yloc);
}

int     Player::fire(int y, int x)
{
    int i;

    i = xloc++;
    while (i <= xMax -2)
    {
        
        //mvwaddch(curwin, yloc, i, '-');
        mvwaddch(curwin, yloc, i, '-');
        //mvwaddch(curwin, yloc, i, ' ');
        refresh();
        if (y == yloc && i == x)
            return (-1);
         usleep(3000); 
        i++;
        //halfdelay(300);
        
    }
    return (1);
    // return (yloc);

}

WINDOW* Player::getwin()
{
    return (curwin);
}

int     Player::getxmax()
{
    return (xMax);
}

void Player::Background()
{
    int loc[15] ={4,9,11,2,22,32,5,17,7,42,39,15,35,20,26};
    int x = rand() % 15;
    int lo[10] ={1,5,17,14,7,3,12,5,10,16};
    int y = rand() % 10;

        mvwaddch(curwin, lo[y], loc[x], '.');
}
