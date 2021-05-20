#include <iostream>
#include "Menu.h"
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Menu menu;
    menu.MainMenu();
}