#pragma once
#include "personaje.h"
#include <vector>
class curador :
	public personaje
{
public:
	curador();
	void curar(vector<personaje*>* personaje);
	~curador();
};

