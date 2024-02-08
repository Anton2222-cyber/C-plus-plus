// function users full.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void Print(char a = '*', int b = 1)
{
	int count = 1;
	if (b == 1) {
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cout << a;
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 1; i <= 4; i++)
		{
			if (count == 3)
			{
				cout << a;
				for (int k = 0; k < 2; k++)
					cout << " ";
				cout << a;
				cout << endl;
				count+=2;
				continue;
			}
			for (int j = 0; j < count; j++)
			{
				cout << a;
			}
			count++;
			cout << endl;
		}
	}
}

void Print(int a = 0, char b='*', int k=0)
{
	int count = 5;
	if (a == 1)
	{


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4 - i; j++)
			{
				cout << b;
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 1; i <= 4; i++)
		{
			if (i == 2)
			{
				cout << b;
				for (; k < 2; k++)
					cout << " ";
				cout << b;
				count -= 2;
				cout << endl;
				continue;
			}

			for (int j = 0; j < count; j++)
			{
				cout << b;
			}
			count--;
			cout << endl;
		}
	}
}

void Print(int a, int b, int c=1, char d = '*')
{
	if (c == 1) 
	{
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 4 - i; j++)
				cout << " ";

			for (int k = 1; k <= i; k++)
				cout << d;
			cout << endl;
		}
	}
	else
	{
		for (int i = 1; i <= 4; i++)
		{
			if(i!=4&&i!=3)
			for (int j = 0; j < 5 - i; j++)
				cout << " ";
			
			if (i == 3)
			{
				cout << " ";
				cout << d;
				cout << "  ";
				cout << d;
				cout << endl;
				a +=2;
				continue;
			}
			for (int k = 0; k < a; k++)
				cout << d;
			cout << endl;
			a++;
		}
	}

}
void Print(double a, float b, char c = '*')
{
	int count = 0;
	if (a == 1.2) 
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < count; j++)
			{
				cout << " ";
			}
			count++;
			for (int k = 0; k < 4 - i; k++)
			{
				cout << c;
			}
			cout << endl;

		}
	}
	else
	{
		for (int i = 1; i <= 4; i++)
		{
			if(i!=2 && i!=1)
			for (int j = 0; j < count+1; j++)
			{
				cout << " ";
			}
			count++;
			if (i == 2)
			{
				cout << " ";
				cout << c;
				cout << "  ";
				cout << c;
				cout << endl;
				continue;
			}
			if (i == 1)
			{
				for (int k = 0; k < 5; k++)
				{
					cout << c;
				}
				cout << endl;
				continue;
			}
			for (int l = 0; l < 5 - i; l++)
			{
				cout << c;
			}
			cout << endl;

		}
	}
	
}
void Print(int a, int b, int c, int d, int f = 1, char o='*')
{
	int count;
	if (f == 1) 
	{
		for (int i = 1, count = 3, count2 = 1; i <= 4; i++)
		{
			for (int j = 0; j < count; j++)
			{
				cout << " ";
			}
			count--;
			for (int k = 0; k < count2; k++)
			{
				cout << o;
			}
			count2 += 2;
			cout << endl;
		}
	}
	else if(f==2)
	{
		for (int i = 1, count=0, count2=7; i <= 4; i++)
		{
			for (int j = 0; j < count; j++)
			{
				cout << " ";
			}
			count++;
			for (int k = 0; k < count2; k++)
			{
				cout << o;
			}
			count2 -= 2;
			cout << endl;
		}
	}
	else if (f == 3)
	{
		for (int i = 1, count=3, count2=1; i <= 4; i++)
		{
			for (int j = 0; j < count; j++)
			{
				cout << " ";
			}
			count--;
			if (i == 2 )
			{
				cout << o;
				cout << " ";
				cout << o;
				cout << endl;
				count2 += 2;
				continue;
			}
			else if (i == 3)
			{
				cout << o;
				cout << "   ";
				cout << o;
				cout << endl;
				count2 += 2;
				continue;
			}
			for (int k = 0; k < count2; k++)
			{
				cout << o;
			}
			count2 += 2;
			cout << endl;

		}
	}
	else if (f == 4)
	{
		for (int i = 1, count = 0, count2 = 7; i <= 4; i++)
		{
			for (int j = 0; j < count; j++)
			{
				cout << " ";
			}
			count++;
			if (i == 2)
			{
				cout << o;
				cout << "   ";
				cout << o;
				cout << endl;
				count2 -= 2;
				continue;
			}
			else if (i == 3)
			{
				cout << o;
				cout << " ";
				cout << o;
				cout << endl;
				count2 -= 2;
				continue;

			}
			for (int k = 0; k < count2; k++)
			{
				cout << o;
			}
			count2 -= 2;
			cout << endl;
		}
	}
	else if (f == 5)
	{
	  for (int i = 1; i <= 3; i++)
	{
		if (i == 1 || i == 3)
		{
			cout << " ";
			cout << o;
			cout << endl;
			continue;
		}
		for (int j = 0; j < 3; j++)
		{
			cout << o;
		}
		cout << endl;

	  }
    }
	else if (f == 6)
	{
	for (int i = 1; i <= 3; i++)
	{
		if (i == 1 || i == 3)
		{
			cout << " ";
			cout << o;
			cout << endl;
		}
		else
		{
			cout << o;
			cout << " ";
			cout << o;
			cout << endl;
		}
	}
    }
}
int main()
{
	setlocale(0, "");
	Print('*');
	cout << endl;
	Print('*',0);
	cout << endl;
	Print(1);
	cout << endl;
	Print(0);
	cout << endl;
	Print(0, 0);
	cout << endl;
	Print(1, 0, 0);
	cout << endl;
	Print(1.2, 4.5);
	cout << endl;
	Print(1.5, 4.5);
	cout << endl;
	Print(1,1,1,1);
	cout << endl;
	Print(2, 2, 2, 2,2);
	cout << endl;
	Print(3, 3, 3, 3, 3);
	cout << endl;
	Print(4, 4, 4, 4, 4);
	cout << endl;
	Print(5, 5, 5, 5, 5);
	cout << endl;
	Print(6, 6, 6, 6, 6);
	return 0;
}
