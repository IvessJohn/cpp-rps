#include "src/rps.h"
#include "utilities.h"

#include <iostream>
#include <string>
using String = std::string;

template<typename T>
void PrintLine(T value)
{
	std::cout << value << std::endl;
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
#pragma region Choose_Shape
		String playerShapeName = Prompt("Input your choice (`rock`, `paper`, `scissors`) :");
		int playerShape = ConvertShapeNameIntoShape(playerShapeName);
#pragma endregion Receiving player input

#pragma region Play
		// Computer chooses its shape

		// Determine a winner

		// Add score
		
#pragma endregion All the behind-the-scenes game code

#pragma region Outcome
		PrintLine("------");
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
