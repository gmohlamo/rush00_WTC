#include <ncurses.h>
#include <string>
#include <iostream>
// using namespace std;

int main(int argc, char **argv)
{
    //initializes the screen
    //sets up memory and clears the  screen
    initscr();
    cbreak();//escape

    raw();
    noecho();//hides input text (ctrl+ c)


    int height, width, start_y, start_x;
    height = 10; 
    width = 20;
    start_y = start_x = 10;
    
    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);//integer value // for border use
    
     //specfic window transfer
     mvwprintw(win, 1, 1,"this is my box");//(1,1 is to shift location of text)
     wrefresh(win);

    //whats for user input, returns int value of that key
     getch();
     getch();


    endwin();
    //deallocates mem ory and ends ncurses
    return 0;
}