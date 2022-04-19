#include "src/rps.h"
#include "utilities.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
using String = std::string;

template<typename T>
void Print(const T& value, bool endline = true)
{
	std::cout << value;
	if (endline)
		std::cout << std::endl;
}

void PrintLine()
{
	Print("");
}

template<typename T>
String Prompt(const T& prompt, bool endline = false)
{
	// Prompt
	Print(prompt, endline);

	// Get input
	String input;
	std::cin >> input;

	return String(input);
}

std::default_random_engine gen(time(NULL));
std::uniform_int_distribution<int> dist(1, 3);

int main()
{
	bool is_playing = true;

	int round = 1;
	int wins = 0;
	int losses = 0;
	int draws = 0;

	while (is_playing)
	{
		std::cout << "ROUND " << round << std::endl;

		// Prompt player input
		int playerShape = -1; // -1 = unset/invalid value
		while (playerShape == -1)
		{
			String playerShapeName = Prompt(
				"Input your choice (`r` - rock, `p` - paper, `s` - scissors): ");
			playerShape = ConvertShapeNameIntoShape(playerShapeName);
		}

		// Computer chooses its shape
		int computerShape = dist(gen) % (rps::_Shapes_MAX + 1);
		
		// Print out the player's and the computer's shapes
		PrintLine();
		std::cout << "You choose: " << GetShapeName(playerShape) << std::endl;
		std::cout << "Opponent chooses: " << GetShapeName(computerShape) << std::endl;

		// Determine a winner
		int outcome = rps::Battle(rps::Shapes(playerShape), rps::Shapes(computerShape));

		// Add score
		PrintLine();
		switch (outcome)
		{
		case rps::_Win:
			Print("WIN!");
			wins++;
			break;

		case rps::_Draw:
			Print("Draw.");
			draws++;
			break;

		case rps::_Loss:
			Print("Loss!");
			losses++;
			break;
		}
		round++;


		Print("\n---SUMMARY---");
		std::cout << "Wins: " << wins << std::endl;
		std::cout << "Losses: " << losses << std::endl;
		std::cout << "Draws: " << draws << std::endl;

		// Prompt the user until his answer is one of: `play`, `reset`, `exit`
		bool is_waiting_for_action = true;
		while (is_waiting_for_action)
		{
			String continueChoice = Prompt(R"(
Enter one the the commands:
[play] - play again
[reset] - reset score and play
[exit] - exit the game)", true);

			if (continueChoice == "p" || continueChoice == "play")
			{
				is_waiting_for_action = false;
			}
			else if (continueChoice == "r" || continueChoice == "reset")
			{
				round = 1;
				wins = 0;
				losses = 0;
				draws = 0;

				is_waiting_for_action = false;
			}
			else if (continueChoice == "e" || continueChoice == "exit")
			{
				is_waiting_for_action = false;
				is_playing = false;
			}
			// If the input is invalid, keep prompting
		}
		Print("-------------------------------\n");
	}
}
