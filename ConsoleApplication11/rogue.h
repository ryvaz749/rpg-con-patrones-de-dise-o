#pragma once
#include "personaje.h"
class curar;
class freezear;
class normalpower;
class rogue :
	public personaje
{
public:
	rogue();
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	~rogue();
};

