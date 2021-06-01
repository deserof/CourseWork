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
			ConsoleService::Write("1. Добавить запись\n");
			ConsoleService::Write("2. Показать записи\n");
			ConsoleService::Write("3. Прочитать файл\n");
			ConsoleService::Write("4. Сортировать записи\n");
			ConsoleService::Write("5. Удалить запись\n");
			ConsoleService::Write("6. Сохранить файл\n");
			ConsoleService::Write("7. Выход\n");
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
				ConsoleService::Write("Файл считан\n");
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
				ConsoleService::Write("Файл сохранен\n");
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
			ConsoleService::Write("1. Вывести все записи\n");
			ConsoleService::Write("2. Вывести записи по дате\n");
			ConsoleService::Write("3. Вывести записи по фамилии и имени сотрудника\n");
			ConsoleService::Write("4. Назад\n");
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
			ConsoleService::Write("1. Сортировать записи по дате по возрастанию\n");
			ConsoleService::Write("2. Сортировать записи по дате по убыванию\n");
			ConsoleService::Write("3. Назад\n");
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
			ConsoleService::Write("Введите номер меню:\n");
			cin >> menuNumberString;

			try
			{
				menuNumber = stoi(menuNumberString);
			}
			catch (...)
			{
				ConsoleService::Write("ERROR.Введите номер из меню\n");
				isCorrectNumber = false;
				continue;
			}

			isCorrectNumber = true;
		}

		return menuNumber;
	}
};
