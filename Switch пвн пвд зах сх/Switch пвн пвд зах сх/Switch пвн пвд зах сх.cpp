#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(0, "");
    char a;
    int b;
	cout << "Введите одну из сторон света(«N» – север, «W» – запад, «S» – юг, «E» – восток):\n";
	cin >> a;
	switch (a)
	{
	   case 'N':cout << "1 – поворот налево, 2 – поворот направо, 3 – поворот на 180 градусов\n";
		cin >> b;
		switch (b)
	    {
		   case 1: cout << "Вы на западе\n";
		   break;
		   case 2: cout << "Вы на востоке\n";
		   break;
		   case 3: cout << "Вы на юге\n";
		   break;
		   default: cout << "Error!\n";
	    }
		break;
	   case 'W': cout << "1 – поворот налево, 2 – поворот направо, 3 – поворот на 180 градусов\n";
		   cin >> b;
		   switch (b)
		   {
		    case 1: cout << "Вы на юге\n";
			   break;
		    case 2: cout << "Вы на севере\n";
			   break;
		    case 3: cout << "Вы на востоке\n";
			   break;
		    default: cout << "Error!\n";
		   }
		   break;
	   case 'S': cout << "1 – поворот налево, 2 – поворот направо, 3 – поворот на 180 градусов\n";
		   cin >> b;
		   switch (b)
		   {
		    case 1: cout << "Вы на востоке\n";
			   break;
		    case 2: cout << "Вы на западе\n";
			   break;
		    case 3: cout << "Вы на севере\n";
			   break;
		    default: cout << "Error!\n";
		   }
		   break;
	   case 'E': cout << "1 – поворот налево, 2 – поворот направо, 3 – поворот на 180 градусов\n";
		   cin >> b;
		   switch (b)
		   {
		   case 1: cout << "Вы на севере\n";
			   break;
		   case 2: cout << "Вы на юге\n";
			   break;
		   case 3: cout << "Вы на западе\n";
			   break;
		   default: cout << "Error!\n";
		   }
		   break;
	   default: cout << "Error!\n";
	}
}