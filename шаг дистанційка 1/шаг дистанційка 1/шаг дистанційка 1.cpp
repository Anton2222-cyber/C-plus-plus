// шаг дистанційка 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	setlocale(0, "");
	char a;
	float x, y, b;
	cout << "Введите операцию"<<endl;
	cin >> x >> a >> y;
	switch (a) {
	case '+':
		cout << "сложение" << endl;
		b = x + y;
		cout << "Результат="<<b << endl;
		break;
	case '-':
		cout << "вычитание" << endl;
		b = x - y;
		cout << "Результат=" << b << endl;
		break;
	case '*':
		cout << "умножение" << endl;
		b = x * y;
		cout << "Результат=" << b << endl;
		break;
	case '/':
		cout << "деление" << endl;
			b = x / y;
		cout << "Результат=" << b << endl;
		break;
	default: cout << "Error"<<endl;
	}
}

