#include "Enemy.hpp"

Enemy::Enemy(View * view,char c) //pass window we working on  y and  x value we will start on and character player 
{
    this->yLoc =view->getMaxY() / 2; // y location in win
    this->xLoc = 0;
    this->character = c;
    this->isAlive = true; //the units will be created dynamically and each wave will have an array of these
    this->view = view;
}

Enemy::Enemy(Enemy const & enemy) {
	*this = enemy;
}

void Enemy::mvup()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    //substract from y location
    this->yLoc--;
    if(yLoc < 1) 
    yLoc = 1;
}

void Enemy::mvdown()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    this->yLoc++;
    if(yLoc >yMax-2) 
    this->yLoc = yMax -2;
}

void Enemy::mvleft()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    this->xLoc--;
    if(this->xLoc < 1)
    	this->isAlive = false;

}

int Enemy::getmv(chtype choice)
{
	return(choice);
}

void Enemy::display()
{
    this->view->render(this->yLoc, this->xLoc, character);
}
