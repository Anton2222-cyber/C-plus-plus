// Quick sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class T>
void quickSortR(T a[], long N)
{
    long i = 0, j = N;
    T temp, p;
    p = a[N / 2]; // центральный элемент
    // процедура разделения
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
    /*
    рекурсивные вызовы, если есть,
    что сортировать
    */
    if (j > 0) quickSortR(a, j);
    if (N > i) quickSortR(a + i, N - i);
}



int main()
{
    const int size = 10;
    int arr[size];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;



    quickSortR(arr, size /*- 1*/);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}