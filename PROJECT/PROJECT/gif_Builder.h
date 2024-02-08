#pragma once
#include "Graphic_Builder.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Gif_Builder :public Graphic_Builder
{
public:
	Gif_Builder(){}
	void Build_format()
	{
		cout << "«бер≥гаЇмо файл в формат≥ gif\n";
	}
};