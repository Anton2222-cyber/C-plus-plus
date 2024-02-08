#pragma once
#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 3;
const int WIDTH_MAP = 3;
#define size 3
int arr[HEIGHT_MAP][WIDTH_MAP] = { 0 };

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