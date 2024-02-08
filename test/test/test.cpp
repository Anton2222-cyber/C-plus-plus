#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include<conio.h>
#include<time.h>
#include"List.h"
#include"Error.h"
#include"Error_Delete_Empty.h"
#include"Error_Index_Delete.h"
#include"Error_Show_Empty.h"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	List<int> list;
	try
	{
		list.Delete_Someone(6);
	}
	catch(Error er)
	{
		er.Show();
	}

	return 0;
}