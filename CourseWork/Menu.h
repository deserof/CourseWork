#pragma once
#include <iostream>
#include <string>
#include "StorageService.h"
#include "ViewService.h"
#include "FileService.h"
#include "SortService.h"
#include "ConsoleService.h"

using namespace std;

class Menu
{
private:
	ViewService viewservice;
	StorageService storageService;
	FileService fileService;
	SortService sortService;

public:
	void MainMenu()
	{
		while (true)
		{
			ConsoleService::Write("1. �������� ������\n");
			ConsoleService::Write("2. �������� ������\n");
			ConsoleService::Write("3. ��������� ����\n");
			ConsoleService::Write("4. ����������� ������\n");
			ConsoleService::Write("5. ������� ������\n");
			ConsoleService::Write("6. ��������� ����\n");
			ConsoleService::Write("7. �����\n");
			int menuNumber = GetInput();
			system("cls");

			switch (menuNumber)
			{
			case 1: {
				storageService.AddAccount();
				break;
			}
			case 2: {
				PrintMenu();
				break;
			}
			case 3: {
				ConsoleService::Write("���� ������\n");
				fileService.ReadFiles();
				break;
			}
			case 4: {
				SortMenu();
				break;
			}
			case 5: {
				viewservice.ShowAccounts();
				storageService.DeleteAccount();
				break;
			}
			case 6: {
				ConsoleService::Write("���� ��������\n");
				fileService.WriteFiles();
				break;
			}
			case 7: {
				return;
			}
			default:
				ConsoleService::Write("ERROR\n");
				break;
			}
		}
	}
private:
	void PrintMenu()
	{
		bool isOpenMenu = true;

		while (isOpenMenu)
		{
			ConsoleService::Write("1. ������� ��� ������\n");
			ConsoleService::Write("2. ������� ������ �� ����\n");
			ConsoleService::Write("3. ������� ������ �� ������� � ����� ����������\n");
			ConsoleService::Write("4. �����\n");
			int menuNumber = GetInput();
			system("cls");

			switch (menuNumber)
			{
			case 1: {
				viewservice.ShowAccounts();
				break;
			}
			case 2: {
				viewservice.ShowAccountsByDate();
				break;
			}
			case 3: {
				viewservice.ShowAccountsByEmployeeFirstNameAndLastName();
				break;
			}
			case 4: {
				return;
			}
			default:
				ConsoleService::Write("ERROR\n");
				break;
			}
		}
	}

	void SortMenu()
	{
		bool isOpenMenu = true;

		while (isOpenMenu)
		{
			ConsoleService::Write("1. ����������� ������ �� ���� �� �����������\n");
			ConsoleService::Write("2. ����������� ������ �� ���� �� ��������\n");
			ConsoleService::Write("3. �����\n");
			int menuNumber = GetInput();
			system("cls");
			switch (menuNumber)
			{
			case 1: {
				sortService.SortAccountsAscending();
				break;
			}
			case 2: {
				sortService.SortAccountsDescending();
				break;
			}
			case 3: {
				return;
			}
			default:
				ConsoleService::Write("ERROR\n");
				break;
			}
		}
	}

	int GetInput()
	{
		string menuNumberString;
		int menuNumber;
		bool isCorrectNumber = false;

		while (!isCorrectNumber)
		{
			ConsoleService::Write("������� ����� ����:\n");
			cin >> menuNumberString;

			try
			{
				menuNumber = stoi(menuNumberString);
			}
			catch (...)
			{
				ConsoleService::Write("ERROR.������� ����� �� ����\n");
				isCorrectNumber = false;
				continue;
			}

			isCorrectNumber = true;
		}

		return menuNumber;
	}
};
