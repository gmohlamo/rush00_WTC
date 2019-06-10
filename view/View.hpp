#ifndef	VIEW_H
# define VIEW_H

#include <ncurses.h>

//View class is basically the client which lets the user interact with the game
class View {
	public:
	View(void);
	View(View const & obj);
	View const & operator = (View const &) const;
	~View(void);
	void	render(int y, int x, const chtype);
	void	update(void);
	WINDOW	*getWindow(void);
	chtype	getCh(void);
	int	getMaxY(void) const;
	int	getMaxX(void) const;
	private:
	WINDOW*	_window;
	chtype	_ch;
	int	_windowVert;
	int	_windowHor;
	void	_moveCursor(int y, int x);
	void	_input(void);
};

#endif
