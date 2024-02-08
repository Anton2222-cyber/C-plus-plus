#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<direct.h>
#include<io.h>
#include<time.h>


using namespace std;
#define size 3
void Move_instruction()
{
	cout << "Позиції клітинок:\n";
	cout << "1 2 3\n4 5 6\n7 8 9\n";

}

void Get_x_y(int a, int* x, int* y)
{
	switch (a)
	{
	case 1:
		*x = 0;
		*y = 0;
		break;
	case 2:
		*x = 0;
		*y = 1;
		break;
	case 3:
		*x = 0;
		*y = 2;
		break;
	case 4:
		*x = 1;
		*y = 0;
		break;
	case 5:
		*x = 1;
		*y = 1;
		break;
	case 6:
		*x = 1;
		*y = 2;
		break;
	case 7:
		*x = 2;
		*y = 0;
		break;
	case 8:
		*x = 2;
		*y = 1;
		break;
	case 9:
		*x = 2;
		*y = 2;
		break;

	}

}
bool Win_or_not_win(int arr[][size], int k)
{

	int sum = 0;
	//по горизонталі
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == k)
				sum++;
		}
		if (sum == 3)
			return true;
		sum = 0;
	}

	//по вертикалі
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[j][i] == k)
				sum++;
		}
		if (sum == 3)
			return true;
		sum = 0;
	}

	//по головній діагоналі

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				if (arr[i][j] == k)
					sum++;
			}

		}
	}
	if (sum == 3)
		return true;
	sum = 0;
	//по бічній діагоналі
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == size - 1 - i)
			{
				if (arr[i][j] == k)
					sum++;
			}
		}
	}
	if (sum == 3)
		return true;
	return false;
}


void Print(int arr[][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 1)
				cout << "X ";
			else if (arr[i][j] == 2)
				cout << "O ";
			else
				cout << "- ";

		}
		cout << endl;
	}
	cout << endl;
	cout << "((((((((((((((((((((((((((((((((((((((((((((((((((((\n";
}


void Human_vs_human(int arr[][size])
{
	int x, y;
	for (int i = 1, hodu = 0;;)
	{
		cout << "1-гравець робіть ваш хід\n";
		cout << "->";
		cin >> x;
		while (x < 1 || x>9)
		{
			cout << "Не коректний ввід!Введіть ще раз(позиція повинна бути в діапазоні від 1 до 9 включно)\n";
			cout << "->";
			cin >> x;
		}
		Get_x_y(x, &x, &y);
		i++;
		while (arr[x][y] == 1 || arr[x][y] == 2)
		{
			cout << "Ця клітинка зайнята! Виберіть іншу\n";
			cout << "->";
			cin >> x;
			Get_x_y(x, &x, &y);
		}
		arr[x][y] = 1;
		cout << endl;
		Print(arr);
		if (i >= 3)
		{
			if (Win_or_not_win(arr, 1))
			{
				cout << "1-гравець переміг!!!\n";
				break;
			}
		}
		hodu++;
		if (hodu == 9)
		{
			cout << "Нічия!\n";
			break;
		}
		cout << "2-гравець робіть ваш хід(вкажіть координати x та у)\n";
		cout << "->";
		cin >> x;
		while (x < 1 || x>9)
		{
			cout << "Не коректний ввід!Введіть ще раз(позиція повинна бути в діапазоні від 1 до 9 включно)\n";
			cout << "->";
			cin >> x;
		}
		Get_x_y(x, &x, &y);
		i++;
		while (arr[x][y] == 1 || arr[x][y] == 2)
		{
			cout << "Ця клітинка зайнята! Виберіть іншу\n";
			cout << "->";
			cin >> x;
			Get_x_y(x, &x, &y);
		}
		cout << endl;
		arr[x][y] = 2;
		Print(arr);
		if (i >= 3)
		{
			if (Win_or_not_win(arr, 2))
			{
				cout << "2-гравець переміг!!!\n";
				break;
			}
		}
		hodu++;
		if (hodu == 9)
		{
			cout << "Нічия!\n";
			break;
		}
	}




}

void Null_masive(int arr[][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}

}

void Human_vs_computer(int arr[][size])
{
	int x, y;
	for (int i = 1, hodu = 0;;)
	{
		cout << "1-гравець робіть ваш хід\n";
		cout << "->";
		cin >> x;
		while (x < 1 || x>9)
		{
			cout << "Не коректний ввід!Введіть ще раз(позиція повинна бути в діапазоні від 1 до 9 включно)\n";
			cout << "->";
			cin >> x;
		}
		Get_x_y(x, &x, &y);
		i++;
		while (arr[x][y] == 1 || arr[x][y] == 2)
		{
			cout << "Ця клітинка зайнята! Виберіть іншу\n";
			cout << "->";
			cin >> x;
			Get_x_y(x, &x, &y);
		}
		arr[x][y] = 1;
		cout << endl;
		Print(arr);
		if (i >= 3)
		{
			if (Win_or_not_win(arr, 1))
			{
				cout << "1-гравець переміг!!!\n";
				break;
			}
		}
		hodu++;
		if (hodu == 9)
		{
			cout << "Нічия!\n";
			break;
		}
		cout << "ПК робить свій хід...\n";
		Sleep(1000);
		x = rand() % 9 + 1;
		Get_x_y(x, &x, &y);
		i++;
		while (arr[x][y] == 1 || arr[x][y] == 2)
		{
			x = rand() % 9 + 1;
			Get_x_y(x, &x, &y);
		}
		cout << endl;
		arr[x][y] = 2;
		Print(arr);
		if (i >= 3)
		{
			if (Win_or_not_win(arr, 2))
			{
				cout << "2-гравець переміг!!!\n";
				break;
			}
		}
		hodu++;
		if (hodu == 9)
		{
			cout << "Нічия!\n";
			break;
		}
	}



}

//хрестик|1| нулик|2|
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int list[size][size] = {}, a;
	cout << "Гра хрестики-нулики\n";
	Move_instruction();
	cout << "З ким грати?(з ПК - 1, з людиною - 2, вихід - 0)\n";
	cout << "->";
	cin >> a;
	while (a)
	{
		switch (a)
		{
		case 1:
			Human_vs_computer(list);
			break;
		case 2:
			Human_vs_human(list);
			break;
		}
		Null_masive(list);
		cout << "Ще раз зіграти?(з ПК - 1, з людиною - 2, вихід - 0)\n";
		cout << "->";
		cin >> a;

	}
	return 0;
}