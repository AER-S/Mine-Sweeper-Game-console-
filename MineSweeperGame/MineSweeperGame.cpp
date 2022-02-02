#include "Land.h"
#include <iostream>

int main()
{
	Land land(9, 9, 10);
	land.PrintTheLand();
	land.OpenPortion(2, 2);
	std::cout << std::endl;
	land.PrintTheLand();
	std::cout << land.GetRevealed();
}