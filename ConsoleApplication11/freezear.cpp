#include "pch.h"
#include "freezear.h"
#include "personaje.h"


freezear::freezear()
{
}

void freezear::poder(vector<enemy>* enemys, vector<personaje*>* pary, personaje* es)
{
	int cual;
	cout << "a quein quieres freezear?";
	cin >> cual;
	es->elegir(enemys, pary, cual)->freezed = true;
}



freezear::~freezear()
{
}
