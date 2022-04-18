#include "src/rps.h"

#include <iostream>
#include <string>
using String = std::string;

int ConvertShapeNameIntoShape(const String shapeName)
{
	if (shapeName == "r" || shapeName == "rock")
		return rps::_Rock;
	else if (shapeName == "p" || shapeName == "paper")
		return rps::_Paper;
	else if (shapeName == "s" || shapeName == "scissors")
		return rps::_Scissors;
	
	return -1;
}

String GetShapeName(const int shape)
{
	switch (shape)
	{
	case rps::_Rock:
		return "Rock";
		break;

	case rps::_Paper:
		return "Paper";
		break;

	case rps::_Scissors:
		return "Scissors";
		break;
	}

	return "UNDEFINED";
}


String GetEndgameMenuChoiceAsInt(String strChoice)
{
	return "";
}