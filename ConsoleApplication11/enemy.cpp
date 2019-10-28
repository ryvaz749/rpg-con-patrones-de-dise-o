#include "pch.h"
#include "enemy.h"
#include "personaje.h"

enemy::enemy()
{
	vida = 3;
	atake = 3;
}

void enemy::atak(vector<enemy>* , vector<personaje*>* pary)
{
	int cual;
	cual = rand() %pary->size();
	cout << (*pary)[cual]->name << " fue atakado, perdio "<<atake<<" de vida";
	(*pary)[cual]->vida -= atake;
}


enemy::~enemy()
{
}
