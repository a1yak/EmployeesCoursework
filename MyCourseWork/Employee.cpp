#include "Employee.h"
#include <iostream>
#include "utils.h"

using namespace std;
Employee::Employee()
{
	bool isWorking = true;
	cout << "Information about person";
	cout << "\n\nEnter Person's name and surname: ";
	CleareBuffer();
	getline(cin, this->_fullName);
	cout << "\nEnter person's age: ";
	while (isWorking)
	{
		this->_age = UTILS::CheckUserInput();
		if (this->_age < 0)
		{
			cout << "\nWrong input, try again: ";
			this->_age = UTILS::CheckUserInput();
		}
		else isWorking = false;
	}
	cout << "\nEnter person's ID: ";
	this->_ID = UTILS::CheckUserInput();
}
void Employee::Change()
{
	cout << "\nEnter Person's name and surname: ";
	CleareBuffer();
	getline(cin, this->_fullName);
	cout << "\nEnter person's age: ";
	CleareBuffer();
	this->_age = UTILS::CheckUserInput();
	cout << "\nEnter person's ID: ";
	this->_ID = UTILS::CheckUserInput();
}
int Employee::GetID()const { return _ID; }
string Employee::GetFullname() const { return _fullName; }
int Employee::GetAge() const { return _age; }

void Employee::Display() const 
{
	cout << "\nID - " << _ID
		<< "\nFull name - " << _fullName
		<< "\nAge - " << _age << endl;
}