#include "View.hpp"

int	main(void) {
	View view;
	move(0, 0);
	printw("Type something");
	refresh();
	view.input();
	view.render(5, 0, view.getCh());
	view.input();
	return(0);
}
