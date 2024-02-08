#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<Windows.h>
//#include"Graphic_Builder.h"
#include"Graphic_Constructor.h"
#include"jpg_Builder.h"
#include"png_Builder.h"
#include"gif_Builder.h"

using namespace std;
class AbstractRedactor
{
public:
	AbstractRedactor() {};
	void Create()
	{
		cout << "‘айл створено!\n";
	}
	virtual void Open() = 0;
	virtual void Save() = 0;
	virtual void Save_with_new_name() = 0;
	void Print()
	{
		cout << "≤де друк...\n";
	}
	void Close()
	{
		cout << "‘айл закрито\n";
	}
};
class Txt_redactor :public AbstractRedactor
{
public:
	Txt_redactor()
	{

	}
	void Open()
	{
		cout << "‘айл в≥дкрито в текстовому режим≥\n";
	}
	void Save()
	{
		cout << "«бережено €к текстовий документ\n";
	}
	void Save_with_new_name()
	{
		string name_file;
		cout << "¬вед≥ть нову назву файлу ->";
		cin >> name_file;
		cout << "“екстовий файл збережено з новим ≥менем (" << name_file << ")\n";
	}
};
class Graphic_redactor :public AbstractRedactor
{
public:
	Graphic_redactor()
	{

	}
	void Open()
	{
		cout << "‘айл в≥дкрито в граф≥чному режим≥\n";
	}
	void Save()
	{
		int a;
		Graphic_Builder* builder=NULL;
		cout << "як зберегти?(1-png,2-jpg,3-gif)\n";
		cout << "->";
		cin >> a;
		Graphic_Constructor* shop = new Graphic_Constructor();
		switch (a)
		{
		case 1:
			builder = new Png_Builder();
			break;
		case 2:
			builder = new Jpg_Builder();
			break;
		case 3:
			builder = new Gif_Builder();
			break;
		}
		shop->Save_As(builder);
		delete shop;
		delete builder;
	}
	void Save_with_new_name()
	{
		string name_file;
		cout << "¬вед≥ть нову назву файлу ->";
		cin >> name_file;
		cout << "√раф≥чний файл збережено з новим ≥менем (" << name_file << ")\n";
	}
};