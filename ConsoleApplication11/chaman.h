#pragma once
#include "personaje.h"
class curar;
class freezear;
class normalpower;
class chaman :
	public personaje
{
public:
	chaman();
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	~chaman();
};

