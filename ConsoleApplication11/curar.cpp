#include "pch.h"
#include "curar.h"
#include "personaje.h"
#include"enemy.h"
curar::curar()
{
}

void curar::poder(vector<enemy>* enemys, vector<personaje*>* pary, personaje* es)
{
	int cual;
	cout << "a quien queres curar: " << endl;
	cin >> cual;
	es->elegir(enemys, pary, cual)->curarse((rand() % 3)*es->nivel);
}


curar::~curar()
{
}
