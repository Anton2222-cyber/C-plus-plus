#pragma once
#include "Graphic_Builder.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Png_Builder:public Graphic_Builder
{
public:
	Png_Builder(){}
	void Build_format()
	{
		cout << "«бер≥гаЇмо файл в формат≥ png\n";
	}
};