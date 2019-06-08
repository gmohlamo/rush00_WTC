#include "enemy.hpp"

Enemy::Enemy(WINDOW *win, int y,int x,char c) //pass window we working on  y and  x value we will start on and character player 
{
    curwin = win;//capture window in
    yLoc =y; // y location in win
    xLoc = x;
    getmaxyx(curwin,yMax,xMax);//
    keypad(curwin,true);//arrow keys use
    character = c;
}

void Enemy::mvup()
{
    //substract from y location
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if(yLoc < 1) 
    yLoc = 1;
}

void Enemy::mvdown()
{
    // mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc >yMax-2) 
    yLoc = yMax -2;
}

void Enemy::mvright()
{
    // mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
    xLoc= xMax -2;
}

void Enemy::mvleft()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
    xLoc= 1;

}

int Enemy::getmv()
{
    int choice = wgetch(curwin);
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

void Enemy::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);
}