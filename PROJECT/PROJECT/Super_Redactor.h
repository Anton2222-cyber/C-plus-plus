#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<Windows.h>
#include"Abstact_Redactor.h"



using namespace std;
class Super_Redactor
{
protected:
	virtual AbstractRedactor* DoRedactor() = 0;
public:
	void Print_Square()
	{
		cout << "� �������\n";
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}
	void Print_Triangle()
	{
		cout << "� ���������\n";
		int k = 1;
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				cout << "*";
			}
			k++;
			cout << endl;
		}
		cout << endl;
	}

	void Work()
	{

		int a;
		AbstractRedactor* ar = DoRedactor();
		cout << "----------------------------------------------------\n";
		cout << "�� ������� �������?\n�������� ���� ->1\n³������ ���� ->2\n�������� ���� ->3\n�������� �� ����� ������ ->4\n���� ->5\n������� ���� ->6\n����� ->0\n";
		cout << "->";
		cin >> a;
		cout << "----------------------------------------------------\n";
		while (a)
		{
			switch (a)
			{
			case 1:
				ar->Create();
				break;
			case 2:
				ar->Open();
				break;
			case 3:
				ar->Save();
				break;
			case 4:
				ar->Save_with_new_name();
				break;
			case 5:
				ar->Print();
				break;
			case 6:
				ar->Close();
				break;
			}
			cout << "----------------------------------------------------\n";
			cout << "�� ������� �������?\n�������� ���� ->1\n³������ ���� ->2\n�������� ���� ->3\n�������� �� ����� ������ ->4\n���� ->5\n������� ���� ->6\n����� ->0\n";
			cout << "->";
			cin >> a;
			cout << "----------------------------------------------------\n";
		}
		delete ar;

	}
};
class Txt_Factory :public Super_Redactor
{
public:
	AbstractRedactor* DoRedactor()
	{
		return new Txt_redactor();
	}
};
class Graphic_Factory :public Super_Redactor
{
public:
	AbstractRedactor* DoRedactor()
	{
		return new Graphic_redactor();
	}
};