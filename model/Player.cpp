#include "./Player.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

Player::Player(View * view, char c) //pass window we working on  y and  x value we will start on and character player 
{
    this->yLoc = 1; // y location in win
    this->xLoc = 1;
    this->character = c;
    this->view = view;
    getmaxyx(this->view->getWindow(), this->yMax, this->xMax);
}

Player::Player(Player const & player) {
	*this = player;
}

Player const & Player::operator=(Player const & rhs) const {
	return(rhs);
}

Player::Player(void) {
}

Player::~Player(void) {
}

void Player::mvup()
{
    //substract from y location
    yLoc--;
    if(yLoc < 1) 
    yLoc = 1;
}

void Player::mvdown()
{
    yLoc++;
    if(yLoc >yMax-2) 
    yLoc = yMax -2;
}

void Player::mvright()
{
    xLoc++;
    if(xLoc > xMax-2)
    xLoc= xMax -2;
}

void Player::mvleft()
{
    xLoc--;
    if(xLoc < 1)
    xLoc= 1;

}

int Player::getxloc(void) {
	return (this->xLoc);
}

int Player::getyloc(void) {
	return (this->yLoc);
}

int Player::getmv()
{
    int	choice = wgetch(this->view->getWindow());
    switch(choice)
    {
     case KEY_UP:
        mvup();
        break; 
     case KEY_DOWN:
        mvdown();
        break; 
     case KEY_LEFT:
        mvleft();
        break; 
     case KEY_RIGHT:
        mvright();
        break;
    default:
        break;
    }
    this->display();
    return choice;
}

void Player::display()
{
    mvwaddch(this->view->getWindow(), this->yLoc, this->xLoc, '>');
    //waddch(this->view->getWindow(), '>');
    //exit(0);
    //this->view->render(this->yLoc, this->xLoc, character);
}
