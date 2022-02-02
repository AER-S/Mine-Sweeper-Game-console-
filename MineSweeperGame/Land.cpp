#include "Land.h"
#include <stdlib.h>
#include <time.h>
//#include <cstdlib>
//#include <ctime>
#include <iostream>


void Land::MakePortions()
{
	land = new Portion * [height];
	for (int i = 0; i < height; i++)
	{
		land[i] = new Portion[width];
	}
}

void Land::PlantMines()
{
	for (int i = 0; i < minesNumber; i++)
	{
		
		srand(time(0)+i);
		int x = rand() % width;
		srand(x+i+3568);
		int y = rand() % height;
		mines[i].x = x;
		mines[i].y = y;
 		land[y][x].MakeMine();
		if (x - 1 >= 0 && y - 1 > 0) land[y - 1][x - 1].IncreaseMinesAround();
		if (x - 1 >= 0) land[y][x - 1].IncreaseMinesAround();
		if (y - 1 >= 0) land[y - 1][x].IncreaseMinesAround();
		if (x + 1 < height) land[y][x + 1].IncreaseMinesAround();
		if (y + 1 < width) land[y + 1][x].IncreaseMinesAround();
		if (x + 1 < height && y + 1 < width) land[y + 1][x + 1].IncreaseMinesAround();
		if (x - 1 >= 0 && y + 1 < width) land[y + 1][x - 1].IncreaseMinesAround();
		if (x + 1 < height && y - 1 >= 0) land[y - 1][x + 1].IncreaseMinesAround();
	}
}

void Land::RevealMines()
{
	for (int i = 0; i < minesNumber; i++)
	{
		land[mines[i].y][mines[i].x].MakeVisible();
	}
}

Land::Land(int _width, int _height, int _mines)
{
	width = _width;
	height = _height;
	minesNumber = _mines;
	mines = new Coordinates[minesNumber];
	minesRevealed = false;
	MakePortions();
	PlantMines();
}

void Land::OpenPortion(int _xPos, int _yPos)
{
	if(land[_yPos][_xPos].GetMinesAround()=='0')
	{
		land[_yPos][_xPos].MakeVisible();
		if (_xPos - 1 >= 0 && _yPos - 1 > 0)
		{
			if(!land[_yPos-1][_xPos-1].IsVisible())OpenPortion(_xPos - 1, _yPos - 1);
		}
		if (_xPos - 1 >= 0)
		{
			if(!land[_yPos][_xPos-1].IsVisible()) OpenPortion(_xPos - 1, _yPos);
		}
		if (_yPos - 1 >= 0)
		{
			if(!land[_yPos-1][_xPos].IsVisible())OpenPortion(_xPos, _yPos - 1);
		}
		if (_xPos + 1 < height)
		{
			if (!land[_yPos][_xPos + 1].IsVisible()) OpenPortion(_xPos + 1, _yPos);
		}
		if (_yPos + 1 < width)
		{
			if (!land[_yPos + 1][_xPos].IsVisible()) OpenPortion(_xPos, _yPos + 1);
		}
		if (_xPos + 1 < height && _yPos + 1 < width)
		{
			if (!land[_yPos + 1][_xPos + 1].IsVisible()) OpenPortion(_xPos + 1, _yPos + 1);
		}
		if (_xPos - 1 >= 0 && _yPos + 1 < width)
		{
			if (!land[_yPos + 1][_xPos - 1].IsVisible()) OpenPortion(_xPos - 1, _yPos + 1);
		}
		if(_xPos + 1 < height && _yPos - 1 >= 0)
		{
			if (!land[_yPos - 1][_xPos + 1].IsVisible()) OpenPortion(_xPos + 1, _yPos - 1);
		}
	}

	else if (land[_yPos][_xPos].GetMinesAround() == '*')
	{
		RevealMines();
		minesRevealed = true;
	}

	else
	{
		land[_yPos][_xPos].MakeVisible();
		
	}
	portionRevealed++;
}

void Land::PrintTheLand()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << "|" << ((land[i][j].IsVisible()) ? (land[i][j].GetMinesAround()) : ' ');
			//std::cout << "| " << land[i][j].GetMinesAround() << " ";
		}
		std::cout << "|\n";
	}
}

bool Land::MinesRevealed()
{
	return minesRevealed;
}

bool Land::AllRevealed()
{
	return (width * height == portionRevealed + minesNumber);
}

int Land::GetRevealed()
{
	return portionRevealed;
}

Land::~Land()
{
	for (int i = 0; i < height; i++)
	{
		delete[] land[i];
	}
	delete[] land;
	land = nullptr;
	delete[] mines;
	mines = nullptr;
}

