#include "src/rps.h"
#include "utilities.h"

#include <iostream>
#include <string>
#include <stdlib.h>
using String = std::string;

template<typename T>
void PrintLine(T value)
{
	std::cout << value << std::endl;
}

void PrintLine()
{
	PrintLine("");
}

template<typename T>
String Prompt(T prompt)
{
	PrintLine(prompt);
	String input;
	std::cin >> input;
	return String(input);
}

int main()
{
#pragma region Initializing_variables
	bool is_playing = true;

	int wins = 0;
	int losses = 0;
	int draws = 0;
#pragma endregion
	while (is_playing)
	{
		// Prompt player input
		String playerShapeName = Prompt("Input your choice (`rock`, `paper`, `scissors`):");
		int playerShape = ConvertShapeNameIntoShape(playerShapeName);

		// Computer chooses its shape
		int computerShape = rand() % (rps::_Shapes_MAX + 1);
		std::cout << "Opponent chooses: " << GetShapeName(computerShape) << std::endl;
		
		// Determine a winner
		int outcome = rps::Battle(rps::Shapes(playerShape), rps::Shapes(computerShape));

		// Add score
		PrintLine();
		switch (outcome)
		{
			case rps::_Win:
				PrintLine("WIN!");
				wins++;
				break;

			case rps::_Draw:
				PrintLine("Draw.");
				draws++;
				break;

			case rps::_Loss:
				PrintLine("Loss!");
				losses++;
				break;
		}

		

#pragma region Outcome
		PrintLine();
		PrintLine("SUMMARY");
		std::cout << "Wins: " << wins << std::endl;
		std::cout << "Losses: " << losses << std::endl;
		std::cout << "Draws: " << draws << std::endl;
		std::cout << std::endl;

		PrintLine("Enter one the the commands:");
		PrintLine("[play] - play again");
		PrintLine("[reset] - reset score and play");
		PrintLine("[exit] - exit the game");
		
#pragma endregion Show outcome and offer to continue
	}
}
