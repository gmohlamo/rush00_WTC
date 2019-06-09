#include "Game.hpp"

Game::Game(void) {
	this->_view = View();
	this->_player = Player(&this->_view, char(PLAYER));
	unsigned int itr = 0;
	while(itr < LASERS) {
		this->_enemies[itr] = false;
		itr++;
	}
	itr = 0;
	while(itr < ENEMIES) {
		this->_enemies[itr] = false;
		itr++;
	}
}

Game::Game(Game const & game) {
	*this = game;
}

Game    const & Game::operator = (Game const & rhs) const{
        return (rhs);
}

void	Game::Play(void) {
	this->_view.update();
	this->_player.getmv();
	//enter enemy AI method here
}
