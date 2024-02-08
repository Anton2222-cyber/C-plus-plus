// цикли шаг.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    setlocale(0, "");
    int n=15, b;
    cout << "Введите количество ящиков\n";
    cin >> b;
    while (b <= n)
    {
        b -= n;
        b++;
    }
    cout << b;
}

