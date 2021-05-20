#pragma once
#include "Storage.h"
#include "ConsoleService.h"

using namespace std;

class ViewService
{
public:
	void ShowAccounts()
	{
		ConsoleService::Write("Accounts\n");
		for (int i = 0; i < Storage::accounts.size(); i++)
		{
			ConsoleService::Write("Id: " + to_string(i) + "\n");
			ConsoleService::Write("Имя сотрудника: " + Storage::accounts[i].GetEmployee().GetFirtsName() + "\n");
			ConsoleService::Write("Фамилия сотрудника: " + Storage::accounts[i].GetEmployee().GetLastName() + "\n");
			ConsoleService::Write("Отчество сотрудника: " + Storage::accounts[i].GetEmployee().GetMiddleName() + "\n");
			ConsoleService::Write("Адрес сотрудника: " + Storage::accounts[i].GetEmployee().GetAddress() + "\n");
			ConsoleService::Write("Зарплата сотрудника: " + to_string(Storage::accounts[i].GetEmployee().GetSalary()) + "\n");
			ConsoleService::Write("Отработанные часы сотрудника: " + to_string(Storage::accounts[i].GetEmployee().GetNumberHourPerMonth()) + "\n");
			ConsoleService::Write("Телефон сотрудника: " + Storage::accounts[i].GetEmployee().GetPhone() + "\n");
			ConsoleService::Write("Дата записи: " + Storage::accounts[i].GetDate().GetFullDate() + "\n");
			ConsoleService::Write("\n");
		}
	}

	void ShowAccountsByEmployeeFirstNameAndLastName()
	{
		string lastName, firstName;
		ConsoleService::Write("Введите имя сотрудника\n");
		cin >> firstName;
		ConsoleService::Write("Введите фамилию сотрудника: \n");
		cin >> lastName;

		bool isFind = false;
		ConsoleService::Write("Accounts by fn and ln\n");

		for (int i = 0; i < Storage::accounts.size(); i++)
		{
			if (firstName == Storage::accounts[i].GetEmployee().GetFirtsName() && lastName == Storage::accounts[i].GetEmployee().GetLastName())
			{
				ConsoleService::Write("Id: " + to_string(i) + "\n");
				ConsoleService::Write("Имя сотрудника: " + Storage::accounts[i].GetEmployee().GetFirtsName() + "\n");
				ConsoleService::Write("Фамилия сотрудника: " + Storage::accounts[i].GetEmployee().GetLastName() + "\n");
				ConsoleService::Write("Отчество сотрудника: " + Storage::accounts[i].GetEmployee().GetMiddleName() + "\n");
				ConsoleService::Write("Адрес сотрудника: " + Storage::accounts[i].GetEmployee().GetAddress() + "\n");
				ConsoleService::Write("Зарплата сотрудника: " + to_string(Storage::accounts[i].GetEmployee().GetSalary()) + "\n");
				ConsoleService::Write("Отработанные часы сотрудника: " + to_string(Storage::accounts[i].GetEmployee().GetNumberHourPerMonth()) + "\n");
				ConsoleService::Write("Телефон сотрудника: " + Storage::accounts[i].GetEmployee().GetPhone() + "\n");
				ConsoleService::Write("Дата записи: " + Storage::accounts[i].GetDate().GetFullDate() + "\n");
				ConsoleService::Write("\n");
				isFind = true;
			}
		}

		if (isFind == false)
		{
			ConsoleService::Write("Такого сотрудника нет\n");
		}
	}

	void ShowAccountsByDate()
	{
		int yy, mm, dd;
		ConsoleService::Write("Записи сотрудников за определенную дату\n");
		ConsoleService::Write("Введите дату записи: \n");
		ConsoleService::Write("Введите год\n");
		cin >> yy;
		ConsoleService::Write("Введите месяц\n");
		cin >> mm;
		ConsoleService::Write("Введите день\n");
		cin >> dd;

		bool isFind = false;
		ConsoleService::Write("Accounts by fn and ln\n");

		for (int i = 0; i < Storage::accounts.size(); i++)
		{
			if (Storage::accounts[i].GetDate().GetYear() == yy && Storage::accounts[i].GetDate().GetMonth() == mm
				&& Storage::accounts[i].GetDate().GetDay() == dd)
			{
				ConsoleService::Write("Id: " + to_string(i) + "\n");
				ConsoleService::Write("Имя сотрудника: " + Storage::accounts[i].GetEmployee().GetFirtsName() + "\n");
				ConsoleService::Write("Фамилия сотрудника: " + Storage::accounts[i].GetEmployee().GetLastName() + "\n");
				ConsoleService::Write("Отчество сотрудника: " + Storage::accounts[i].GetEmployee().GetMiddleName() + "\n");
				ConsoleService::Write("Адрес сотрудника: " + Storage::accounts[i].GetEmployee().GetAddress() + "\n");
				ConsoleService::Write("Зарплата сотрудника: " + to_string(Storage::accounts[i].GetEmployee().GetSalary()) + "\n");
				ConsoleService::Write("Отработанные часы сотрудника: " + to_string(Storage::accounts[i].GetEmployee().GetNumberHourPerMonth()) + "\n");
				ConsoleService::Write("Телефон сотрудника: " + Storage::accounts[i].GetEmployee().GetPhone() + "\n");
				ConsoleService::Write("Дата записи: " + Storage::accounts[i].GetDate().GetFullDate() + "\n");
				ConsoleService::Write("\n");
				isFind = true;
			}
		}

		if (isFind == false)
		{
			ConsoleService::Write("Такого сотрудника нет\n");
		}
	}

	void ShowAccounts(vector<Account> accounts)
	{
		ConsoleService::Write("Accounts\n");
		for (int i = 0; i < accounts.size(); i++)
		{
			ConsoleService::Write("Id: " + to_string(i) + "\n");
			ConsoleService::Write("Имя сотрудника: " + accounts[i].GetEmployee().GetFirtsName() + "\n");
			ConsoleService::Write("Фамилия сотрудника: " + accounts[i].GetEmployee().GetLastName() + "\n");
			ConsoleService::Write("Отчество сотрудника: " + accounts[i].GetEmployee().GetMiddleName() + "\n");
			ConsoleService::Write("Адрес сотрудника: " + accounts[i].GetEmployee().GetAddress() + "\n");
			ConsoleService::Write("Зарплата сотрудника: " + to_string(accounts[i].GetEmployee().GetSalary()) + "\n");
			ConsoleService::Write("Отработанные часы сотрудника: " + to_string(accounts[i].GetEmployee().GetNumberHourPerMonth()) + "\n");
			ConsoleService::Write("Телефон сотрудника: " + accounts[i].GetEmployee().GetPhone() + "\n");
			ConsoleService::Write("Дата записи: " + accounts[i].GetDate().GetFullDate() + "\n");
			ConsoleService::Write("\n");
		}
	}
};

