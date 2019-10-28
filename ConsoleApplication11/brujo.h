#pragma once
#include "personaje.h"
class curar;
class freezear;
class normalpower;
class brujo :
	public personaje
{
public:
	brujo();
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	~brujo();
};

