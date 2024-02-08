// Цикли дз шаг.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int i = 1, a, i2, i3;

	cout << "Введiть число:" << endl;
	cin >> a;
	cout << "Числа якi дiляться нацiло на квадрат i не дiляться нацiло на куб:" << endl;
	while (i <= a)
	{
		i2 = i * i;
		i3 = i * i * i;
		if (((a % i2) == 0) && ((a % i3) != 0))
		{
			cout << i << endl;
		}
		i++;
	}
}