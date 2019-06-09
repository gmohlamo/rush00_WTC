#include "Player.hpp"

Player::Player(View * view,char c) //pass window we working on  y and  x value we will start on and character player 
{
    yLoc =view->getMaxY() / 2; // y location in win
    xLoc = 0;
    character = c;
    this->view = view;
}

Player::Player(Player const & player) {
	*this = player;
}

void Player::mvup()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    //substract from y location
    yLoc--;
    if(yLoc < 1) 
    yLoc = 1;
}

void Player::mvdown()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    yLoc++;
    if(yLoc >yMax-2) 
    yLoc = yMax -2;
}

void Player::mvright()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
    xLoc= xMax -2;
}

void Player::mvleft()
{
    this->view->render(this->yLoc, this->xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
    xLoc= 1;

}

int Player::getmv()
{
    int	choice = this->view->getCh();
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
    return choice;
}

void Player::display()
{
    this->view->render(this->yLoc, this->xLoc, character);
}
