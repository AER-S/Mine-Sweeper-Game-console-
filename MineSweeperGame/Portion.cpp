#include "Portion.h"

Portion::Portion()
{
	minesAround = '0';
	visible = false;
}

void Portion::IncreaseMinesAround()
{
	if(minesAround!='*')minesAround++;
}

void Portion::MakeVisible()
{
	if(!visible) visible = true;
}

void Portion::MakeMine()
{
	minesAround = '*';
}

bool Portion::IsVisible() const
{
	return visible;
}

char Portion::GetMinesAround() const
{
	return minesAround;
}

