#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include"GameSnake.h"
#include"StrategyTime.h"

using namespace std;




int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	StrategyTime* slow = new Slow();
	StrategyTime* normal= new Normal();
	StrategyTime* fast = new Fast();

	GameSnake a;
	int k;
	cout << "Виберіть складність:\n";
	cout << "1-легко\n";
	cout << "2-нормально\n";
	cout << "3-важко\n";
	cout << "0-вихід\n";
	cout << "->";
	cin >> k;
	while (k)
	{
		switch (k)
		{
		case 1:
			a.SetDifficult(slow);
			a.StartGame();
			break;
		case 2:
			a.SetDifficult(normal);
			a.StartGame();
			break;
		case 3:
			a.SetDifficult(fast);
			a.StartGame();
			break;
		}
		cout << "Граємо далі?Виберіть складність:\n";
		cout << "1-легко\n";
		cout << "2-нормально\n";
		cout << "3-важко\n";
		cout << "0-вихід\n";
		cout << "->";
		cin >> k;
	}
	delete slow;
	delete normal;
	delete fast;
	system("pause");
	return 0;
}