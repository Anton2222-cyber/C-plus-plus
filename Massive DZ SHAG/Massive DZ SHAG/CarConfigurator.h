#pragma once
#include<iostream>
#include "Deteails.h"
#include"Car.h"
#include"Factories.h"
using namespace std;

class CarConfigurator
{
	CarFactory* carfactory;
public:
	CarConfigurator()
	{
		carfactory = NULL;
	}
	virtual~CarConfigurator()
	{
		if (carfactory)
			delete carfactory;
	}
	void SetCarfactory(CarFactory* carfactory)
	{
		this->carfactory = carfactory;
	}
	CarFactory* GetCarfactory()
	{
		return carfactory;
	}
	void Configure(Car* car)
	{
		car->SetBody(carfactory->CreateBody());
		car->SetChassis(carfactory->CreateChassis());
		car->SetEngine(carfactory->CreateEngine());
		car->SetTransmission(carfactory->CreateTransmission());
		car->SetElectricalComponent(carfactory->CreateElectricalComponent());
		car->SetName(carfactory->SetName());
		car->SetMaxSpeed();
	}

};