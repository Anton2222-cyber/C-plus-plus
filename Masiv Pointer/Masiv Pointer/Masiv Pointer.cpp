// Masiv Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;

int* Add(int* arr, int* size, int a)
{
	int* temp = new int[*size];
	for (int i = 0; i < *size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = new int[*size + 1];
	for (int i = 0; i < *size; i++)
	{
		arr[i] = temp[i];
	}
	delete[] temp;
	arr[*size] = a;
	*size += 1;
	return arr;
}

int* Prosti_Chisla(int* arr, int* size)
{
	int size2 = 0;
	int count = 0;
	int* temp = new int[size2];
	for (int i = 0; i < *size; i++)
	{
		for (int j = 1; j <= arr[i]; j++)
		{
			if (arr[i] % j == 0)
				count++;

		}
		if (count == 2)
			temp = Add(temp, &size2, arr[i]);
		count = 0;
	}
	*size = size2;
	delete[] arr;
	
	return temp;
}

int* Kratni_3(int* arr, int* size)
{
	int size2 = 0;
	int* temp = new int[size2];
	for (int i = 0; i < *size; i++)
	{
		if (arr[i] % 3 == 0)
			temp = Add(temp, &size2, arr[i]);
	}

	*size = size2;
	delete[] arr;

	return temp;
}

int* Parni(int* arr, int* size)
{
	int size2 = 0;
	int* temp = new int[size2];
	for (int i = 0; i < *size; i++)
	{
		if (arr[i] % 2 == 0)
			temp = Add(temp, &size2, arr[i]);
	}
	*size = size2;
	delete[] arr;

	return temp;

}
int* Arr_Pointer(int*(*arr[3])(int*, int*), int *arr1, int* size)
{
	int i;
	cout << "Введiть операцiю над масивом(Масив з простими числами - 1, Масив чисел кратних 3-ом - 2, Масив парних чисел - 3)\n";
	cout << "->";
	cin >> i;
	
	return (arr[i - 1](arr1, size));
}

int main()
{
	setlocale(0, "");
	srand(time(0));
	int size;
	int* (*arrp[3])(int*, int*) = { Prosti_Chisla, Kratni_3, Parni };
	cout << "Введiть розмiр масива\n";
	cout << "->";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101;
		cout << arr[i] << " ";
	}
	cout << endl;

	arr=Arr_Pointer(arrp, arr, &size);
	if (size == 0)
		cout << "Немає чисел такого типу у масивi\n";
	else
	{
		cout << "Новий масив:\n";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}
	delete[] arr;
	return 0;
}