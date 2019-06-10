#include "./Game.hpp"
#include <unistd.h>

Game::Game(void) {
	time_t t;
	srand((unsigned) time(&t));
	this->_view = new View();
	this->_player = new Player(this->_view, '>');
	/*unsigned int itr = 0;
	while(itr < LASERS) {
		this->_enemies[itr] = false;
		itr++;
	}
	itr = 0;
	while(itr < ENEMIES) {
		this->_enemies[itr] = false;
		itr++;
	}*/
}

Game::Game(Game const & game) {
	*this = game;
}

Game::~Game(void) {
	int posL = 0;
	while (posL < LASERS) {
		delete this->_laser[posL];
		posL++;
	}
	int posE = 0;
	while (posE < ENEMIES) {
		delete this->_enemy[posE];
		posE++;
	}
	delete _view;
	delete _player;
	endwin(); //close the ncurses window
	std::cout << "game over" << std::endl;
	std::cout << "thank you for playing with us!" << std::endl;
}

Game    const & Game::operator = (Game const & rhs) const{
        return (rhs);
}

void	Game::updateEnemies(int pos) {
	this->_enemy[pos]->mv();
}

void	Game::updateLasers(int pos) {
	if (this->_laser[pos]->getxloc() < 0 || this->_laser[pos]->getxloc() > this->_view->getMaxX()) {
		delete this->_laser[pos];
		this->_lasers[pos] = false;
	} else {
		this->_laser[pos]->mv();
	}
	//endwin(); //tty fix
	//exit(0);
}

void	Game::newEnemy(int pos) {
	this->_enemy[pos] = new Enemy(this->_view, '<');
	this->_enemies[pos] = true;
}

void	Game::Play(void) {
	usleep(30000);
	clear();
	int choice = this->_player->getmv();
	if (choice == 32) {
		int itr = 0;
		while (itr < LASERS) {
			if (this->_lasers[itr] == false) {
				this->_laser[itr] = new Laser(this->_view, this->_player, '-');
				this->_lasers[itr] = true;
				break;
			}
			itr++;
		}
	}
	//enter enemy AI method here
	int posE = 0;
	while(posE < ENEMIES) {
		if (this->_enemies[posE] == true) {
			this->updateEnemies(posE); //update enemy positions
		} else {
			this->newEnemy(posE); //create a new enemy when the last one had fallen
		}
		posE++;
	}
	/*int posL = 0;
	while(posL < LASERS) {
		if (this->_lasers[posL] == true) {
			this->updateLasers(posL); //update projectile position
		}
		posL++;
	}*/
	this->_view->update();
}
