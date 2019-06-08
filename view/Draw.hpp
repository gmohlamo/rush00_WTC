#ifndef	DRAW_H
# define DRAW_H

#include <ncurses.h>

class Draw {
	public:
	Draw(void);
	Draw(Draw const & obj);
	Draw & operator = (Draw const &);
	~Draw(void);
	void	draw(int y, int x, const chtype);
	void	input(void);
	private:
	WINDOW*	_window;
	chtype	_ch;
	int	_windowVert;
	int	_windowHor;
	void	_moveCursor(int y, int x);
};

#endif
