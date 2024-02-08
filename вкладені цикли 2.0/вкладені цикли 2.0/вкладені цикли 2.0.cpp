// вкладені цикли 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    setlocale(0, "");
    int n, m;
    cout << "Введiть число: ";
    cin >> n;
    m = n;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            for (int k = 1; k == 1; k++)
            {
                cout << n << " ";
            }
            n++;
        }
        n = m;
        cout << endl;
    }
}