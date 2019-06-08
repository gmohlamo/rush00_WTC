#ifndef	DRAW_H
# define DRAW_H

#include <ncurses.h>

class Draw {
	public:
	Draw(void);
	Draw(Draw const & obj);
	Draw & operator = (Draw const &);
	~Draw(void);
	private:
	WINDOW*	_window;
	int	_offsetx;
	int	_offsety;
};

#endif
