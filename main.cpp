#include "view/View.hpp"
#include "model/Game.hpp"

int		main(void) {
	View	*view = new View();
	Game	*game = new Game(view);
	while (true)
		game->Play();
	//delete game;
	return(0);
}
