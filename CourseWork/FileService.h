#pragma once
#include <iostream>
#include <string>
#include "Storage.h"
#include <fstream>
#include "Account.h"

using namespace std;

class FileService
{
private:
	template<typename T1, typename T2>
	static void Write(string file, T1 object, T2 collection)
	{
		ofstream out(file, ofstream::out);

		if (out.is_open())
		{
			for (const T1& object : collection)
			{
				out.write((char*)&object, sizeof(T1));
			}
		}

		out.close();
	}

public:
	static void WriteFiles()
	{
		Account account;
		Write("files\\accounts.bin", account, Storage::accounts);
	}

	static void ReadFiles()
	{
		Storage::accounts.clear();

		ifstream in("files\\accounts.bin", ios::app);

		if (in.is_open())
		{
			Account account;

			while (in.read((char*)&account, sizeof(account)))
			{
				Storage::accounts.push_back(account);
			}
		}

		in.close();
	}
};

