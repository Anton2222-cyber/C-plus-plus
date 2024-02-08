#pragma once
#include<iostream>
#include "Deteails.h"
using namespace std;

class CarFactory
{
public:
	virtual Body* CreateBody() = 0;
	virtual Engine* CreateEngine() = 0;
	virtual Chassis* CreateChassis() = 0;
	virtual Transmission* CreateTransmission() = 0;
	virtual ElectricalComponent* CreateElectricalComponent() = 0;
	virtual string SetName() = 0;
	
};

class AstonMartinFactory :public CarFactory
{
public:
	Body* CreateBody()
	{
		return new Cabriolet();
	}
	Engine* CreateEngine()
	{
		return new EngineAstonMartin();
	}
	Chassis* CreateChassis()
	{
		return new BackDrive();
	}
	Transmission* CreateTransmission()
	{
		return new Mechanic6();
	}
	ElectricalComponent* CreateElectricalComponent()
	{
		return new StandartElectrical();
	}
	string SetName()
	{
		return "Aston Martin";
	}
};

class NissanFactory :public CarFactory
{
public:
	Body* CreateBody()
	{
		return new Crossover();
	}
	Engine* CreateEngine()
	{
		return new EngineNissan();
	}
	Chassis* CreateChassis()
	{
		return new FullDrive();
	}
	Transmission* CreateTransmission()
	{
		return new Mechanic6();
	}
	ElectricalComponent* CreateElectricalComponent()
	{
		return new StandartElectrical();
	}
	string SetName()
	{
		return "Nissan";
	}
};

class FerrariFactory :public CarFactory
{
public:
	Body* CreateBody()
	{
		return new CoupeSclass();
	}
	Engine* CreateEngine()
	{
		return new EngineAstonMartin();
	}
	Chassis* CreateChassis()
	{
		return new BackDrive();
	}
	Transmission* CreateTransmission()
	{
		return new Mechanic6Robot();
	}
	ElectricalComponent* CreateElectricalComponent()
	{
		return new StandartElectrical();
	}
	string SetName()
	{
		return "Ferrari";
	}
};

class KoenigseggFactory :public CarFactory
{
public:
	Body* CreateBody()
	{
		return new RodsterSclass();
	}
	Engine* CreateEngine()
	{
		return new V8();
	}
	Chassis* CreateChassis()
	{
		return new BackDrive();
	}
	Transmission* CreateTransmission()
	{
		return new Mechanic6();
	}
	ElectricalComponent* CreateElectricalComponent()
	{
		return new StandartElectrical();
	}
	string SetName()
	{
		return "Koenigsegg";
	}
};

class LotusFactory :public CarFactory
{
public:
	Body* CreateBody()
	{
		return new RodsterSclass();
	}
	Engine* CreateEngine()
	{
		return new V1_8();
	}
	Chassis* CreateChassis()
	{
		return new BackDrive();
	}
	Transmission* CreateTransmission()
	{
		return new Mechanic6();
	}
	ElectricalComponent* CreateElectricalComponent()
	{
		return new StandartElectrical();
	}
	string SetName()
	{
		return "Lotus";
	}
};