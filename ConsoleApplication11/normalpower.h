#pragma once
class personaje;
#include "power.h"
class normalpower :
	public power
{
private:
	bool estalisto = false,esta;
public:
	normalpower();
	void poder(vector<enemy>*, vector<personaje*>*, personaje*);
	~normalpower();
};

