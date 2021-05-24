#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
#include <regex>
#include "Person.h"
#include "ConsoleService.h"
#include "EmployeeType.h"	

using namespace std;

class Employee : public Person
{
private:
	char address[128];
	char phone[128];
	int numberHourPerMonth;
	int salary;
	EmployeeType employeeType;
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
				ConsoleService::Write("Неверный ввод\n");
				isCorrectNumber = false;
				continue;
			}

			isCorrectNumber = true;
		}

		return phoneNumber;
	}

public:
	EmployeeType GetEmployeeType() {
		return employeeType;
	}

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
		ConsoleService::Write("Введите должность работника (цифру): \n0. Директор\n1. Бухгалтер\n2. Наемный рабочий\n3. Уборщик\n");
		employeeType = (EmployeeType)GetInputEmployeeType();
		cin.ignore();
		ConsoleService::Write("Введите имя работника: ");
		cin.getline(firstName, 128);
		ConsoleService::Write("Введите фамилию работника: ");
		cin.getline(lastName, 128);
		ConsoleService::Write("Введите отчество работника: ");
		cin.getline(middleName, 128);
		ConsoleService::Write("Введите адрес работника: ");
		cin.getline(address,128);
		ConsoleService::Write("Введите телефон работника (+375 29|44|25|33 7цифр): ");
		strcpy(phone, GetInputPhoneNumber().c_str());
		ConsoleService::Write("Введите отработанные часы: ");
		numberHourPerMonth = GetInput();
		ConsoleService::Write("Введите зарплату работника: ");
		int salaryClear = GetInput();
		salary = salaryClear - salaryClear * INCOME_TAX;
	}

	private:
		int GetInputEmployeeType()
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

					if (number < 0 || number > 3) {
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
};