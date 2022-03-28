#pragma once
#include "IHumanBeing.h"
#include <iostream>
using namespace std;
class Man : virtual public IHumanBeing
{
	virtual void Display()const = 0;
	
	
	virtual void Change() = 0;
public:
	void CleareBuffer()
	{
		if (char(cin.peek()) == '\n')
			cin.ignore();
		if (cin.fail())
		{
			std::cin.clear();
			cin.ignore(32767, '\n');
		}
	}
};