// масиви академія шаг пара.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define size 12
int main()
{
    setlocale(0, "");
    
    int arr[size], a, b, max, min, count, count1;
    for (int i = 0; i < size; i++)
    {
        cout << "Введiть прибуток " << i + 1 << " мiсяця-> ";
        cin >> arr[i];
    }
    cout << "Введiть дiапозон(нижнiй i верхнiй):\n";
    cin >> a >> b;
    if ((a <= 0) || (a >= 13) || (b <= 0) || (b >= 13))
        cout << "Error!\n";
    a--;
    b--;
    min = arr[a];
    max = arr[a];
    for (int i=a;i < b; i++)
    {
       
        if (min < arr[i])
        {
            min = arr[i];
            count = i;
        }
      
    }
    cout << "Мiнiмум " << count << " мiсяць\n";
    a = count1;
    for (int i=a; i < b; i++)
    {

        if (arr[i] > arr[i])
        {
            max = arr[i];
            count = i;
        }
       
    }
    cout << "Максимум " << count << " мiсяць\n";
}

