#pragma once
class Portion
{
	char minesAround;
	bool visible;

public:
	Portion();
	void IncreaseMinesAround();
	void MakeVisible();
	void MakeMine();
	char GetMinesAround() const;
	bool IsVisible() const;
};

