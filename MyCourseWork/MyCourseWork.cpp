// MyCourseWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include<fstream>
#include<ostream>
#include "IHumanBeing.h"
#include "Employee.h"
#include "Man.h"
#include "WorkerWithHourPay.h"
#include "WorkerWithPieceworkPay.h"
#include "utils.h"
using namespace std;

enum Operations
{
	Add = 1,
	Show = 2,
	Change = 3,
	Write = 4,
	Exit = 0
};



void ShowMenu()
{
	cout << "\tMENU"
		<< "\n(1) - ADD PERSON TO THE LIST"
		<< "\n(2) - SHOW LIST"
		<< "\n(3) - CHANGE INFO ABOUT PERSON"
		<< "\n(4) - WRITE DATA TO A FILE"
		<< "\n(0) - EXIT"
		<< "\n\nYOUR CHOISE>> ";
}

void CreateList(vector<Employee*>& arr)
{
	cout << "\n(1) - Add Employee"
		<< "\n(2) - Add Worker with hour pay"
		<< "\n(3) - Add Worker with piece work pay"
		<< "\n\nYour choise>> ";
	int choice = 0;

	choice = UTILS::CheckUserInput();

	switch (choice)
	{
	case 1:
		arr.push_back(new Employee);
		break;
	case 2:
		arr.push_back(new WorkerWithHourPay);
		break;
	case 3:
		arr.push_back(new WorkerWithPieceworkPay);
		break;
	default:
		cout << "\nNo such point!\n\n";
		break;
	}
}

void DisplayList(vector<Employee*> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i]->Display();
		cout << endl;
	}
}

void ClearAll(vector<Employee*>& arr)
{
	for (auto person : arr)
	{
		delete person;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Employee*> arr;

	bool isOpen = true;
	bool isOpened = false;

	while (isOpen)
	{
		ShowMenu();
		int menu_choice = UTILS::CheckUserInput();

		switch (menu_choice)
		{
		case Operations::Add:
			CreateList(arr);
			isOpened = true;
			break;
		case Operations::Show:
			if (isOpened) DisplayList(arr);
			else cout << "\nList is empty!\n";
			break;
		case Operations::Change:
			if (isOpened)
			{
				int changeNumber;
				cout << "Enter person's ID, who you want to change: ";
				changeNumber = UTILS::CheckUserInput();
				int numberOfPerson = 0;
				bool isFinded = false;

				for (int i = 0; i < arr.size(); i++)
				{
					if (arr[i]->GetID() == changeNumber)
					{
						isFinded = true;
						numberOfPerson = i;
					}
				}

				if (isFinded)
				{
					arr[numberOfPerson]->Change();
					cout << "\nInfo has been changed!\n";
				}
				else
				{
					cout << "\nThere is no such ID in the list!\n";
				}
			}
			else cout << "\nList is empty!\n";
			break;
		case Operations::Write:
			if (isOpened)
			{
				string fileName;
				cout << "Enter filename: ";
				cin >> fileName;
				fileName += ".txt";
				ofstream out(fileName, ios::out | ios::binary);

				if (!out.is_open()) cout << "\nFile didn't manage to open!\n";
				else
				{
					for (int i = 0; i < arr.size(); i++)
					{
						out << "Employee" << endl;
						out << arr[i]->GetID() << endl;
						out << arr[i]->GetFullname() << endl;
						out << arr[i]->GetAge() << endl << endl;
					}
					cout << "\nData has been written succesfully!";
				}
				out.close();
			}
			else cout << "\nList is empty!!\n";
			break;
		case Operations::Exit:
			isOpen = false;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	ClearAll(arr);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
