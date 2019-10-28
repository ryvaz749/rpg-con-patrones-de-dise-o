#pragma once
#include "personaje.h"
class curar;
class freezear;
class normalpower;
class paladin :
	public personaje
{
public:
	paladin();
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	~paladin();
};

