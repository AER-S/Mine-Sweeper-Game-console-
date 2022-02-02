#include "GameEngine.h"
#include <iostream>
#include <windows.h>

void GameEngine::Welcome()
{
	std::cout << "   ------------------------------\n";
	std::cout << "   |                            |\n";
	std::cout << "   |\tWELCOME TO Mine Sweeper\t|\n";
	std::cout << "   |                            |\n";
	std::cout << "   ------------------------------\n";
}

void GameEngine::Rules()
{
	std::cout << "RULES:\n";
	std::cout << "1. The land is divided into cells, with mines randomly distributed.\n";
	std::cout << "2. To win, you need to open all the cells.\n";
	std::cout << "3. The number on cell shows the number of mines adjacent to it.\n";
	std::cout << "4. Using the previous rule, determine the safe cells and the ones with mines.\n";
}

void GameEngine::HowToPlay()
{
	std::cout << "HOW TO PLAY:\n";
	std::cout << "1. User will inter x & y (coordinates where he wants to click)\n";
}

void GameEngine::AskForReplay(bool& _play)
{
	char input[80];
	do
	{
		std::cout << "Do you want to play again? (Y/N): ";
		std::cin.getline(input, 80);
		std::cin.ignore(std::numeric_limits<std::streamsize>::infinity(), '\n');
		if (input[0] != 'y' && input[0] != 'Y' && input[0] != 'N' && input[0] != 'n') std::cout << "Invalid Answer! Please answer with 'Y' or 'N'!\n";
	} while (input[0] != 'y' && input[0] != 'Y' && input[0] != 'N' && input[0] != 'n');
	switch (input[0])
	{
	case 'y':
	case 'Y':
		_play = true;
		break;
	case 'N':
	case 'n':
		_play = false;
		break;
	default:
		break;
	}
}

void GameEngine::SetColor(int _textCol, int _backCol)
{
	if ((_textCol % 16) == (_backCol % 16))_textCol++;
	_textCol %= 16; _backCol %= 16;
	unsigned short wAttributes = ((unsigned)_backCol << 4) | (unsigned)_textCol;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, wAttributes);
}

void GameEngine::PlayGame(Game* game)
{
	bool play;
	do
	{
		game = new Game(9, 9, 10);
		while (game->IsRunning())
		{
			system("cls");
			Welcome();
			std::cout << std::endl;
			Rules();
			std::cout << std::endl;
			HowToPlay();
			std::cout << std::endl;
			game->GameStart();
			game->ShowLand();
			const Coordinates coordinates = game->AskForCoordinates();
			game->OpenPosition(coordinates);
			
			if(game->MinesRevealed())
			{
				game->StopRunning();
				game->ShowLand();
				game->PrintLose();
				break;
			}
			if(game->AllRevealed())
			{
				game->StopRunning();
				game->RevealMines();
				game->ShowLand();
				game->PrintWin();
			}
		}
		GameEngine::AskForReplay(play);			
	}
	while (play);
}
