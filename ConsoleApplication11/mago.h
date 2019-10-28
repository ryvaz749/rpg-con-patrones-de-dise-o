#pragma once
#include "personaje.h"
class curar;
class freezear;
class normalpower;
class mago :
	public personaje
{
public:
	mago();
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	~mago();
};

