#include <string>
#include "Gameplay.h"

Gameplay::Gameplay(const string& score)
{
	this->score = score;
}

string Gameplay::getScore() const
{
	return score;
}