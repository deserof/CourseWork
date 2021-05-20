#pragma once
#include "Account.h"
#include "Storage.h"
#include "ConsoleService.h"
using namespace std;

class StorageService
{
private:
	int GetInput()
	{
		string menuNumberString;
		int menuNumber;
		bool isCorrectNumber = false;

		while (!isCorrectNumber)
		{
			ConsoleService::Write("¬ведите id:\n");
			cin >> menuNumberString;

			try
			{
				menuNumber = stoi(menuNumberString);
			}
			catch (...)
			{
				ConsoleService::Write("ERROR\n");
				isCorrectNumber = false;
				continue;
			}

			isCorrectNumber = true;
		}

		return menuNumber;
	}
public:
	void AddAccount()
	{
		Date date;
		date.SetDate();
		Employee employee;
		employee.SetEmployee();
		Account account;
		account.SetAccount(date, employee);
		Storage::accounts.push_back(account);
	}

	void DeleteAccount()
	{
		int id = GetInput();

		if (id < 0 || id >= Storage::accounts.size())
		{
			ConsoleService::Write("id не существует\n");
			return;
		}

		Storage::accounts.erase(Storage::accounts.begin() + id);
	}
};

