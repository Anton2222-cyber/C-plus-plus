#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<Windows.h>
#include"Super_Redactor.h"


using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*Super_Redactor* r = new Txt_Factory();
	r->Work();*/
	Super_Redactor* r = new Graphic_Factory();
	r->Print_Triangle();
	r->Work();
	


	delete r;
	return 0;
}
