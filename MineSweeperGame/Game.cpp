#include "Game.h"
#include <iostream>

Game::Game(int _width, int _height, int _mines)
{
	land = new Land(_width, _height, _mines);
	run = true;
}

void Game::GameStart()
{
	std::cout << std::endl << std::endl;
	std::cout << "   ------------------------------\n";

	std::cout << "   |\t    GAME STARTS\t\t|\n";

	std::cout << "   ------------------------------\n";
}

Coordinates Game::AskForCoordinates()
{
	Coordinates coor;
	std::cout << "Enter the X and Y Coordinates:\n";
	std::cin >>coor.x;
	std::cin >> coor.y;
	return coor;
}

void Game::OpenPosition(Coordinates _coordinates)
{
	land->OpenPortion(_coordinates.x, _coordinates.y);
}

bool Game::AllRevealed()
{
	return  land->AllRevealed();
}

bool Game::MinesRevealed()
{
	return land->MinesRevealed();
}

void Game::PrintWin()
{
	std::cout << std::endl << std::endl;
	std::cout << "   ------------------------------\n";

	std::cout << "   |\t    GAME WON\t\t|\n";

	std::cout << "   ------------------------------\n";
}

void Game::PrintLose()
{
	std::cout << std::endl << std::endl;
	std::cout << "   ------------------------------\n";

	std::cout << "   |\t    GAME Lost\t\t|\n";

	std::cout << "   ------------------------------\n";
}

void Game::ShowLand()
{
	land->PrintTheLand();
}

bool Game::IsRunning()
{
	return run;
}

Game::~Game()
{
	delete land;
}
