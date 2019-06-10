#include "./Enemy.hpp"

Enemy::Enemy(View * view,char c) //pass window we working on  y and  x value we will start on and character player 
{
    int winMaxY, winMaxX;
    this->view = view;
    getmaxyx(this->view->getWindow(), winMaxY, winMaxX);
    this->yLoc = rand() % winMaxY; // y location in win
    this->xLoc = winMaxX - 1; //initially starts on the other end of the screen
    this->character = c;
    this->isAlive = true; //the units will be created dynamically and each wave will have an array of these
}

Enemy::Enemy(Enemy const & enemy) {
	*this = enemy;
}

Enemy const & Enemy::operator = (Enemy const & rhs) const {
	return(rhs);
}

Enemy::~Enemy(void) {
}

void Enemy::mvup()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
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

void Enemy::shoot() {
}

void Enemy::display()
{
	mvwaddch(this->view->getWindow(), this->yLoc, this->xLoc, '<');
}

int Enemy::getxloc(void) {
	return(this->xLoc);
}

int Enemy::getyloc(void) {
	return(this->yLoc);
}

void Enemy::mv(void) {
	mvleft();
	this->display();
}
