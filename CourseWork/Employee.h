#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
#include <regex>
#include "Person.h"
#include "ConsoleService.h"

using namespace std;

class Employee : public Person
{
private:
	char address[128];
	char phone[128];
	int numberHourPerMonth;
	int salary;
	static constexpr float INCOME_TAX = 0.12f;
	static constexpr int FULL_WORKING_HOURS = 144;

	int GetInput()
	{
		string numberString;
		int number;
		bool isCorrectNumber = false;

		while (!isCorrectNumber)
		{
			cin >> numberString;

			try
			{
				number = stoi(numberString);

				if (number < 0)
				{
					throw 0;
				}
			}
			catch (...)
			{
				ConsoleService::Write("ERROR\n");
				isCorrectNumber = false;
				continue;
			}

			isCorrectNumber = true;
		}

		return number;
	}

	string GetInputPhoneNumber()
	{
		string phoneNumber;
		bool isCorrectNumber = false;

		while (!isCorrectNumber)
		{
			cin >> phoneNumber;
			regex regular("^(\\+375)(29|25|33|44)(\\d{7})$");

			try
			{
				if (!regex_match(phoneNumber, regular))
				{
					throw 0;
				}
			}
			catch (...)
			{
				ConsoleService::Write("Ќеверный ввод\n");
				isCorrectNumber = false;
				continue;
			}

			isCorrectNumber = true;
		}

		return phoneNumber;
	}

public:
	string GetAddress()
	{
		return address;
	}

	string GetPhone()
	{
		return phone;
	}

	int GetNumberHourPerMonth()
	{
		return numberHourPerMonth;
	}

	int GetSalary()
	{
		return salary;
	}

	void SetEmployee()
	{
		cin.ignore();
		ConsoleService::Write("¬ведите им€ работника: ");
		cin.getline(firstName, 128);
		ConsoleService::Write("¬ведите фамилию работника: ");
		cin.getline(lastName, 128);
		ConsoleService::Write("¬ведите отчество работника: ");
		cin.getline(middleName, 128);
		ConsoleService::Write("¬ведите адрес работника: ");
		cin.getline(address,128);
		ConsoleService::Write("¬ведите телефон пациента (+375 29|44|25|33 7цифр): ");
		strcpy(phone, GetInputPhoneNumber().c_str());
		ConsoleService::Write("¬ведите отработанные часы: ");
		numberHourPerMonth = GetInput();
		ConsoleService::Write("¬ведите зарплату работника :");
		salary = GetInput();
	}
};