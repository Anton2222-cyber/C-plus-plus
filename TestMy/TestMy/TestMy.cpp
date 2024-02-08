#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string.h>
#include<vector>
#include<fstream>
using namespace std;

struct ITINERARY
{
	string FIRST;
	string FINAL;
	string NUM;
	float DISTANCE;
	ITINERARY(string FIRST, string FINAL, string NUM, float DISTANCE)
	{
		this->FIRST = FIRST;
		this->FINAL = FINAL;
		this->NUM = NUM;
		this->DISTANCE = DISTANCE;
	}
	void PrintInfo()
	{
		cout << FIRST << " ->" << FINAL << " Номер: " << NUM << " відстань: " << DISTANCE << "км\n";
	}
};
struct ITINERARYs
{
	vector<ITINERARY*> itinerarys;
	ITINERARYs()
	{
		
	}
	~ITINERARYs()
	{
		for (int i = 0; i < itinerarys.size(); i++)
		{
			delete itinerarys[i];
		}
	}
	void Add(ITINERARY* it)
	{
		itinerarys.push_back(it);
	}
	void Delete(string FIRST, string FINAL, string NUM)
	{
		bool b = false;
		for (int i = 0; i < this->itinerarys.size(); i++)
		{
			if (itinerarys[i]->FIRST == FIRST && itinerarys[i]->FINAL == FINAL && itinerarys[i]->NUM == NUM)
			{
				
				itinerarys.erase(itinerarys.begin() + i);
				cout << "Видалено!\n";
				b = true;
				break;
			}
		}
		if (!b)
			cout << "Не знайдено!\n";
	}
	void Search_By_FIRST(string FIRST)
	{
		bool b = false;
		for (int i = 0; i < itinerarys.size(); i++)
		{
			if (itinerarys[i]->FIRST == FIRST)
			{
				itinerarys[i]->PrintInfo();
				b = true;
			}
		}
		if(!b)
			cout << "Не знайдено!\n";
	}
	void ReadAll()
	{
		fstream f("baza.txt", ios::in);
		
		string FIRST;
		string FINAL;
		string NUM;
		float DISTANCE;
		itinerarys.clear();
		while (!f.eof())
		{
			f >> FIRST;
			f >> FINAL;
			f >> NUM;
			f >> DISTANCE;
			itinerarys.push_back(new ITINERARY(FIRST, FINAL, NUM, DISTANCE));
		}
		f.close();
	}
	void SaveAll()
	{
		fstream f("baza.txt", ios::out);
		for (int i = 0; i < itinerarys.size(); i++)
		{
			f << endl << itinerarys[i]->FIRST << " " << itinerarys[i]->FINAL<<" "<< itinerarys[i]->NUM<<" "<< itinerarys[i]->DISTANCE;
		}
		f.close();
	}
	void Search_By_FINAL(string FINAL)
	{
		bool b = false;
		for (int i = 0; i < itinerarys.size(); i++)
		{
			if (itinerarys[i]->FINAL == FINAL)
			{
				itinerarys[i]->PrintInfo();
				b = true;
			}
		}
		if (!b)
			cout << "Не знайдено!\n";
	}
	void Search_By_NUM(string NUM)
	{
		bool b = false;
		for (int i = 0; i < itinerarys.size(); i++)
		{
			if (itinerarys[i]->NUM == NUM)
			{
				itinerarys[i]->PrintInfo();
				b = true;
			}
		}
		if (!b)
			cout << "Не знайдено!\n";
	}
	void Search_By_DISTANCE(float DISTANCE)
	{
		bool b = false;
		for (int i = 0; i < itinerarys.size(); i++)
		{
			if (itinerarys[i]->DISTANCE == DISTANCE)
			{
				itinerarys[i]->PrintInfo();
				b = true;
			}
		}
		if (!b)
			cout << "Не знайдено!\n";
	}
	void PrintAll()
	{
		for (int i = 0; i < this->itinerarys.size(); i++)
		{
			itinerarys[i]->PrintInfo();
		}
	}
	void Redact(string FIRST, string FINAL, string NUM)
	{
		int k = 0;
		string tmp;
		float km;
		bool b = false;
		for (int i = 0; i < this->itinerarys.size(); i++)
		{
			if (itinerarys[i]->FIRST == FIRST && itinerarys[i]->FINAL == FINAL && itinerarys[i]->NUM == NUM)
			{
				b = true;
				cout << "Редагувати назву початкового маршруту->1\nРедагувати назву кінцевого маршруту->2\nРедагувати номер маршруту->3\nРедагувати відстань->4\nВихід->0\n";
				cout << "->";
				cin >> k;
				system("cls");
				while (k != 0)
				{
					switch (k)
					{
					case 1:
						cout << "Ведіть нову назву початкового маршруту->";
						cin >> tmp;
						itinerarys[i]->FIRST = tmp;
						break;
					case 2:
						cout << "Ведіть нову назву кінцевого маршруту->";
						cin >> tmp;
						itinerarys[i]->FINAL = tmp;
						break;
					case 3:
						cout << "Ведіть новий номер маршруту->";
						cin >> tmp;
						itinerarys[i]->NUM = tmp;
						break;
					case 4:
						cout << "Ведіть відстань(у км), на яку хочете змінити->";
						cin >> km;
						itinerarys[i]->DISTANCE = km;
						break;
					}
					system("cls");
					cout << "Успішно змінено!\n";
					cout << "Редагувати назву початкового маршруту->1\nРедагувати назву кінцевого маршруту->2\nРедагувати номер маршруту->3\nРедагувати відстань->4\nВихід->0\n";
					cout << "->";
					cin >> k;
					system("cls");
				}
			}
		}
		if (!b)
			cout << "Не знайдено!"<<endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string FIRST;
	string FINAL;
	string NUM;
	float DISTANCE;
	ITINERARYs it;
	int k = 0;
	cout << "Додати запис->1\nЗнайти за назвою початкового маршруту->2\nЗнайти за назвою кінцевого маршруту->3\nЗнайти за номером маршруту->4\nЗнайти за відстанню->5\nРедагувати запис->6\nЗберегти записи->7\nЗчитати записи->8\nПоказати всі записи->9\nВидалити запис->10\nВихід->0\n";
	cout << "->";
	cin >> k;
	system("cls");
	while (k != 0)
	{
		switch (k)
		{
		case 1:
			cout << "Введіть назву початкового маршруту->";
			cin >> FIRST;
			cout << "Введіть назву кінцевого маршруту->";
			cin >> FINAL;
			cout << "Введіть номер маршруту->";
			cin >> NUM;
			cout << "Введіть відстань(у км)->";
			cin >> DISTANCE;
			system("cls");
			it.Add(new ITINERARY(FIRST, FINAL, NUM, DISTANCE));
			cout << "Додано!\n";
			break;
		case 2:
			cout << "Введіть назву початкового маршруту->";
			cin >> FIRST;
			system("cls");
			it.Search_By_FIRST(FIRST);
			break;
		case 3:
			cout << "Введіть назву кінцевого маршруту->";
			cin >> FINAL;
			system("cls");
			it.Search_By_FINAL(FINAL);
			break;
		case 4:
			cout << "Введіть номер маршруту->";
			cin >> NUM;
			system("cls");
			it.Search_By_NUM(NUM);
			break;
		case 5:
			cout << "Введіть відстань(у км)->";
			cin >> DISTANCE;
			system("cls");
			it.Search_By_DISTANCE(DISTANCE);
			break;
		case 6:
			cout << "Введіть назву початкового маршруту->";
			cin >> FIRST;
			cout << "Введіть назву кінцевого маршруту->";
			cin >> FINAL;
			cout << "Введіть номер маршруту->";
			cin >> NUM;
			system("cls");
			it.Redact(FIRST, FINAL, NUM);
			break;
		case 7:
			it.SaveAll();
			cout << "Збережено!\n";
			break;
		case 8:
			it.ReadAll();
			cout << "Зчитано!\n";
			break;
		case 9:
			it.PrintAll();
			break;
		case 10:
			cout << "Введіть назву початкового маршруту->";
			cin >> FIRST;
			cout << "Введіть назву кінцевого маршруту->";
			cin >> FINAL;
			cout << "Введіть номер маршруту->";
			cin >> NUM;
			system("cls");
			it.Delete(FIRST, FINAL, NUM);
			break;
		}
		cout << "Додати запис->1\nЗнайти за назвою початкового маршруту->2\nЗнайти за назвою кінцевого маршруту->3\nЗнайти за номером маршруту->4\nЗнайти за відстанню->5\nРедагувати запис->6\nЗберегти записи->7\nЗчитати записи->8\nПоказати всі записи->9\nВидалити запис->10\nВихід->0\n";
		cout << "->";
		cin >> k;
		system("cls");
	}

	system("pause");
	return 0;
}