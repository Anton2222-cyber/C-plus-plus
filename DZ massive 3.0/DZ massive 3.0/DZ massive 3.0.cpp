// DZ massive 3.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
#include<time.h>
using namespace std;
#define size 5
#define size2 10
int main()
{
    setlocale(0, "");
    srand(time(0));
    int arr[size][size2], arr2[size][size], count=0, sum=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            arr[i][j] = rand() % 51;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2/2; j++)
        {
            
            arr2[i][j] = arr[i][j + count] + arr[i][j + 1 + count];
            count++;
        }
        count = 0;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}

