#pragma once
#include "personaje.h"
class curar;
class freezear;
class normalpower;
class hechisero :
	public personaje
{
public:
	hechisero();
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	~hechisero();
};

