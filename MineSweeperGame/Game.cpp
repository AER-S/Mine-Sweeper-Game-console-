#include "Game.h"
#include <iostream>
#include <string>

int Game::Askfor(char _index)
{
	int input = 0;
	std::string sInput = "0";
	do
	{
		std::cout << "Enter "<< _index << " position: ";
		std::getline(std::cin, sInput);
		sInput = "0" + sInput;
		//std::cout << sInput << std::endl;
		std::string::size_type sz;
		input = std::stoi(sInput,&sz);
		//std::cout << input << std::endl;
		if (input > 9 || input <= 0) std::cout << "Invalid Input! Retry!\n";
	} while (input > 9 || input <= 0);
	return input;
}

Game::Game(int _width, int _height, int _mines)
{
	land = new Land(_width, _height, _mines);
	run = true;
}

void Game::GameStart()
{
	//std::cout << std::endl << std::endl;
	std::cout << "   ------------------------------\n";

	std::cout << "   |\t    GAME STARTS\t\t|\n";

	std::cout << "   ------------------------------\n";
}

Coordinates Game::AskForCoordinates()
{
	Coordinates coor;
	std::cout << "Enter the X and Y Coordinates:\n";
	coor.x = Askfor('x');
	coor.y = Askfor('y');
	return coor;
}

void Game::OpenPosition(Coordinates _coordinates)
{
	land->OpenPortion(_coordinates.x-1, _coordinates.y-1,0);
}

bool Game::AllRevealed()
{
	return  land->AllRevealed();
}

bool Game::MinesRevealed()
{
	return land->MinesRevealed();
}

void Game::StopRunning()
{
	run = false;
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

void Game::RevealMines()
{
	land->RevealMines();
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
