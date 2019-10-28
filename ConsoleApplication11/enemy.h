#pragma once
#include "mob.h"
class personaje;
class enemy: public mob
{
public:
	enemy();
	void atak(vector<enemy>*, vector<personaje*>*);
	~enemy();
};

