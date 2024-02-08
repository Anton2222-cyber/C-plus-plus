// game вгадай число.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
#include<time.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int x, i, sum = 1;
    x = 1 + rand() % 500;
    cout << "Гра <<Вгадайте число(вiд 1 до 500)>>\n";
    cout << "Вихiд з гри - 0\n";
    cout << "Вгадайте число:\n";
    cin >> i;
    for (; i != 0; sum++)
    {
        if (i < x)
        {
            cout << "Бiльше:)\n";
        }
        if (i > x)
        {
            cout << "Менше:)\n";
        }
        if (i == x)
        {
            cout << "Ура Ви вгадали:)\n";
            cout << "Кiлькiсть спроб: " << sum << endl;
            break;
        }
        cin >> i;
    }
}