#include "Game.h"
#include <iostream>

int main()
{
	Game* game = new Game(9, 9, 10);
	game->GameStart();
	game->ShowLand();
	Coordinates coord = game->AskForCoordinates();
	game->OpenPosition(coord);
	game->ShowLand();
	delete game;
}