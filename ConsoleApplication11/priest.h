#pragma once
#include "personaje.h"
class curar;
class freezear;
class normalpower;
class priest :
	public personaje
{
public:
	priest();
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	~priest();
};

