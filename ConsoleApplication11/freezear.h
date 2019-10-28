#pragma once
#include "power.h"
class personaje;
class freezear :
	public power
{
public:
	freezear();
	void poder(vector<enemy>*, vector<personaje*>*, personaje*);
	~freezear();
};

