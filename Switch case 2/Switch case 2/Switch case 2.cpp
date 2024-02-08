#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(0, "");
    cout << "1 - Катет\n";
    cout << "2 - Гипотенуза\n";
    cout << "3 - Высота опущенная из вершины прямого угла на гипотенузу\n";
    cout << "4 - Площадь\n";
    int c;
    float a, b;
    cin >> c;
    switch (c)
    {
    case 1: cout << "Введите катет:\n";
        cin >> a;
        cout << "Второй катет: " << a << endl;
        b = sqrt(a * a * 2);
        cout << "Гипотенуза: " << b << endl;
        cout << "Висота: " << (b / 2) << endl;
        cout << "Площадь: " << ((a*a)/2) << endl;
        break;
    case 2: cout << "Введите гипотенузу:\n";
        cin >> a;
        b = a/2;
        cout <<"Два катета по: "<< (sqrt(2 * b * b))<<endl;
        cout << "Висота: " << b << endl;
        cout << "Площадь: " << (b * b) << endl;
        break;
    case 3: cout << "Введите высоту:\n";
        cin >> a;
        b = sqrt(2 * a * a);
        cout << "Два катета по: " << b << endl;
        cout << "Гипотенуза: " <<(a*2) << endl;
        cout << "Площадь: " << ((b * b) / 2) << endl;
        break;
    case 4: cout << "Введите площадь:\n";
        cin >> a;
        b = sqrt(a);
        cout << "Два катета по: " << (sqrt(2 * b * b)) << endl;
        cout << "Гипотенуза: " << b*2 << endl;
        cout << "Висота: " << b << endl;
        break;
    default: cout << "Error!\n";
    }
}

