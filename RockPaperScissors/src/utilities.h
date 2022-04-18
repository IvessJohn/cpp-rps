#pragma once
#include <string>
using String = std::string;

template<typename T>
void PrintLine(T value);

template<typename T>
String Prompt(T prompt);

int ConvertShapeNameIntoShape(String shapeName);