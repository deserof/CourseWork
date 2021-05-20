#pragma once
#include <iostream>
#include <regex>
#include "ConsoleService.h"

using namespace std;

class Date
{
private:
	int year = 0;
	int month = 0;
	int day = 0;
	long long convDate = 0;

	int GetInputYear()
	{
		string yy;
		int year;
		bool isCorrectInput = false;

		while (!isCorrectInput)
		{
			cin >> yy;
			regex regular("(\\d{4})");

			try
			{
				if (!regex_match(yy, regular))
				{
					throw 0;
				}

				year = stoi(yy);

				if (year > 2022 || year < 2000)
				{
					throw 0;
				}
			}
			catch (...)
			{
				ConsoleService::Write("Неправильный ввод\n");
				isCorrectInput = false;
				continue;
			}

			isCorrectInput = true;
		}

		return year;
	}

	int GetInputMonth()
	{
		string mm;
		int month;
		bool isCorrectInput = false;

		while (!isCorrectInput)
		{
			cin >> mm;
			regex regular("(\\d{2}||\\d{1})");

			try
			{
				if (!regex_match(mm, regular))
				{
					throw 0;
				}

				month = stoi(mm);

				if (month > 12 || month < 1)
				{
					throw 0;
				}
			}
			catch (...)
			{
				ConsoleService::Write("Неправильный ввод\n");
				isCorrectInput = false;
				continue;
			}

			isCorrectInput = true;
		}

		return month;
	}

	int GetInputDay()
	{
		string dd;
		int day;
		bool isCorrectInput = false;

		while (!isCorrectInput)
		{
			cin >> dd;
			regex regular("(\\d{2}||\\d{1})");

			try
			{
				if (!regex_match(dd, regular))
				{
					throw 0;
				}

				day = stoi(dd);

				if (day > 31 || day < 1)
				{
					throw 0;
				}

				if (year % 4 == 0 && month == 2 && day > 29)
				{
					throw 0;
				}

				if (year % 4 != 0 && month == 2 && day > 28)
				{
					throw 0;
				}
			}
			catch (...)
			{
				ConsoleService::Write("Неправильный ввод\n");
				isCorrectInput = false;
				continue;
			}

			isCorrectInput = true;
		}

		return day;
	}

public:
	int GetYear()
	{
		return year;
	}

	int GetMonth()
	{
		return month;
	}

	int GetDay()
	{
		return day;
	}

	void SetDate()
	{
		int yy, mm, dd;
		ConsoleService::Write("Введите год:\n");
		year = GetInputYear();
		ConsoleService::Write("Введите месяц:\n");
		month = GetInputMonth();
		ConsoleService::Write("Введите день:\n");
		day = GetInputDay();
		convDate = year * 365 + month * 31 + day;
	}

	string GetFullDate()
	{
		return to_string(year) + ":" + to_string(month) + ":" + to_string(day);
	}

	long long GetConvDate()
	{
		return convDate;
	}
};

