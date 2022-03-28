#include "utils.h"
#include <iostream>

namespace UTILS
{
	int CheckUserInput()
	{
		double userInput;

		while (!(std::cin >> userInput) && std::cin.get() != '\n')
		{
			std::cout << "Error, connected with input!Try to input data again: ";
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		return (int)userInput;
	}
}