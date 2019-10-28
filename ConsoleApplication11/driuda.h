#pragma once
#include "personaje.h"
class curar;
class freezear;
class normalpower;
class driuda :
	public personaje
{
public:
	driuda();
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	~driuda();
};

