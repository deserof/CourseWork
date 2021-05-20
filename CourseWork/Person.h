#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>

using namespace std;

class Person
{
protected:
	char firstName[128];
	char lastName[128];
	char middleName[128];
public:
	string GetFirtsName()
	{
		return firstName;
	}

	string GetLastName()
	{
		return lastName;
	}

	string GetMiddleName()
	{
		return middleName;
	}
};

