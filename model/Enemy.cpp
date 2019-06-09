#include "Enemy.hpp"

Enemy::Enemy(View * view,char c) //pass window we working on  y and  x value we will start on and character player 
{
    yLoc =view->getMaxY() / 2; // y location in win
    xLoc = 0;
    character = c;
    this->view = view;
}

Enemy::Enemy(Enemy const & player) {
	*this = player;
}

void Enemy::mvup()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    //substract from y location
    yLoc--;
    if(yLoc < 1) 
    yLoc = 1;
}

void Enemy::mvdown()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    yLoc++;
    if(yLoc >yMax-2) 
    yLoc = yMax -2;
}

void Enemy::mvright()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
    xLoc= xMax -2;
}

void Enemy::mvleft()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
    xLoc= 1;

}

int Enemy::getmv(chtype choice)
{
	return(choice)
}

void Enemy::display()
{
    this->view->render(this->yLoc, this->xLoc, character);
}
