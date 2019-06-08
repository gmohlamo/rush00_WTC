#include "Draw.hpp"

int	main(void) {
	Draw drawer;
	move(0, 0);
	printw("Type something");
	refresh();
	drawer.input();
	drawer.draw(5, 0, drawer.getCh());
	drawer.input();
	return(0);
}
