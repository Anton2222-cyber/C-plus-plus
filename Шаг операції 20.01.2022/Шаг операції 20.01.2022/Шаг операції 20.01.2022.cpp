// Шаг операції 20.01.2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	int a;
	cin >> a;
	/*for (int i = 0; i < a; i++)
	{

		for (int j = 0; j <= i; j++)
		{
			cout << "+";
			
		}
		cout << endl;
	}*/
	


	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= a-i; j++)
		{
			cout << " ";

		}
		for (int k = 1; k <= i; k++)
		{
			cout << "+";
		}
		cout << endl;
	}


}

