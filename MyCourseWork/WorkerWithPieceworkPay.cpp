#include <iostream>
#include "WorkerWithPieceworkPay.h"
#include "Employee.h"
#include "utils.h"

using namespace std;
	WorkerWithPieceworkPay::WorkerWithPieceworkPay():Employee()
	{
		cout << "\nEnter Piece work pay: ";
		this->_itemPay = UTILS::CheckUserInput();
		cout << "\nEnter amount of completed work: ";
		this->_amountOfWorkInWeek = UTILS::CheckUserInput();
	}

	void WorkerWithPieceworkPay::Display() const
	{
		Employee::Display();
		cout << "Enter price per item - " << _itemPay
			<< "\nAmount of items made per week - " << _amountOfWorkInWeek << endl;
	}

	void WorkerWithPieceworkPay::Change()//override
	{
		Employee::Change();
		cout << "\nEnter Piece work pay: ";
		this->_itemPay = UTILS::CheckUserInput();
		cout << "\nAmount of items made per week: ";
		this->_amountOfWorkInWeek = UTILS::CheckUserInput();
	}

	int WorkerWithPieceworkPay::GetItemPay()const { return _itemPay; }
	int WorkerWithPieceworkPay::GetAmountOfWork() const { return _amountOfWorkInWeek; }
