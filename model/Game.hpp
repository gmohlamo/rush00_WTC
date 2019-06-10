#ifndef __GAME__H
#define __GAME__H

#include "../view/View.hpp"
#include "./Enemy.hpp"
#include "./Player.hpp"
#include "./Laser.hpp"
#include <math.h>
#include <iostream>

#define LASERS 4096
#define ENEMIES 32

class Game {
	public:
	Game(void);
	Game(View *view);
	Game(Game const &);
	Game const & operator = (Game const & rhs) const;
	~Game(void);
	void	checkCollide(void);
	void	Play(void);
	void	updateLasers(int pos);
	void	updateEnemies(int pos);
	void	newEnemy(int pos);
	private:
	View	*_view;
	Player	*_player;
	Enemy	*_enemy[ENEMIES];
	bool	_enemies[ENEMIES];
	Laser	*_laser[LASERS];
	bool	_lasers[LASERS];
};

#endif
