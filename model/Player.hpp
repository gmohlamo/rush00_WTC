#ifndef __PLAYER__
#define __PLAYER__
#include <string>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <ctime>
#include "../view/View.hpp"

class Player{

    public:
    Player(View * view, char c);
    Player(Player const & player);
    Player(void);
    Player & operator = (Player const & player);
    ~Player(void);

    void shoot();
    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();

    private:
    View * view;
    int xLoc, yLoc, xMax, yMax;//contain player location
    char character; //player

};
#endif
