#pragma once
#include "Graphic_Builder.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Graphic_Constructor
{
public:
	Graphic_Constructor()
	{
	}
	void Save_As(Graphic_Builder* builder)
	{
		builder->Build_format();
	}
};