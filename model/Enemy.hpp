#ifndef __ENEMY__
#define __ENEMY__
#include <string>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <ctime>
#include "../view/View.hpp"

class Enemy{

    public:
    Enemy(View * view, char c);
    Enemy(Enemy const & player);
    Enemy(void);
    Enemy const & operator = (Enemy const & rhs) const;
    ~Enemy(void);

    void shoot();
    void mvup();
    void mvdown();
    void mvleft();
    void mv(); //generally move the enemy towards the player's side of the game
    int getxloc();
    int getyloc();
    void display();
    //Enemy will be killed and instantiated by the game
    private:
    View * view;
    int xLoc, yLoc, xMax, yMax;//contain player location
    char character; //enemy character
    bool isAlive; //this tells us if the unit is alive or dead

};
#endif
