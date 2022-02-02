#pragma once
#include "Land.h"

class Game
{
	Land* land;
	bool run;

public:
	Game(int _width, int _height, int _mines);
	void GameStart();
	Coordinates AskForCoordinates();
	void OpenPosition(Coordinates _coordinates);
	bool AllRevealed();
	bool MinesRevealed();
	void PrintWin();
	void PrintLose();
	void ShowLand();
	bool IsRunning();
	~Game();
};

