#pragma once
#include<iostream>
#include<string>
using namespace std;

class Detail
{
protected:
	string name;
public:
	virtual void ShowInfo() = 0;
};

class Body :public Detail //кузов
{
protected:
	int m;//маса кузова
public:
	int GetM()
	{
		return m;
	}
};

class Engine :public Detail
{
protected:
	int P; // потужність у кінських силах
public:
	int GetP()
	{
		return P;
	}
};

class Chassis :public Detail //ходова частина
{
protected:

};

class Transmission :public Detail //трансмісія
{
protected:

};

class ElectricalComponent :public Detail //електрообладнання автомобіля
{
protected:

};
class RodsterSclass :public Body
{
public:
	RodsterSclass()
	{
		name = "кузов родстер S-класу";
		m = 1280;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << m << " кг\n";
	}


};

class Cabriolet :public Body
{
public:
	Cabriolet()
	{
		name = "кузов Cabriolet";
		m = 1500;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << m << " кг\n";
	}

};

class CoupeSclass :public Body
{
public:
	CoupeSclass()
	{
		name = "кузов купе S-класу";
		m = 1200;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << m << " кг\n";
	}

};
class Crossover :public Body
{
public:
	Crossover()
	{
		name = "кузов Crossover";
		m = 2500;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << m << " кг\n";
	}

};

class EngineNissan:public Engine
{
public:
	EngineNissan()
	{
		name = "двигун Nissan";
		P=500;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " к.c.\n";
	}
};

class V8 :public Engine
{
public:
	V8()
	{
		name = "двигун V8";
		P = 806;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " к.c.\n";
	}
};

class V1_8 :public Engine
{
public:
	V1_8()
	{
		name = "двигун V 1.8";
		P = 192;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " к.c.\n";
	}
};

class EnginePorsche :public Engine
{
public:
	EnginePorsche()
	{
		name = "двигун Porsche";
		P = 530;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " к.c.\n";
	}
};

class EngineAstonMartin :public Engine
{
public:
	EngineAstonMartin()
	{
		name = "двигун  Aston Martin";
		P = 517;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " к.c.\n";
	}
};

class BackDrive :public Chassis
{
public:
	BackDrive()
	{
		name = "Задній привод";
	}
	void ShowInfo()
	{
		cout <<"Ходова - "<< name << endl;
	}
};

class FrontDrive :public Chassis
{
public:
	FrontDrive()
	{
		name = "Передній привод";
	}
	void ShowInfo()
	{
		cout << "Ходова - " << name << endl;
	}
};

class FullDrive :public Chassis
{
public:
	FullDrive()
	{
		name = "Повний привод";
	}
	void ShowInfo()
	{
		cout << "Ходова - " << name << endl;
	}
};

class Mechanic6 :public Transmission
{
public:
	Mechanic6()
	{
		name = "6-ступенева механіка";
	}
	void ShowInfo()
	{
		cout << "Трансмісія - " << name << endl;
	}

};

class Avtomat6 :public Transmission
{
public:
	Avtomat6()
	{
		name = "6-ступеневий автомат";
	}
	void ShowInfo()
	{
		cout << "Трансмісія - " << name << endl;
	}

};

class Mechanic6Robot :public Transmission
{
public:
	Mechanic6Robot()
	{
		name = "6-ступенева роботизована механіка";
	}
	void ShowInfo()
	{
		cout << "Трансмісія - " << name << endl;
	}

};

class StandartElectrical:public ElectricalComponent
{
public:
	StandartElectrical()
	{
		name = "Стандартна система електрообладнання";
	}
	void ShowInfo()
	{
		cout << name << endl;
	}
};

class EliteElectrical :public ElectricalComponent
{
public:
	EliteElectrical()
	{
		name = "Елітна система електрообладнання";
	}
	void ShowInfo()
	{
		cout << name << endl;
	}
};