#pragma once
#include<iostream>
#include"Deteails.h"
#include"string"
using namespace std;

class Car
{
	string name;
	int distance_done;
	int speed;
	int maxspeed;
	Body* body;
	Engine* engine;
	Chassis* chassis;
	Transmission* transmission;
	ElectricalComponent* electricalComponent;
public:
	
	void SetDistance(float distance)
	{
		this->distance_done = distance;
	}
	int& Get_Distance_Done()
	{
		return distance_done;
	}
	int& Get_Speed()
	{
		return speed;
	}
	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		
		this->name = name;
		this->name += rand() % 10 + '0';
		this->name += rand() % 10 + '0';
	}
	void SetMaxSpeed()
	{
		maxspeed = (engine->GetP() / 2) * ((float)1700 / body->GetM());
	}
	Car()
	{
		
		distance_done = 0;
		speed = 0;
		body=NULL;
		engine = NULL;
		chassis = NULL;
		transmission = NULL;
		electricalComponent = NULL;
	}
	int GetMaxSpeed()
	{
		return maxspeed;
	}
	virtual~Car()
	{
		if (body)
			delete body;
		if (engine)
			delete engine;
		if (chassis)
			delete chassis;
		if (transmission)
			delete transmission;
		if (electricalComponent)
			delete electricalComponent;
	}

	void SetBody(Body* body)
	{
		this->body = body;
	}
	Body* GetBody()
	{
		return body;
	}

	void SetEngine(Engine* engine)
	{
		this->engine = engine;
	}
	Engine* GetEngine()
	{
		return engine;
	}

	void SetChassis(Chassis* chassis)
	{
		this->chassis = chassis;
	}
	Chassis* GetChassis()
	{
		return chassis;
	}

	void SetTransmission(Transmission* transmission)
	{
		this->transmission = transmission;
	}
	Transmission* GetTransmission()
	{
		return transmission;
	}

	void SetElectricalComponent(ElectricalComponent* electricalComponent)
	{
		this->electricalComponent = electricalComponent;
	}
	ElectricalComponent* GetElectricalComponent()
	{
		return electricalComponent;
	}


};