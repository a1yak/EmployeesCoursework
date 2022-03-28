#pragma once
#include "Employee.h"
class WorkerWithPieceworkPay : public Employee
{
private:
	int _itemPay;
	int _amountOfWorkInWeek;
public:
	WorkerWithPieceworkPay();
	void Display() const override;
	void Change()override;
	int GetItemPay()const;
	int GetAmountOfWork() const;
};