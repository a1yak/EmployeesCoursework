#include "WorkerWithHourPay.h"
#include <iostream>
#include "Employee.h"
#include "utils.h"

using namespace std;
WorkerWithHourPay::WorkerWithHourPay():Employee()
{
	cout << "\nEnter Hour Pay: ";
	this->_hourPay = UTILS::CheckUserInput();
	cout << "\nEnter amount of Working hours per week: ";
	this->_amountOfHoursInWeek = UTILS::CheckUserInput();
}

void WorkerWithHourPay::Display() const
{
	Employee::Display();
	cout << "Hour Pay - " << _hourPay
		<< "\nAmount of working hours per week - " << _amountOfHoursInWeek << endl;

}

void WorkerWithHourPay::Change() //override
{
	Employee::Change();
	cout << "\nEnter Hour Pay: ";
	this->_hourPay = UTILS::CheckUserInput();
	cout << "\nEnter amount of Working hours per week: ";
	this->_amountOfHoursInWeek = UTILS::CheckUserInput();
}

int WorkerWithHourPay::GetHourPay() const { return _hourPay; }
int WorkerWithHourPay::GetAmountOfHours()const { return _amountOfHoursInWeek; }


