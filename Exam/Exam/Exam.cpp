#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class Cost
{
	string name;
	string category;
	float money;
	int day;
	int mis;
	int year;
public:
	void PrintInfo()
	{
		cout << "------------------------------------------\n";
		cout << name << endl;
		cout << category << endl;
		cout << money << "грн"<<endl;
		cout << day << "." << mis << "." << year << endl;
		cout << "------------------------------------------\n";
	}
	string Get_Name()
	{
		return name;
	}
	string Get_Category()
	{
		return category;
	}
	float& Get_Money()
	{
		return money;
	}
	int Get_Day()
	{
		return day;
	}
	int Get_Mis()
	{
		return mis;
	}
	int Get_Year()
	{
		return year;
	}
	Cost()
	{

	}
	Cost(string name, string category, float money, int day, int mis, int year)
	{
		this->name = name;
		this->category = category;
		this->money = money;
		this->day = day;
		this->mis = mis;
		this->year = year;
	}
	void AddCost(string name, string category, float money, int day, int mis, int year)
	{
		this->name = name;
		this->category = category;
		this->money = money;
		this->day = day;
		this->mis = mis;
		this->year = year;
	}
};
class SortByPrice
{
public:
	bool operator()(Cost* left, Cost* right)
	{
		return left->Get_Money() > right->Get_Money();
	}
};
class Card
{
	string name;
	string account;
	float balance;
	vector<Cost*> costs;
public:
	float& Get_Balance()
	{
		return balance;
	}
	Card(string name, string account, float balance)
	{
		this->name = name;
		this->account = account;
		this->balance = balance;
	}
	~Card()
	{
		for (auto it = costs.begin(); it != costs.end(); it++)
		{
			delete *it;
		}
	}
	void PrintInfo()
	{
		cout << name << " рахунок: " << account;
	}
	void SetCard(string name, string account, float balance)
	{
		this->name = name;
		this->account = account;
		this->balance = balance;
	}
	void AddCost(Cost* cost)
	{
		this->costs.push_back(cost);
	}
	void ShowZvitDay(int day, int mis, int year)
	{
		string txt;
		txt += "Витрати за конкретний день\n";
		txt += "---------------------------------------\n";
		int k;
		for (int i = 0; i < costs.size(); i++)
		{
			
			if (costs[i]->Get_Day() == day && costs[i]->Get_Mis() == mis && costs[i]->Get_Year() == year)
			{
				costs[i]->PrintInfo();
				txt += costs[i]->Get_Name()+"\n";
				txt += costs[i]->Get_Category()+"\n";
				txt += to_string(costs[i]->Get_Money())+"грн\n";
				txt += to_string(costs[i]->Get_Day()) + ".";
				txt += to_string(costs[i]->Get_Mis()) + ".";
				txt += to_string(costs[i]->Get_Year()) + "\n";
				txt += "---------------------------------------\n";
			}
		}
		txt += "---------------------------------------\n";
		cout << "Зберегти у файл?(1-Так, 0-ні)->";
		cin >> k;
		if (k == 1)
		{
			fstream f("data.txt", ios::app|ios::out);
			f << txt;
			f.close();
		}
	}
	void ShowZvitWeek(int day, int mis, int year)
	{
		string txt;
		txt += "Витрати за тиждень\n";
		txt += "---------------------------------------\n";
		int k;
		for (int i = 0; i < costs.size(); i++)
		{

			if ( costs[i]->Get_Day()>= day && costs[i]->Get_Day()<=day+7 && costs[i]->Get_Mis() == mis && costs[i]->Get_Year() == year)
			{
				costs[i]->PrintInfo();
				txt += costs[i]->Get_Name() + "\n";
				txt += costs[i]->Get_Category() + "\n";
				txt += to_string(costs[i]->Get_Money()) + "грн\n";
				txt += to_string(costs[i]->Get_Day()) + ".";
				txt += to_string(costs[i]->Get_Mis()) + ".";
				txt += to_string(costs[i]->Get_Year()) + "\n";
				txt += "---------------------------------------\n";
			}
		}
		txt += "---------------------------------------\n";
		cout << "Зберегти у файл?(1-Так, 0-ні)->";
		cin >> k;
		if (k == 1)
		{
			fstream f("data.txt", ios::app | ios::out);
			f << txt;
			f.close();
		}
	}
	void ShowZvitMonth(int mis, int year)
	{
		string txt;
		txt += "Витрати за місяць\n";
		txt += "---------------------------------------\n";
		int k;
		for (int i = 0; i < costs.size(); i++)
		{

			if (costs[i]->Get_Mis() == mis && costs[i]->Get_Year() == year)
			{
				costs[i]->PrintInfo();
				txt += costs[i]->Get_Name() + "\n";
				txt += costs[i]->Get_Category() + "\n";
				txt += to_string(costs[i]->Get_Money()) + "грн\n";
				txt += to_string(costs[i]->Get_Day()) + ".";
				txt += to_string(costs[i]->Get_Mis()) + ".";
				txt += to_string(costs[i]->Get_Year()) + "\n";
				txt += "---------------------------------------\n";
			}
		}
		txt += "---------------------------------------\n";
		cout << "Зберегти у файл?(1-Так, 0-ні)->";
		cin >> k;
		if (k == 1)
		{
			fstream f("data.txt", ios::app | ios::out);
			f << txt;
			f.close();
		}
	}
	void ShowTop3Week(int day, int mis, int year)
	{
		sort(this->costs.begin(), this->costs.end(), SortByPrice());
		string txt;
		txt += "Топ-3 витрати за тиждень\n";
		txt += "---------------------------------------\n";
		int k;
		int count = 0;
		for (int i = 0; i < costs.size(); i++)
		{

			if (costs[i]->Get_Day() >= day && costs[i]->Get_Day() <= day + 7 && costs[i]->Get_Mis() == mis && costs[i]->Get_Year() == year)
			{
				
				costs[i]->PrintInfo();
				txt += costs[i]->Get_Name() + "\n";
				txt += costs[i]->Get_Category() + "\n";
				txt += to_string(costs[i]->Get_Money()) + "грн\n";
				txt += to_string(costs[i]->Get_Day()) + ".";
				txt += to_string(costs[i]->Get_Mis()) + ".";
				txt += to_string(costs[i]->Get_Year()) + "\n";
				txt += "---------------------------------------\n";
				count++;
				if (count == 3)
					break;
			}
		}
		txt += "---------------------------------------\n";
		cout << "Зберегти у файл?(1-Так, 0-ні)->";
		cin >> k;
		if (k == 1)
		{
			fstream f("data.txt", ios::app | ios::out);
			f << txt;
			f.close();
		}
	}
	void ShowTop3Month( int mis, int year)
	{
		sort(this->costs.begin(), this->costs.end(), SortByPrice());
		string txt;
		txt += "Топ-3 витрати за місяць\n";
		txt += "---------------------------------------\n";
		int k;
		int count = 0;
		for (int i = 0; i < costs.size(); i++)
		{

			if (costs[i]->Get_Mis() == mis && costs[i]->Get_Year() == year)
			{

				costs[i]->PrintInfo();
				txt += costs[i]->Get_Name() + "\n";
				txt += costs[i]->Get_Category() + "\n";
				txt += to_string(costs[i]->Get_Money()) + "грн\n";
				txt += to_string(costs[i]->Get_Day()) + ".";
				txt += to_string(costs[i]->Get_Mis()) + ".";
				txt += to_string(costs[i]->Get_Year()) + "\n";
				txt += "---------------------------------------\n";
				count++;
				if (count == 3)
					break;
			}
		}
		txt += "---------------------------------------\n";
		cout << "Зберегти у файл?(1-Так, 0-ні)->";
		cin >> k;
		if (k == 1)
		{
			fstream f("data.txt", ios::app | ios::out);
			f << txt;
			f.close();
		}
	}
	int IsCategoryNeIs(vector<Cost*>& tmp,string category_)
	{
		for (int i = 0; i < tmp.size(); i++)
		{
			if (category_ == tmp[i]->Get_Category())
				return i;
		}
		return -1;
	}
	void ShowTop3CategoryWeek(int day, int mis, int year)
	{
		int l;
		vector<Cost*> tmp;
		for (int i = 0; i < costs.size(); i++)
		{
			if (costs[i]->Get_Day() >= day && costs[i]->Get_Day() <= day + 7 && costs[i]->Get_Mis() == mis && costs[i]->Get_Year() == year)
			{
				l = IsCategoryNeIs(tmp, costs[i]->Get_Category());
				if (l == -1)
				{
					tmp.push_back(new Cost(costs[i]->Get_Name(), costs[i]->Get_Category(), costs[i]->Get_Money(), costs[i]->Get_Day(), costs[i]->Get_Mis(), costs[i]->Get_Year()));
				}
				else
					tmp[l]->Get_Money() += costs[i]->Get_Money();
			}

		}
		sort(tmp.begin(), tmp.end(), SortByPrice());
		string txt;
		txt += "Топ-3 категорії за тиждень\n";
		txt += "---------------------------------------\n";
		int k;
		int count = 0;
		for (int i = 0; i < tmp.size(); i++)
		{

			if (tmp[i]->Get_Day() >= day && tmp[i]->Get_Day() <= day + 7 && tmp[i]->Get_Mis() == mis && tmp[i]->Get_Year() == year)
			{
				cout << tmp[i]->Get_Category() << endl;
				txt += tmp[i]->Get_Category() + "\n";
				txt += to_string(tmp[i]->Get_Day()) + ".";
				txt += to_string(tmp[i]->Get_Mis()) + ".";
				txt += to_string(tmp[i]->Get_Year()) + "\n";
				txt += "---------------------------------------\n";
				count++;
				if (count == 3)
					break;
			}
		}
		txt += "---------------------------------------\n";
		cout << "Зберегти у файл?(1-Так, 0-ні)->";
		cin >> k;
		if (k == 1)
		{
			fstream f("data.txt", ios::app | ios::out);
			f << txt;
			f.close();
		}
		for (int i = 0; i < tmp.size(); i++)
		{
			delete tmp[i];
		}
	}
	void ShowTop3CategoryMonth( int mis, int year)
	{
		int l;
		vector<Cost*> tmp;
		for (int i = 0; i < costs.size(); i++)
		{
			if ( costs[i]->Get_Mis() == mis && costs[i]->Get_Year() == year)
			{
				l = IsCategoryNeIs(tmp, costs[i]->Get_Category());
				if (l == -1)
				{
					tmp.push_back(new Cost(costs[i]->Get_Name(), costs[i]->Get_Category(), costs[i]->Get_Money(), costs[i]->Get_Day(), costs[i]->Get_Mis(), costs[i]->Get_Year()));
				}
				else
					tmp[l]->Get_Money() += costs[i]->Get_Money();
			}

		}
		sort(tmp.begin(), tmp.end(), SortByPrice());
		string txt;
		txt += "Топ-3 категорії за місяць\n";
		txt += "---------------------------------------\n";
		int k;
		int count = 0;
		for (int i = 0; i < tmp.size(); i++)
		{

			if (tmp[i]->Get_Mis() == mis && tmp[i]->Get_Year() == year)
			{
				cout << tmp[i]->Get_Category() << endl;
				txt += tmp[i]->Get_Category() + "\n";
				txt += to_string(tmp[i]->Get_Day()) + ".";
				txt += to_string(tmp[i]->Get_Mis()) + ".";
				txt += to_string(tmp[i]->Get_Year()) + "\n";
				txt += "---------------------------------------\n";
				count++;
				if (count == 3)
					break;
			}
		}
		txt += "---------------------------------------\n";
		cout << "Зберегти у файл?(1-Так, 0-ні)->";
		cin >> k;
		if (k == 1)
		{
			fstream f("data.txt", ios::app | ios::out);
			f << txt;
			f.close();
		}
		for (int i = 0; i < tmp.size(); i++)
		{
			delete tmp[i];
		}
	}
};

class Wallet
{
	string name;
	vector<Card*> cards;
	void AddCost(int i)
	{
		string name;
		string category;
		float money;
		int day;
		int mis;
		int year;
		cout << "Введіть суму витрати->";
		cin >> money;
		if (money < cards[i]->Get_Balance())
		{
			cards[i]->Get_Balance() -= money;
			cout << "Введіть назву витрати->";
			cin >> name;
			cout << "Введіть назву категорії витрати->";
			cin >> category;
			cout << "Введіть число(дата) витрати->";
			cin >> day;
			cout << "Введіть місяць(дата) витрати->";
			cin >> mis;
			cout << "Введіть рік(дата) витрати->";
			cin >> year;
			cards[i]->AddCost(new Cost(name, category, money, day, mis, year));
			system("cls");
		}
		else
			cout << "Недостатньо коштів на карті\n";
	}
public:
	int Get_Size()
	{
		return cards.size();
	}
	string Get_Name()
	{
		return name;
	}
	Wallet(string name)
	{
		this->name = name;
	}
	~Wallet()
	{
		for (auto it = this->cards.begin();it!=cards.end(); it++)
		{
			delete *it;
		}
	}
	void AddCard(Card* card)
	{
		this->cards.push_back(card);
	}
	void PerformOperation()
	{
		int day;
		int mis;
		int year;
		int m;
		int increase;
		int k=1;
		while (k)
		{
			int j = 0;
			cout << "Оберіть карту:\n";
			for (int i = 0; i < cards.size(); i++)
			{
				cards[i]->PrintInfo();
				cout << "->" << i + 1 << endl;
			}
			cout << "->";
			cin >> j;
			while (j < 0 || j > cards.size())
			{
				cout << "Не коректний ввід->";
				cin >> j;
				
			}
			int a;
			
			system("cls");
			cards[j - 1]->PrintInfo();
			cout << endl;
			cout << cards[j - 1]->Get_Balance() <<"грн"<< endl;
			cout << "Виберіть операцію:\nПоповнити карту->1\nЗробити витрату->2\nСформувати звіт->3\nСформувати рейтинг->4\nВихід->0\n";
			cout << "->";
			cin >> a;
			system("cls");
			while (a)
			{
				cards[j - 1]->PrintInfo();
				cout << endl;
				cout << cards[j - 1]->Get_Balance() << "грн" << endl;
				switch (a)
				{
				case 1:
					cout << "Поповнити на ->";
					cin >> increase;
					cards[j-1]->Get_Balance() += increase;
					system("cls");
					cards[j - 1]->PrintInfo();
					cout << endl;
					cout << cards[j - 1]->Get_Balance() << "грн" << endl;
					break;
				case 2:
					AddCost(j-1);
					break;
				case 3:
					cout << "За конкретний день->1\nЗа тиждень->2\nЗа місяць->3\n";
					cout << "->";
					cin >> m;
					system("cls");
					switch (m)
					{
					case 1:
						cout << "Введіть число(дата) витрати->";
						cin >> day;
						cout << "Введіть місяць(дата) витрати->";
						cin >> mis;
						cout << "Введіть рік(дата) витрати->";
						cin >> year;
						system("cls");
						cards[j - 1]->ShowZvitDay(day,mis,year);
						break;
					case 2:
						cout << "Введіть число(дата від якої почати тиждень) витрати->";
						cin >> day;
						cout << "Введіть місяць(дата від якої почати тиждень) витрати->";
						cin >> mis;
						cout << "Введіть рік(дата від якої почати тиждень) витрати->";
						cin >> year;
						system("cls");
						cards[j - 1]->ShowZvitWeek(day, mis, year);
						break;
					case 3:
						cout << "Введіть місяць(дата) витрати->";
						cin >> mis;
						cout << "Введіть рік(дата) витрати->";
						cin >> year;
						system("cls");
						cards[j - 1]->ShowZvitMonth(mis, year);
						break;
					}
					break;
				case 4:
					cout << "Топ 3-витрати(за тиждень->1,за місяць->2), Топ 3-категорії(за тиждень->3, за місяць->4)\n";
					cout << "->";
					cin >> m;
					switch (m)
					{
					case 1:
						cout << "Введіть число(дата від якої почати тиждень) витрати->";
						cin >> day;
						cout << "Введіть місяць(дата від якої почати тиждень) витрати->";
						cin >> mis;
						cout << "Введіть рік(дата від якої почати тиждень) витрати->";
						cin >> year;
						cards[j - 1]->ShowTop3Week(day, mis, year);
						break;
					case 2:
						cout << "Введіть місяць(дата) витрати->";
						cin >> mis;
						cout << "Введіть рік(дата) витрати->";
						cin >> year;
						cards[j - 1]->ShowTop3Month(mis, year);
						break;
					case 3:
						cout << "Введіть число(дата від якої почати тиждень) витрати->";
						cin >> day;
						cout << "Введіть місяць(дата від якої почати тиждень) витрати->";
						cin >> mis;
						cout << "Введіть рік(дата від якої почати тиждень) витрати->";
						cin >> year;
						cards[j - 1]->ShowTop3CategoryWeek(day, mis, year);
						break;
					case 4:
						cout << "Введіть місяць(дата) витрати->";
						cin >> mis;
						cout << "Введіть рік(дата) витрати->";
						cin >> year;
						cards[j - 1]->ShowTop3CategoryMonth(mis, year);
						break;
					}
					break;
				}
				
				cout << "Виберіть операцію:\nПоповнити карту->1\nЗробити витрату->2\nСформувати звіт->3\nСформувати рейтинг->4\nВихід->0\n";
				cout << "->";
				cin >> a;
				system("cls");
			}
			system("cls");
			cout << "Обрати іншу карту ->1\nВихід->0\n";
			cin >> k;
			system("cls");
		}

	}
};

class FinanceManager
{
	vector<Wallet*>wallets;
public:
	~FinanceManager()
	{
		for (int i = 0; i < wallets.size(); i++)
		{
			delete wallets[i];
		}
	}
	void StartWork()
	{
		
		string name;
		string account;
		float balance;
		int k,k2,k3;
		cout << "Додати гаманця->1,Вихід->0\n";
		cout << "->";
		cin >> k;
		system("cls");
		while (k)
		{
			switch (k)
			{
			case 1:
				cout << "Введіть назву гаманця->";
				cin >> name;
				system("cls");
				this->wallets.push_back(new Wallet(name));
				break;
			case 2:
				cout << "Оберіть гаманець\n";
				for (int i = 0; i < wallets.size(); i++)
				{
					cout << wallets[i]->Get_Name() << " ->" << i + 1<<endl;
				}
				cout << "->";
				cin >> k2;
				system("cls");
				cout << "Додати карту->1\nЗайти у гаманець->2\nвихід ->0\n";
				cout << "->";
				cin >> k3;
				while (k3)
				{
					switch (k3)
					{
					case 1:
						system("cls");
						cout << "Введіть назву карти->";
						cin >> name;
						cout << "Введіть рахунок карти->";
						cin >> account;
						cout << "Введіть баланс на карті->";
						cin >> balance;
						wallets[k2-1]->AddCard(new Card(name, account, balance));
						system("cls");
						break;
					case 2:
						system("cls");
						if (wallets[k2 - 1]->Get_Size() > 0)
							wallets[k2 - 1]->PerformOperation();
						else
							cout << "Карт не знайдено додайте хоча б одну\n";
						break;
					}
					cout << "Додати карту->1\nЗайти у гаманець->2\nвихід ->0\n";
					cout << "->";
					cin >> k3;
					system("cls");
				}
				
			}
			cout << "Додати гаманця->1,обрати гаманець->2,Вихід->0\n";
			cout << "->";
			cin >> k;
			system("cls");
		}
	}
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FinanceManager financemanager;
	financemanager.StartWork();
	system("pause");
	return 0;
}