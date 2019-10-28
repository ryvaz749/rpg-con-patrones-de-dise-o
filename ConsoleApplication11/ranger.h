#pragma once
#include "personaje.h"
class ranger :
	public personaje
{
public:
	void poder(vector<personaje*>*, vector<enemy*>*, personaje*);
	ranger();
	~ranger();
};

