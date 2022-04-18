#include "rps.h"

#include <iostream>

void ShowTestMessage()
{
	std::cout << "rps.cpp test active!" << std::endl;
}

namespace rps
{
	int Battle(const Shapes playerShape, const Shapes opponentShape)
	{
		if (playerShape == opponentShape)
			return _Draw;

		if (playerShape == _Rock)
		{
			if (opponentShape == _Paper)
				return _Loss;
			else
				return _Win;
		}

		if (playerShape == _Paper)
		{
			if (opponentShape == _Scissors)
				return _Loss;
			else
				return _Win;
		}

		//if (playerShape == _Scissors)
		//{
		if (opponentShape == _Rock)
			return _Loss;
		//else
		return _Win;
		//}
	}
}