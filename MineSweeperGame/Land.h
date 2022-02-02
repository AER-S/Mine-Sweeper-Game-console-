#pragma once
#include "Portion.h"

struct Coordinates
{
	int x;
	int y;
};

class Land
{
	Portion** land;
	Coordinates* mines;
	int width;
	int height;
	int minesNumber;
	bool minesRevealed;
	int portionRevealed;
	

	void MakePortions();
	void PlantMines();
	void RevealMines();

public:
	Land(int _width, int _height, int _mines);
	void OpenPortion(int _xPos, int _yPos);
	void PrintTheLand();
	bool MinesRevealed();
	bool AllRevealed();
	int GetRevealed();
	~Land();
};




