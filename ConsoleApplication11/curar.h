#pragma once
#include "power.h"
class personaje;
class enemy;
class curar :
	public power
{
public:
	curar();
	void poder(vector<enemy>*, vector<personaje*>*, personaje*);
	~curar();
};

