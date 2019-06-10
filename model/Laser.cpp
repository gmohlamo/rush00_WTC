#include"./Laser.hpp"
#include <unistd.h>

Laser::Laser(View *view, Player * owner, char c) {
	this->character = c;
	this->view = view;
	this->p_owner = owner;
	this->e_owner = NULL;
	this->direction = RIGHT;
	this->xLoc = owner->getxloc();
	this->yLoc = owner->getyloc();
}

Laser::Laser(View *view, Enemy * owner, char c) {
	this->character = c;
	this->view = view;
	this->e_owner = owner;
	this->p_owner = NULL;
	this->direction = LEFT;
}

Laser::Laser(void) {
	this->character = DEFAULT_LASER;
	this->e_owner = NULL;
	this->e_owner = NULL;
	this->direction = ERROR;
}

Laser const & Laser::operator = (Laser const & rhs) const {
	return(rhs);
}

Laser::Laser(Laser const & lsr){
	*this = lsr;
}

Laser::~Laser(void) {
}

void	Laser::mvleft(void) {
	mvwaddch(this->view->getWindow(), this->yLoc, this->xLoc, ' ');
	this->xLoc--;
}

void	Laser::mvright(void) {
	mvwaddch(this->view->getWindow(), this->yLoc, this->xLoc, ' ');
	this->xLoc++;
}

void	Laser::display() {
	mvwaddch(this->view->getWindow(), this->yLoc, this->xLoc, '-');
}

int	Laser::getxloc(void) {
	return(this->xLoc);
}

int	Laser::getyloc(void) {
	return(this->yLoc);
}

void	Laser::mv(void) {
	if (this->p_owner != NULL) {
		this->mvright();
	} else {
		this->mvleft();
	}
	this->display();
}
