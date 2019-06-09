#include"Laser.hpp"

Laser::Laser(View *view, Player * owner, char c) {
	this->character = c;
	this->view = view;
	this->p_owner = owner;
	this->e_owner = NULL;
	this->direction = RIGHT;
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

Laser::Laser(Laser const & lsr){
	*this = lsr;
}

Laser::~Laser(void) {
}

void	Laser::mvleft(void) {
	this->xLoc--;
}

void	Laser::mvright(void) {
	this->xLoc++;
}

void	Laser::display() {
	this->view->render(this->yLoc, this->xLoc, this->character);
}
