#pragma once
#include <iostream>
#include "StrategyTime.h"

class Memento
{
	int point;
	int i;
	int j;
	StrategyTime* strategy;
public:
	Memento(int point, int i, int j, StrategyTime* strategy)
	{
		this->point = point;
		this->i = i;
		this->j = j;
		this->strategy = strategy;
	}
	int Get_Point()
	{
		return point;
	}
	int Get_I()
	{
		return i;
	}
	int Get_J()
	{
		return j;
	}
	StrategyTime* Get_Strategy()
	{
		return strategy;
	}

};