// Pointer 1.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<time.h>
using namespace std;
void Sdvig(int* px0, int* px, int*pend, int* peredend, int size)
{
    int a, b, temp;
    int* px2 = &*px;
    int* pperedend = &*peredend;
    cout << "Куди зрушення(вправо - |1|, влiво - |2|)\n";
    cout << "->";
    cin >> b;
    switch (b)
    {
    case 1:
        cout << "Скiльки зрушень?\n";
        cout << "->";
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {      
                temp = *px0;
                *px0 = *px;
                *px = temp;
                px++;
            }
            px = &*px2;
        }
        break;
    case 2:
        cout << "Скiльки зрушень?\n";
        cout << "->";
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                temp = *pend;
                *pend = *peredend;
                *peredend = temp;
                peredend--;
            }
            peredend = &*pperedend;
        }


    }


}
int main()
{
    setlocale(0, "");
    srand(time(0));
    int const size = 10;
    int arr[size];
    int* px = &arr[1];
    int* pend = &arr[size - 1];
    int* peredend = &arr[size - 2];
    cout << "Масив \n";
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    Sdvig(arr, px, pend, peredend, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

