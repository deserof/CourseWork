#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Employee.h"

using namespace std;

class Account
{
private:
	Date date;
	Employee employee;
public:
	Date GetDate()
	{
		return date;
	}

	Employee GetEmployee()
	{
		return employee;
	}

	void SetAccount(Date date, Employee employee)
	{
		this->date = date;
		this->employee = employee;
	}
};

