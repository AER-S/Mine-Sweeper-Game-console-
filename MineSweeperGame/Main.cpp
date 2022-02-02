#include "Game.h"
#include "GameEngine.h"

int main()
{
	Game* game = nullptr;
	GameEngine::PlayGame(game);
	delete game;
}