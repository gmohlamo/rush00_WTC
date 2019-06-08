#include "Draw.hpp"

Draw::Draw(void) {
	initscr(); //initialize terminal curses mode
	//cbreak();
	raw(); //See the man on this function. It prevents the tty driver from buffering typed
	//characters until a newline or line carriage is typed.
	noecho(); //prevent keys being entered from being echoed to the screen
	keypad(stdscr, TRUE); //enable keyboard event capturing
	getmaxyx(stdscr, this->_windowVert, this->_windowHor); //get thew maximum width and height values for the game.
	this->_window = newwin(this->_windowVert, this->_windowHor, 0, 0); //allocate memory and gather information on the window.
}

Draw::~Draw(void) {
	endwin();
}

Draw::Draw(Draw const & obj) {
	*this = obj;
}

Draw	&	Draw::operator = (Draw const &){
	return (*this);
}

void	Draw::_moveCursor(int y, int x) {
	move(y, x);
}

void	Draw::draw(int y, int x, chtype const ch) {
	move(y, x);
	addch(ch);
}

void	Draw::input(void) {
	this->_ch = getch();
}

chtype	Draw::getCh(void) {
	return(this->_ch);
}
