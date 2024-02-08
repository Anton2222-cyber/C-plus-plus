
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include<list>
#include<vector>
#include<map>
#include"time.h"
#include<algorithm>
#include<iterator>
#include"DirectoryComposite.h"
#include<io.h>
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	
		DirectoryComposite a;
		string place;
		cout << "Введіть місцерозташування ->";
		getline(cin, place);
		cout << "\t\tДерево каталогів\n";
		a.ADDDIR(place);
		a.Show();
	
	system("pause");
	return 0;
}


