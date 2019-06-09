#ifndef __LASER__
#define __LASER__
#include <string>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <ctime>
#include "../view/View.hpp"

class Laser{

    public:
    Laser(View * view, char c);
    Laser(Laser const & player);
    Laser(void);
    Laser & operator = (Laser const & player);
    ~Laser(void);

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
