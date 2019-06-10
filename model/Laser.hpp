#ifndef __LASER__
#define __LASER__
#include <string>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <ctime>
#include "../view/View.hpp"
#include "./Player.hpp"
#include "./Enemy.hpp"
#define DEFAULT_LASER '-'
#define LEFT 1
#define RIGHT 2
#define	ERROR 0

class Laser{

    public:
    Laser(View * view, Player * owner, char c);
    Laser(View * view, Enemy * owner, char c);
    Laser(Laser const & player);
    Laser(void);
    Laser const & operator = (Laser const & player) const;
    ~Laser(void);

    void mvleft();
    void mvright();
    void shoot();
    void display();
    int  getxloc(void);
    int  getyloc(void);
    void mv();

    private:
    int	direction;
    bool onScreen;
    View * view;
    Player * p_owner;
    Enemy * e_owner;
    int xLoc, yLoc, xMax, yMax;//contain player location
    char character; //player

};
#endif
