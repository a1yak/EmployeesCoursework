#pragma once
#include "Employee.h"
class WorkerWithHourPay :public Employee
{
private:
	int _hourPay;
	int _amountOfHoursInWeek;
public:
	WorkerWithHourPay();
	
	void Display() const override;
	void Change() override;
	
	int GetHourPay() const;
	int GetAmountOfHours()const;
};