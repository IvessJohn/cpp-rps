#pragma once
#include <string>
using String = std::string;

//enum class EndgameChoices
//{
//	Play,
//	Reset,
//	Quit
//};

int ConvertShapeNameIntoShape(const String& shapeName);

String GetShapeName(const int shape);

int GetEndgameMenuChoiceAsInt(const String& strChoice);