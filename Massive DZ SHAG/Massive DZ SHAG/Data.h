#pragma once
#include<string>
#include <iostream>
using namespace std;
class Data
{
protected:
	string name;

public:
	virtual void Show(int a) = 0;
	virtual string GetName() = 0;
	virtual int Get_Size() = 0;
};