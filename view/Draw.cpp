#include "Draw.hpp"

Draw::Draw(void) {
	initscr();
	cbreak();
	noecho();
}

Draw::~Draw(void) {
}

Draw::Draw(Draw const & obj) {
	*this = obj;
}

Draw	&	Draw::operator = (Draw const &){
	return (*this);
}
