#include "src/rps.h"

#include <iostream>
#include <string>
using String = std::string;

int ConvertShapeNameIntoShape(String shapeName)
{
	return rps::_Rock;
}

String GetShapeName(int shape)
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