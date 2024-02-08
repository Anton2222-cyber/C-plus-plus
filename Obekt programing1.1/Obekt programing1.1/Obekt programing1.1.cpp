// Obekt programing1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#define size 100
using namespace std;
class group
{
	string Name;
	int Number;
public:
	group(string a, int b)
	{
		Name = a;
		Number = b;
	}
	void Print()
	{
		cout << "Назва групи - " << Name << endl;
		cout << "Кiлькiсть студентiв/студенток - " << Number << endl;
	}
	
};
class Students
{ 
	string Lastname[size];
	string Firstname[size];
	string Surname[size];
public:
	Students(string a, string b, string c, int i)
	{
		--i;
		Lastname[i] = a;
		Firstname[i] = b;
		Surname[i] = c;

	}
	Students(int a)
	{
		cout << "Прiзвище студента/студентки - " << Lastname[a] << endl;
		cout << "Iм'я студента/студентки - " << Firstname[a] << endl;
		cout << "По-батьковi студента/студентки - " << Surname[a] << endl;
	}
	

};


int main()
{
	setlocale(0, "");
	int k, temp2;
	string a, b, c, name;
	cout << "Введiть назву групи\n";
	cout << "->";
	cin >> name;
	cout << "Скiльки у групi студентiв/студенток?\n";
	cout << "->";
	cin >> k;
	group (name, k);
	for (int i = 1; i <=k; i++)
	{
		cout << "Введiть прiзвище, iм'я, по-батьковi " << i << " студента/студентки\n";
		cin >> a >> b >> c;
		Students (a, b, c, i);
	}
    group Print();
	for (int i = 0; i < k; i++)
	{
		cout << i + 1 << " Студент/студентка\n";
		Students о(i);
	}
  
	return 0;
}



