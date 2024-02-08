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
#define size 11

int* Add(int* arr, int* s, int a)
{
	int* temp = new int[++(*s)];
	for (int i = 0; i < *s - 1; i++)
	{
		temp[i] = arr[i];

	}
	temp[*s - 1] = a;
	delete[] arr;
	return temp;
}
void Print(int* arr, const int s)
{
	cout << "Ваші карти: ";
	for (int i = 0; i < s; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int s = 1;
	int* player_koloda = new int[s];
	int player, pk, number_pk = 1;
	int koloda[size] = { 3,5,1,7,2,6,9,11,4,10,8 };
	int a = rand() % 21;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < size - 2; j++)
		{
			int temp = koloda[j];
			koloda[j] = koloda[j + 2];
			koloda[j + 2] = temp;
		}
	}

	player = koloda[0];
	player_koloda[0] = koloda[0];
	pk = koloda[1];
	int b, i;
	for (i = 2; i < size;)
	{
		if (pk >= 18)
			cout << "Супротивник пасує!\n";
		if (pk < 18)
		{
			pk += koloda[i];
			i++;
			number_pk++;
			cout << "Супротивник набрав\n";
			b = false;
		}

		cout << "Карт у супротивника: " << number_pk << endl;
		Print(player_koloda, s);
		cout << "Ваші очки: " << player << endl;
		cout << "Набрати ще одну - |1|, пас - |2|\n";
		cout << "->";
		cin >> b;
		if (b == 1)
		{
			player_koloda = Add(player_koloda, &s, koloda[i]);
			player += koloda[i];
			i++;

		}
		else
			break;
	}

	while (i < size)
	{
		if (pk < 18)
		{
			pk += koloda[i];
			i++;
			number_pk++;
			cout << "Супротивник набрав\n";
			cout << "Карт у супротивника: " << number_pk << endl;
		}
		else
		{
			cout << "Супротивник пасує!\n";
			break;
		}

	}

	if (player > 21 && pk > 21)
	{
		if (player < pk)
			cout << "Ви виграли!\n";
		else if (player == pk)
			cout << "Нічия!\n";
		else
			cout << "Ви програли!\n";
	}
	else if (player > 21)
		cout << "Ви програли!\n";
	else if (pk > 21)
		cout << "Ви виграли!\n";
	else if (player > pk)
		cout << "Ви виграли!\n";
	else if (player < pk)
		cout << "Ви програли!\n";
	else if (player == pk)
		cout << "Нічия!\n";
	delete[] player_koloda;
	cin.ignore();
	system("Pause");
	return 0;
}