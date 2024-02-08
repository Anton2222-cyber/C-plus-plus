

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(0, "");
    std::cout << "Hello World!\n";
    int a;
    cout << "1 - аквамариновий фон, червоний шрифт \n";
    cout << "2 - синiй фон, зелений шрифт\n";
    cout << "3 - синiй фон, червоний шрифт\n";
    cout << "4 - рожевий фон, свiтло-жовтий шрифт\n";
    cout << "5 - чорний фон, червоний шрифт\n";
    cout << "6 - синiй фон, свiтло-жовтий шрифт\n";
    cout << "7 - сiрий фон, бiлий шрифт\n";
    cin >> a;
    switch (a) {
    case 1: system("color B4");
        cout << "Hello World" << endl;
        break;
    case 2: system("color 12");
        cout << "Hello World" << endl;
        break;
    case 3: system("color 15");
        cout << "Hello World" << endl;
        break;
    case 4: system("color 5E");
        cout << "Hello World" << endl;
        break;
    case 5: system("color 04");
        cout << "Hello World" << endl;
        break;
    case 6: system("color 1E");
        cout << "Hello World" << endl;
        break;
    case 7: system("color 87");
        cout << "Hello World" << endl;
        break;
    default: cout << "Error!" << endl;

    }
}

