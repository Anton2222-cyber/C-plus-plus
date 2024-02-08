 #include <iostream>
using namespace std;
#define size 10
int main()
{
    setlocale(0, "");

    int arr[size], a=0, b;
    float sum=0;
    for (int i = 0; i < size; i++)
    {
        cout << "Введiть " << i + 1 << " оцінку-> ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Оцiнки\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    cout << "Потрібна перездача натисніть 0\n";
    cin >> a;
    if (a == 0)
    {
        cout << "Введiть номер оцiнки якої хочете перездати(вiд 1 до 10): ";
        cin >> b;
        arr[b + 1] = b;
    }
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    sum /= 10;
    if (sum >= 10.7)
    {
        cout << "Виходить стипендiя\n";
    }
    else
        cout << "Не виходить стипендiя\n";






























}/*int main()
{
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
}*/