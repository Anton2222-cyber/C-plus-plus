// Dynamic massiv.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int* Vidminne(int* arr1, int* arr2, int* size1, int* size2)
{
	bool b=false;
	int* temp = new int[*size1];
	for (int i = 0; i < *size1; i++)
	{
		temp[i] = arr1[i];
	}
	for (int i = 0; i < *size2; i++)
	{
		for (int j = 0; j < *size1; j++)
		{
			if (arr2[i] == arr1[j])
			{
				b = true;
			}
		}
		if (b == false)
			temp=Add(temp, size1, arr2[i]);
		b = false;

	}
	delete[] arr1;
	arr1 = new int[*size1];
	for (int i = 0; i < *size1; i++)
	{
		arr1[i] = temp[i];
	}
	delete[] temp;
	return arr1;
}

int main()
{
	setlocale(0, "");
	srand(time(0));
	int size1, size2;
	cout << "Введiть розмiр першого i другого масива\n";
	cout << "->";
	cin >> size1;
	cout << "->";
	cin >> size2;
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = rand() % 101;
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = rand() % 101;
		cout << arr2[i] << " ";
	}
	cout << endl;
	arr1 = Vidminne(arr1, arr2, &size1, &size2);
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}


	delete[] arr1;
	delete[] arr2;
	return 0;
}

