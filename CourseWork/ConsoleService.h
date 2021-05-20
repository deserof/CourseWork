#pragma once
#include <iostream>
#include <string>

using namespace std;

class ConsoleService
{
public:
	static void Write(string text)
	{
		cout << text;
	}
};

