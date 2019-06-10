#include "./Game.hpp"
#include <unistd.h>

Game::Game(View *view) {
	time_t t;
	srand((unsigned) time(&t));
	this->_view = view;
	this->_player = new Player(this->_view, '>');
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

Game::Game(void) {
	time_t t;
	srand((unsigned) time(&t));
	this->_view = new View();
	this->_player = new Player(this->_view, '>');
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
	wrefresh(this->_view->getWindow());
	endwin(); //close the ncurses window
	std::cout << "game over" << std::endl;
	std::cout << "thank you for playing with us!" << std::endl;
}

Game    const & Game::operator = (Game const & rhs) const{
        return (rhs);
}

void	Game::updateEnemies(int pos) {
	this->_enemy[pos]->mv();

	if (this->_enemy[pos]->getxloc() < 0) {
		delete this->_enemy[pos];
		this->_enemies[pos] = false;
	}
}

void	Game::newEnemy(int pos) {
	this->_enemy[pos] = new Enemy(this->_view, '<');
	this->_enemies[pos] = true;
}

void	Game::checkCollide(void) {
	int itr = 0;
	int itr2;
	while (itr < LASERS) {
		if (this->_lasers[itr] == true) {
			itr2 = 0;
			while (itr2 < ENEMIES) {
				if (this->_enemies[itr2] == true) {
					if (this->_laser[itr]->getxloc() == this->_enemy[itr2]->getxloc() && (this->_laser[itr]->getyloc() == this->_enemy[itr2]->getyloc())) {
						this->_lasers[itr] = false;
						this->_enemies[itr2] = false;
						delete this->_enemy[itr2];
					}
				}
				itr2++;
			}
		}
		itr++;
	}
}

void	Game::Play(void) {
	usleep(40000);
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
	this->checkCollide();
	int posE = 0;
	while(posE < ENEMIES) {
		if (this->_enemies[posE] == true) {
			this->updateEnemies(posE); //update enemy positions
		} else {
			this->newEnemy(posE); //create a new enemy when the last one had fallen
		}
		
		posE++;
	}
	int posL = 0;
	while(posL < LASERS) {
		if (this->_lasers[posL] == true) {
			this->_laser[posL]->mv(); //update projectile position
			if (this->_laser[posL]->getxloc() > this->_view->getMaxX()) {
				delete this->_laser[posL];
				this->_lasers[posL] = false;
			}
		}
		posL++;
	}
	refresh();
	this->_view->update();
}
