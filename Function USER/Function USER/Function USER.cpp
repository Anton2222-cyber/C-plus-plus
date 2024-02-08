#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include<list>
#include<vector>
#include<map>
#include"time.h"
#include<algorithm>
using namespace std;
;

class Unit
{
protected:
	int health;
	int armor;
	int power;
public:
	virtual int CauseDamage() = 0;
	virtual void GetDamage(int damage) = 0;
	int Get_Health()
	{
		return health;
	}
};
class Warior :public Unit
{
private:
	string name;
public:
	Warior()
	{
		Set_RandName();
		health = rand() % 501 + 100;
		armor = rand() % 101 + 100;
		power = rand() % 401 + 40;
	}
	void Set_RandName()
	{

		int k = rand() % 10 + 1;
		switch (k)
		{
		case 1:
			name = "Kolia";
			break;
		case 2:
			name = "Anton";
			break;
		case 3:
			name = "Vasia";
			break;
		case 4:
			name = "Fedia";
			break;
		case 5:
			name = "Andriy";
			break;
		case 6:
			name = "Bogdan";
			break;
		case 7:
			name = "Karl";
			break;
		case 8:
			name = "Mcgregor";
			break;
		case 9:
			name = "Ronin";
			break;
		case 10:
			name = "Michael";
			break;
		default:
			name = "Michael";
		}
		name += rand() % 10 + '0';
		name += rand() % 10 + '0';
	}
	int CauseDamage()
	{
		return rand() % power;
	}
	void GetDamage(int damage)
	{
		if (damage > armor)
		{
			int damage_now = (armor - damage) * (-1);
			this->armor = 0;
			this->health = health - damage_now;
		}
		else
			this->armor -= damage;
	}
	void Show_Parameters()
	{
		cout << name << "  " << "здоров'я: " << health << "  " << "броня: " << armor << "  " << "сила: " << power << endl;
	}


};
class Predicat_Health
{
public:
	bool operator()(Warior& w)
	{
		return w.Get_Health() <= 0;
	}
};

class Game
{
private:
	vector<Warior> Counter_Terrorist;
	vector<Warior> Terrorist;
	void Preparation()
	{
		for (int i = 0; i < 5; i++)
		{
			Counter_Terrorist.push_back(Warior());
			Terrorist.push_back(Warior());
		}
	}
	void Show_Statistic()
	{
		if (Counter_Terrorist.size() > 0)

		{
			cout << "Контер-терористи:\n";
			for (int i = 0; i < Counter_Terrorist.size(); i++)
			{
				Counter_Terrorist[i].Show_Parameters();
			}
		}
		if (Terrorist.size() > 0)
		{
			cout << "Терористи:\n";
			for (int i = 0; i < Terrorist.size(); i++)
			{
				Terrorist[i].Show_Parameters();
			}
		}
	}
public:
	void New_Game()
	{
		Preparation();
		cout << "Гра почалась!!\n";
		Sleep(1000);
		system("cls");
		Show_Statistic();
		Sleep(2000);
		system("cls");
		while (Counter_Terrorist.size() > 0 && Terrorist.size() > 0)
		{

			for (int i = 0; i < min(Terrorist.size(), Counter_Terrorist.size()); i++)
			{
				Counter_Terrorist[i].GetDamage(Terrorist[i].CauseDamage());
				Terrorist[i].GetDamage(Counter_Terrorist[i].CauseDamage());
			}

			auto iter_for_delete = remove_if(Counter_Terrorist.begin(), Counter_Terrorist.end(), Predicat_Health());
			Counter_Terrorist.erase(iter_for_delete, Counter_Terrorist.end());
			iter_for_delete = remove_if(Terrorist.begin(), Terrorist.end(), Predicat_Health());
			Terrorist.erase(iter_for_delete, Terrorist.end());
			if (Counter_Terrorist.size() == 0)
			{
				cout << "Терористи виграли!\n";
				Show_Statistic();
				break;
			}
			if (Terrorist.size() == 0)
			{
				cout << "Контр-терористи виграли!\n";
				Show_Statistic();
				break;
			}
			Show_Statistic();
			Sleep(2000);
			system("cls");

		}

	}

};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	Game g;
	g.New_Game();

	system("pause");
	return 0;
}