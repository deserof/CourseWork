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
			ConsoleService::Write("��� ����������: " + Storage::accounts[i].GetEmployee().GetFirtsName() + "\n");
			ConsoleService::Write("������� ����������: " + Storage::accounts[i].GetEmployee().GetLastName() + "\n");
			ConsoleService::Write("�������� ����������: " + Storage::accounts[i].GetEmployee().GetMiddleName() + "\n");
			ConsoleService::Write("����� ����������: " + Storage::accounts[i].GetEmployee().GetAddress() + "\n");
			ConsoleService::Write("�������� ����������: " + to_string(Storage::accounts[i].GetEmployee().GetSalary()) + "\n");
			ConsoleService::Write("������������ ���� ����������: " + to_string(Storage::accounts[i].GetEmployee().GetNumberHourPerMonth()) + "\n");
			ConsoleService::Write("������� ����������: " + Storage::accounts[i].GetEmployee().GetPhone() + "\n");
			ConsoleService::Write("���� ������: " + Storage::accounts[i].GetDate().GetFullDate() + "\n");
			ConsoleService::Write("\n");
		}
	}

	void ShowAccountsByEmployeeFirstNameAndLastName()
	{
		string lastName, firstName;
		ConsoleService::Write("������� ��� ����������\n");
		cin >> firstName;
		ConsoleService::Write("������� ������� ����������: \n");
		cin >> lastName;

		bool isFind = false;
		ConsoleService::Write("Accounts by fn and ln\n");

		for (int i = 0; i < Storage::accounts.size(); i++)
		{
			if (firstName == Storage::accounts[i].GetEmployee().GetFirtsName() && lastName == Storage::accounts[i].GetEmployee().GetLastName())
			{
				ConsoleService::Write("Id: " + to_string(i) + "\n");
				ConsoleService::Write("��� ����������: " + Storage::accounts[i].GetEmployee().GetFirtsName() + "\n");
				ConsoleService::Write("������� ����������: " + Storage::accounts[i].GetEmployee().GetLastName() + "\n");
				ConsoleService::Write("�������� ����������: " + Storage::accounts[i].GetEmployee().GetMiddleName() + "\n");
				ConsoleService::Write("����� ����������: " + Storage::accounts[i].GetEmployee().GetAddress() + "\n");
				ConsoleService::Write("�������� ����������: " + to_string(Storage::accounts[i].GetEmployee().GetSalary()) + "\n");
				ConsoleService::Write("������������ ���� ����������: " + to_string(Storage::accounts[i].GetEmployee().GetNumberHourPerMonth()) + "\n");
				ConsoleService::Write("������� ����������: " + Storage::accounts[i].GetEmployee().GetPhone() + "\n");
				ConsoleService::Write("���� ������: " + Storage::accounts[i].GetDate().GetFullDate() + "\n");
				ConsoleService::Write("\n");
				isFind = true;
			}
		}

		if (isFind == false)
		{
			ConsoleService::Write("������ ���������� ���\n");
		}
	}

	void ShowAccountsByDate()
	{
		int yy, mm, dd;
		ConsoleService::Write("������ ����������� �� ������������ ����\n");
		ConsoleService::Write("������� ���� ������: \n");
		ConsoleService::Write("������� ���\n");
		cin >> yy;
		ConsoleService::Write("������� �����\n");
		cin >> mm;
		ConsoleService::Write("������� ����\n");
		cin >> dd;

		bool isFind = false;
		ConsoleService::Write("Accounts by fn and ln\n");

		for (int i = 0; i < Storage::accounts.size(); i++)
		{
			if (Storage::accounts[i].GetDate().GetYear() == yy && Storage::accounts[i].GetDate().GetMonth() == mm
				&& Storage::accounts[i].GetDate().GetDay() == dd)
			{
				ConsoleService::Write("Id: " + to_string(i) + "\n");
				ConsoleService::Write("��� ����������: " + Storage::accounts[i].GetEmployee().GetFirtsName() + "\n");
				ConsoleService::Write("������� ����������: " + Storage::accounts[i].GetEmployee().GetLastName() + "\n");
				ConsoleService::Write("�������� ����������: " + Storage::accounts[i].GetEmployee().GetMiddleName() + "\n");
				ConsoleService::Write("����� ����������: " + Storage::accounts[i].GetEmployee().GetAddress() + "\n");
				ConsoleService::Write("�������� ����������: " + to_string(Storage::accounts[i].GetEmployee().GetSalary()) + "\n");
				ConsoleService::Write("������������ ���� ����������: " + to_string(Storage::accounts[i].GetEmployee().GetNumberHourPerMonth()) + "\n");
				ConsoleService::Write("������� ����������: " + Storage::accounts[i].GetEmployee().GetPhone() + "\n");
				ConsoleService::Write("���� ������: " + Storage::accounts[i].GetDate().GetFullDate() + "\n");
				ConsoleService::Write("\n");
				isFind = true;
			}
		}

		if (isFind == false)
		{
			ConsoleService::Write("������ ���������� ���\n");
		}
	}

	void ShowAccounts(vector<Account> accounts)
	{
		ConsoleService::Write("Accounts\n");
		for (int i = 0; i < accounts.size(); i++)
		{
			ConsoleService::Write("Id: " + to_string(i) + "\n");
			ConsoleService::Write("��� ����������: " + accounts[i].GetEmployee().GetFirtsName() + "\n");
			ConsoleService::Write("������� ����������: " + accounts[i].GetEmployee().GetLastName() + "\n");
			ConsoleService::Write("�������� ����������: " + accounts[i].GetEmployee().GetMiddleName() + "\n");
			ConsoleService::Write("����� ����������: " + accounts[i].GetEmployee().GetAddress() + "\n");
			ConsoleService::Write("�������� ����������: " + to_string(accounts[i].GetEmployee().GetSalary()) + "\n");
			ConsoleService::Write("������������ ���� ����������: " + to_string(accounts[i].GetEmployee().GetNumberHourPerMonth()) + "\n");
			ConsoleService::Write("������� ����������: " + accounts[i].GetEmployee().GetPhone() + "\n");
			ConsoleService::Write("���� ������: " + accounts[i].GetDate().GetFullDate() + "\n");
			ConsoleService::Write("\n");
		}
	}
};

