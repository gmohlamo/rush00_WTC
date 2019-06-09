#ifndef __GAME__H
#define __GAME__H

#include "../view/View.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Laser.hpp"

#define LASERS 1024
#define ENEMIES 64
#define PLAYER '>' | COLOR_GREEN
#define ENEMY '<' | COLOR_BLUE
#define LASER '-' | COLOR_RED

class Game {
	public:
	Game(void);
	Game(Game const &);
	Game const & operator = (Game const & rhs) const;
	~Game(void);
	void	Play(void);
	private:
	View	_view;
	Player	_player;
	Enemy	_enemy[ENEMIES];
	bool	_enemies[ENEMIES];
	Laser	_laser[LASERS];
	bool	_lasers[LASERS];
};

#endif
