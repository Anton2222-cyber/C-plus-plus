#pragma once
#include"Data.h"
#include <iostream>
using namespace std;
class File :public Data
{

public:
	File(string n)
	{
		this->name = n;
	}
	void Show(int a)
	{
		cout << this->name<<endl;
	}
	string GetName()
	{
		return name;
	}
	int Get_Size()
	{
		return 0;
	}
};