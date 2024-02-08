// РОБОТА з ФАЙЛАМИ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
// Робота з файлами.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

int main()
{
    setlocale(0, "");
    FILE* f;
    int n, a;
    const int count = 8;
    int chisla[count];

    f = fopen("E:\\money.txt", "w");
    for (int i = 0; i < count; i++) {
        cout << "введите " << i +1 << " число ";
        cin >> chisla[i];
        cout << endl;
        fprintf(f, "%d", chisla[i]);
    }
    int tmp;
    int c1 = 0;
    int counterS = 0;
    int res[8];
    for (int i = 0; i < count; i++)
    {

        if ((((chisla[i] % 2) == 0) && chisla[i] != 2) || (((chisla[i] % 3) == 0) && chisla[i] != 3)) {
            res[c1++] = chisla[i];
            counterS++;
        }

    }
    int temp;
    for (int i = 0; i < counterS; i++) {
        for (int j = i + 1; j < counterS; j++) {
            if (res[i] < res[j]) {
                temp = res[i];
                res[i] = res[j];
                res[j] = temp;
            }
        }
    }
    for (int i = 0; i < counterS; i++) {
        cout << "Складенные числа" << res[i] << endl;
    }


    fclose(f);


    return 0;
}
