// шаг масиви дз 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>


using namespace std;

#define size 10

int main()
{
	setlocale(0, "");
	int arr[size];
	bool b = false;
	cout << "Заповнiть масив (10 чисел) -> ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - 1; j++)
		{
			if (arr[i] == arr[j])
			{
				b = true;
			}
		}
	}
	if (b)
	{
		cout << "Є елементи з одинаковими значеннями\n";
	}
	else
	{
		cout << "Немає елементiв з одинаковими значеннями\n";

	}