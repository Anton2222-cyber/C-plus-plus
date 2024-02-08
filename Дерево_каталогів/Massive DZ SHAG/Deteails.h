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

class Body :public Detail //�����
{
protected:
	int m;//���� ������
public:
	int GetM()
	{
		return m;
	}
};

class Engine :public Detail
{
protected:
	int P; // ��������� � ������� �����
public:
	int GetP()
	{
		return P;
	}
};

class Chassis :public Detail //������ �������
{
protected:

};

class Transmission :public Detail //��������
{
protected:

};

class ElectricalComponent :public Detail //����������������� ���������
{
protected:

};
class RodsterSclass :public Body
{
public:
	RodsterSclass()
	{
		name = "����� ������� S-�����";
		m = 1280;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << m << " ��\n";
	}


};

class Cabriolet :public Body
{
public:
	Cabriolet()
	{
		name = "����� Cabriolet";
		m = 1500;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << m << " ��\n";
	}

};

class CoupeSclass :public Body
{
public:
	CoupeSclass()
	{
		name = "����� ���� S-�����";
		m = 1200;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << m << " ��\n";
	}

};
class Crossover :public Body
{
public:
	Crossover()
	{
		name = "����� Crossover";
		m = 2500;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << m << " ��\n";
	}

};

class EngineNissan:public Engine
{
public:
	EngineNissan()
	{
		name = "������ Nissan";
		P=500;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " �.c.\n";
	}
};

class V8 :public Engine
{
public:
	V8()
	{
		name = "������ V8";
		P = 806;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " �.c.\n";
	}
};

class V1_8 :public Engine
{
public:
	V1_8()
	{
		name = "������ V 1.8";
		P = 192;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " �.c.\n";
	}
};

class EnginePorsche :public Engine
{
public:
	EnginePorsche()
	{
		name = "������ Porsche";
		P = 530;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " �.c.\n";
	}
};

class EngineAstonMartin :public Engine
{
public:
	EngineAstonMartin()
	{
		name = "������  Aston Martin";
		P = 517;
	}
	void ShowInfo()
	{
		cout << name << endl;
		cout << P << " �.c.\n";
	}
};

class BackDrive :public Chassis
{
public:
	BackDrive()
	{
		name = "����� ������";
	}
	void ShowInfo()
	{
		cout <<"������ - "<< name << endl;
	}
};

class FrontDrive :public Chassis
{
public:
	FrontDrive()
	{
		name = "������� ������";
	}
	void ShowInfo()
	{
		cout << "������ - " << name << endl;
	}
};

class FullDrive :public Chassis
{
public:
	FullDrive()
	{
		name = "������ ������";
	}
	void ShowInfo()
	{
		cout << "������ - " << name << endl;
	}
};

class Mechanic6 :public Transmission
{
public:
	Mechanic6()
	{
		name = "6-��������� �������";
	}
	void ShowInfo()
	{
		cout << "�������� - " << name << endl;
	}

};

class Avtomat6 :public Transmission
{
public:
	Avtomat6()
	{
		name = "6-���������� �������";
	}
	void ShowInfo()
	{
		cout << "�������� - " << name << endl;
	}

};

class Mechanic6Robot :public Transmission
{
public:
	Mechanic6Robot()
	{
		name = "6-��������� ������������ �������";
	}
	void ShowInfo()
	{
		cout << "�������� - " << name << endl;
	}

};

class StandartElectrical:public ElectricalComponent
{
public:
	StandartElectrical()
	{
		name = "���������� ������� �����������������";
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
		name = "����� ������� �����������������";
	}
	void ShowInfo()
	{
		cout << name << endl;
	}
};