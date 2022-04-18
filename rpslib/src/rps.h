#pragma once

void ShowTestMessage();

namespace rps
{
	enum Outcomes
	{
		_Loss = -1,
		_Draw = 0,
		_Win = 1,
		_Outcomes_MAX = _Win
	};

	enum Shapes
	{
		_Rock,
		_Paper,
		_Scissors,
		_Shapes_MAX = _Scissors
	};

	int Battle(const Shapes playerShape, const Shapes opponentShape);
}
