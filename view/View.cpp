#include "View.hpp"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

//does not yet handle window size change

View::View(void) {
	initscr(); //initialize terminal curses mode
	noecho(); //prevent keys being entered from being echoed to the screen
	cbreak();
	//raw(); //See the man on this function. It prevents the tty driver from buffering typed
	//characters until a newline or line carriage is typed.
	getmaxyx(stdscr, this->_windowVert, this->_windowHor); //get thew maximum width and height values for the game.
	//std::cout << this->_windowVert << " vertical." << std::endl << this->_windowHor << std::endl;
	//exit(0);
	this->_window = newwin(this->_windowVert - 2, this->_windowHor - 2, 1, 1); //allocate memory and gather information on the window.
	box(this->_window, 0, 0); //create a box around the window
	curs_set(false); //prevent the cursor from being displayed
	//wtimeout(this->_window, 1500); //wait for user input but return ERR should the user fail to give any input
	keypad(this->getWindow(), true); //enable keyboard event capturing
	refresh();
	wrefresh(this->_window);
	nodelay(this->_window, true);
	//sleep(2);
	//endwin();
	//exit(0);
}

View::~View(void) {
	endwin();
}

View::View(View const & obj) {
	*this = obj;
}

WINDOW *View::getWindow(void) {
	return (this->_window);
}

View	const &	View::operator = (View const & operand) const{
	return (operand);
}

int	View::getMaxY(void) const {
	return(this->_windowVert);
}

int	View::getMaxX(void) const {
	return(this->_windowHor);
}

void	View::_moveCursor(int y, int x) {
	move(y, x);
}

void	View::render(int y, int x, chtype const ch) {
	wmove(this->getWindow(), y, x);
	waddch(this->getWindow(), ch);
}

void	View::_input(void) {
	this->_ch = getch();
}

void	View::update(void) {
	refresh();
	wrefresh(this->_window);
	//sleep(2);
	//endwin();
	//exit(0);
}

chtype	View::getCh(void) {
	this->_input();
	return(this->_ch);
}
