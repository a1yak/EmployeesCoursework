#pragma once
#include <string>
#include "Man.h"
class Employee : public Man
{
private:
	string _fullName;
	int _age;
	int _ID;
public:
	Employee();
	int GetID()const;
	string GetFullname() const;
	int GetAge() const;
	void Change() override;
	void Display() const override;
};
