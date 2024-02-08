// екзамен відсотки задачка.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>


using namespace std;

#define size 4

int main()
{
	setlocale(0, "");
	float arr[size], count=0;
	cout << "Обработка результатов экзамена.\n";
	cout << "Введите исходные данные:\n";
	cout << "пятерок -> ";
	cin >> arr[0];
	cout << "четверок -> ";
	cin >> arr[1];
	cout << "троек -> ";
	cin >> arr[2];
	cout << "двоек -> ";
	cin >> arr[3];
	for (int i = 0; i < size; i++)
	{
		count += arr[i];
	}
	count = 100 / count;
	for (int i = 0; i < size; i++)
	{
		arr[i] = arr[i] * count;
	}
	cout << "Результаты экзамена\n";
	cout << "пятерок -> " << arr[0] << "% \n";
	cout << "четверок -> " << arr[1] << "%\n";
	cout << "троек -> " << arr[2] << "%\n";
	cout << "двоек -> " << arr[3] << "%\n";
}
