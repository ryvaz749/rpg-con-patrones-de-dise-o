#pragma once
#include "personaje.h"
class enemy;
#include <vector>;
class power
{
public:
	power();
	virtual void poder(vector<enemy>*, vector<personaje*>*, personaje*) = 0;
	~power();
};

