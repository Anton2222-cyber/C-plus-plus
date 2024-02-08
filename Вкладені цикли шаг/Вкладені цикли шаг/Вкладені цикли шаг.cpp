// Вкладені цикли шаг.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    setlocale(0, "");
    int n, k = 1, m;
    cout << "Введiть число: ";
    cin >> n;
    m = n;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int l = 1; l == 1; l++)
            {
                cout << n << " ";
            }
            n++;
        }
        k++;
        n = m;
        n -= i;
        cout << endl;
    }

}











   



