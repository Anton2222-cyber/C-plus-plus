
#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    srand(time(0));
    int arr[10], x, k;

    for (int i = 0; i < 10; i++)
    {
        x = rand() % 100;
        cout << x << " ";
        arr[i] = x;
    }

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        x = arr[i];
        k = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (x > arr[j])
            {
                x = arr[j];
                k = j;
            }
        }
       x = arr[i];
        arr[i] = arr[k];
        arr[k] = x;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";

    }

    cout << endl;
}