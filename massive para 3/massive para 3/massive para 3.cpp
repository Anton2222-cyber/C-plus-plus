// massive para 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
#include<time.h>

using namespace std;
#define size 4
#define size2 5
int main()
{
    setlocale(0, "");
    srand(time(0));

    int arr[size][size2], x, a, temp, count=1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            arr[i][j] = rand() % 10;
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
    cout << "Куди зрушення?\n";
    cout << "Вверх - |1|, вниз - |2|, вправо - |3|, влiво - |4|\n";
    cout << "->";
    cin >> x;
    switch (x)
    {
    case 1:cout << "Скiльки зрушень бажаєте отримати?\n";
        cout << "->";
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            for (int j = size-1; j >=0; j--)
            {
                if (j == 0)
                    count = 0;
                for(int k=0; k<size2; k++)
                {
                    temp = arr[size - 1][k];
                    arr[size - 1][k] = arr[size - 1 - count][k];
                    arr[size - 1 - count][k] = temp;
                    
                }
                count++;
            }
           
            count = 1;

        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        break;
    case 2:
        cout << "Скiльки зрушень бажаєте отримати?\n";
        cout << "->";
        cin >> a;
        for (int k = 0; k < a; k++)
        {
            for (int i = 0; i < size; i++)
            {
                if (i == size - 1)
                    count = 0;

                for (int j = 0; j < size2; j++)
                {
                    temp = arr[0][j];
                    arr[0][j] = arr[count][j];
                    arr[count][j] = temp;
                }
                count++;
                
            }
            count = 1;

            
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        break;
    case 3:cout << "Скiльки зрушень бажаєте отримати?\n";
        cout << "->";
        cin >> a;
        for (int k = 0; k < a; k++)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size2-1; j++)
                {
                    temp = arr[i][0];
                    arr[i][0] = arr[i][j + count];
                    arr[i][j + count] = temp;
                }
                count = 1;
            }

        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        break;
    case 4:cout << "Скiльки зрушень бажаєте отримати?\n";
        cout << "->";
        cin >> a;
        for (int k = 0; k < a; k++)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = size2 - 1; j > 0; j--)
                {
                  
                    temp = arr[i][size2 - 1];
                    arr[i][size2 - 1] = arr[i][size2 - count - 1];
                    arr[i][size2 - count - 1] = temp;
                    count++;
                }
                count = 1;
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        break;
    default: cout << "Error!\n";
    }
   
}

