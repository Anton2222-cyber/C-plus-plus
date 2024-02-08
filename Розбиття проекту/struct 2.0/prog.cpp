#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<direct.h>
#include<io.h>
#include<time.h>
#include "function.h"
using namespace std;

#define size 20


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	float arr[size];
	Set_random(size, arr);
	Print_arr(arr, size);
	Min_by_arr(arr, size);
	Max_by_arr(arr, size);
	quickSortR(arr, size-1);
	Print_arr(arr, size);
	Red_edit(arr, size);
	Print_arr(arr, size);
	return 0;
}

