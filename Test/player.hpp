#ifndef __PLAYER__
#define __PLAYER__
#include <string>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <ctime>

class Player{

    public:
     Player();
       ~Player();
    Player(WINDOW * win, int y, int x, char c);

    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();
    int  getyloc();
    int  getxloc();
    int  fire(int x, int y);

    private:
    int xLoc, yLoc, xMax, yMax;//contain player location
    char character; //player
    WINDOW * curwin; //current window
    int     xloc;
    int     yloc;

};
#endif