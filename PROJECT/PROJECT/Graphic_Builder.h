#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<Windows.h>
#include"Abstact_Redactor.h"

using namespace std;
class Graphic_redactor;
class Graphic_Builder
{
protected:
	Graphic_redactor* redactor;
public:
	Graphic_Builder()
	{

	}
	Graphic_redactor* Get_Graphic_redactor()
	{
		return redactor;
	}
	
	virtual void Build_format() = 0;
};