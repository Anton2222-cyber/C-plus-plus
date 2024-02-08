#define _CRT_SECURE_NO_WARNINGS
#include "Error.h"
#include<iostream>
using namespace std;
Error::Error(int code, const char* name)
{
	this->code = code;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Error::~Error()
{
	if (name != NULL)
		delete[]name;
}
void Error::Show()
{
	cout << this->code << " " << this->name << endl;
}