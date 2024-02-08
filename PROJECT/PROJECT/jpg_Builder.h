#pragma once
#include "Graphic_Builder.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Jpg_Builder :public Graphic_Builder
{
public:
	Jpg_Builder(){}
	void Build_format()
	{
		cout << "«бер≥гаЇмо файл в формат≥ jpg\n";
	}
};