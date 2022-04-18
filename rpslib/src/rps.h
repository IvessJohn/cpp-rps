#pragma once

void ShowTestMessage();

namespace rps
{
	enum Outcomes
	{
		_Loss = -1,
		_Draw = 0,
		_Win = 1
	};

	enum Shapes
	{
		_Rock,
		_Paper,
		_Scissors
	};

	int Battle(Shapes playerShape, Shapes opponentShape);
}
