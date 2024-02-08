// масиви шаг.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define SIZE 5

void main()
{
    setlocale(0, "");
    int a[SIZE], min;
    cout << "Введите в одной строке элементы массива (5 целых чисел) и нажмите <Enter> -> ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> a[i];
    }
    min = a[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
       
    }
    cout << "Минимальный элемент массива: " << min;
}