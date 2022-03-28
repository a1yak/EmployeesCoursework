#pragma once
using namespace std;
class IHumanBeing
{
	virtual void Display()const = 0;
	virtual void CleareBuffer() = 0;
	virtual void Change() = 0;
};