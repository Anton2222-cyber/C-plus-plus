// Rekyrsia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<time.h>
using namespace std;
int Max(int arr[], int size, int i = 0) {
	if (i == size)
		return arr[size];

	int max = Max(arr, size, i + 1);

	if (arr[i] < max)
		return max;
	else {
		return arr[i];
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int const size = 10;
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}

	cout << endl;
	cout << Max(arr, size);
	return 0;
}