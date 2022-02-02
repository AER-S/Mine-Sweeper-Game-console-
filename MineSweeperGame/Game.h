#pragma once
#include "Land.h"

class Game
{
	Land* land;
	bool run;
	int Askfor(char _index);

public:
	Game(int _width, int _height, int _mines);
	void GameStart();
	Coordinates AskForCoordinates();
	void OpenPosition(Coordinates _coordinates);
	bool AllRevealed();
	bool MinesRevealed();
	void StopRunning();
	void PrintWin();
	void PrintLose();
	void RevealMines();
	void ShowLand();
	bool IsRunning();
	~Game();
};

