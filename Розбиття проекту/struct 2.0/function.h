#pragma once
#include<iostream>
#include<time.h>

using namespace std;
#define INTEGER 100
template <class F>
void Set_random(const int size, F arr[])
{

	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101/(float)10;

	}


}


template <class C>
void Print_arr(C arr[], const int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";

	}
	cout << endl;

}


template <class B>
void Min_by_arr(B arr[], const int size)
{
	B min = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	cout << min << endl;
}

template <class A>
void Max_by_arr(A arr[], const int size)
{
	A max = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	cout << max << endl;
}

template <class T>
void quickSortR(T a[], long N)
{
	long i = 0, j = N;
	T temp, p;
	p = a[N / 2];
	do {
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) quickSortR(a, j);
	if (N > i) quickSortR(a + i, N - i);
}

#ifdef INTEGER
template <class K>
void Red_edit(K arr[], int const size)
{
	setlocale(0, "");
	for (int i = 0; i < size; i++)
	{
		cout << "¬вед≥ть " << i + 1 << " елемент масива ->";
		cin >> arr[i];
	}

}


#endif // INTEGER

