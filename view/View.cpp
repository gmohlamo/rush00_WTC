#include "View.hpp"

//does not yet handle window size change

View::View(void) {
	initscr(); //initialize terminal curses mode
	//cbreak();
	raw(); //See the man on this function. It prevents the tty driver from buffering typed
	//characters until a newline or line carriage is typed.
	noecho(); //prevent keys being entered from being echoed to the screen
	keypad(stdscr, TRUE); //enable keyboard event capturing
	getmaxyx(stdscr, this->_windowVert, this->_windowHor); //get thew maximum width and height values for the game.
	curs_set(FALSE); //prevent the cursor from being displayed
	box(this->_window, 0, 0); //create a box around the window
	this->_window = newwin(this->_windowVert, this->_windowHor, 0, 0); //allocate memory and gather information on the window.
}

View::~View(void) {
	endwin();
}

View::View(View const & obj) {
	*this = obj;
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
	move(y, x);
	addch(ch);
}

void	View::input(void) {
	this->_ch = getch();
}

chtype	View::getCh(void) {
	return(this->_ch);
}
