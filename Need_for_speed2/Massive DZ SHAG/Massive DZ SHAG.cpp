
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include<list>
#include<map>
#include "Deteails.h"
#include"Car.h"
#include"CarConfigurator.h"
#include"time.h"
using namespace std;

void PrintCar(Car* car)
{
	cout << "--------------------------------------\n";
	cout << car->GetName() << endl;
	car->GetBody()->ShowInfo();
	car->GetChassis()->ShowInfo();
	car->GetEngine()->ShowInfo();
	car->GetTransmission()->ShowInfo();
	car->GetElectricalComponent()->ShowInfo();
	cout << "--------------------------------------\n";
}
class Game
{
	int size = 0;
	list<Car*> race;
	map<int,string>statistic;
	CarFactory* GetRandFactory()
	{
		CarFactory* carfactory;
		int k = rand() % 5 + 1;
		switch (k)
		{
		case 1:
			carfactory = new AstonMartinFactory();
			break;
		case 2:
			carfactory = new NissanFactory();
			break;
		case 3:
			carfactory = new FerrariFactory();
			break;
		case 4:
			carfactory = new KoenigseggFactory();
			break;
		case 5:
			carfactory = new LotusFactory();
			break;
		default:
			carfactory = new FerrariFactory();
		}
		return carfactory;

	}
	void ChangeCar(Car* car)
	{
		
			int plus = car->GetEngine()->GetP()/40;
			if (car->Get_Speed()*3.6 >= car->GetMaxSpeed())
			{
				plus = 0;
			}
			car->Get_Speed() += plus;
		int randminus = rand() % car->GetEngine()->GetP() / 40;
		while (car->Get_Speed() < randminus)
		{
			randminus = rand() % car->GetEngine()->GetP() / 40;
		}
		car->Get_Speed() -= randminus;
		car->Get_Distance_Done() += car->Get_Speed();
	}
public:
	~Game()
	{
		for (auto it = race.begin(); it != race.end(); it++)
		{
			delete* it;
		}
	}
	bool Winners_Is_Here(float distance)
	{
		for (auto it = race.begin(); it != race.end(); it++)
		{
			if ((*it)->Get_Distance_Done() >= distance)
				return true;
		}
		return false;
	}
	list<Car*>::iterator GetIteratorWinneer()
	{
		auto max = race.begin();
		for (auto it = race.begin(); it != race.end(); it++)
		{
			if ((*max)->Get_Distance_Done()<(*it)->Get_Distance_Done())
			{
				max = it;
			}
		}
		statistic[size++] = (*max)->GetName();
		return max;
	}
	

	void StartGame()
	{
		float distance = 3;
		cout << "Ціль: " << distance << " км\n";
		Sleep(2000);
		system("cls");
		distance *= 1000;
		int k = 3;
			for (int i = 0; i < k; i++)
			{
				CarConfigurator* carconf = new CarConfigurator();
				Car* car = new Car();
				carconf->SetCarfactory(GetRandFactory());
				carconf->Configure(car);
				delete carconf;
				race.push_back(car);
			}
			int time=0;
			cout << "На старт!\n";
			Sleep(1000);
			system("cls");
			cout << "Увага!\n";
			Sleep(1000);
			system("cls");
			cout << "Руш!\n";
			Sleep(1000);
			system("cls");

			while (race.size() > 0)
			{
				cout << "Час: " << time << endl;
				for (auto it = race.begin(); it != race.end(); it++)
				{
					ChangeCar(*it);
					cout<<(*it)->GetName()<<endl;
					cout << (*it)->Get_Speed()*3.6 <<" км/год"<< endl;
					cout << float((*it)->Get_Distance_Done())/1000<<" км" << endl;
					
					cout << endl;
					
				}
				while (Winners_Is_Here(distance))
				{
					race.erase(GetIteratorWinneer());
				}
				
				time++;
				Sleep(1000);
				system("cls");
			}
			cout << "Список переможців:\n";
			for (int i = 1; i <= size; i++)
			{
				cout << i << ". " << statistic[i - 1] << endl;
			}

	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	Game g;
	g.StartGame();
	system("pause");
	return 0;
}

