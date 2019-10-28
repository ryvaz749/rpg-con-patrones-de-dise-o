#include "pch.h"
#include "personaje.h"
#include "power.h"
#include "enemy.h"
personaje::personaje() : weapon()
{
	vida = 10;
	atake = 10;
	exp = 0;
}

void personaje::atak(vector<enemy>* enemys, vector<personaje*>* pary)
{
	mob* este;
	bool siono;
	int cual;
	if (poderes.size() > 0) {
		cout << "quieres usar poder? true-false"<<endl;
		cin >> siono;
		if (siono) {
			if (poderes.size() == 2) {
				cout << "cual poder quieres usar?" << endl;
				cin >> cual;
				poderes[cual]->poder(enemys, pary, this);
			}
			else {
				poderes[0]->poder(enemys, pary, this);
			}
		}
	}
	cout << name << " ataka a: ";
	cin >> cual;
	este = elegir(enemys, pary, cual);
	if (ta && nivel < 2) {
		cout << "usar arma?";
		cin >> u;
		if(u){
			este->vida -= weapon.dao;
			weapon.durabilidad -= 1;
			if (weapon.durabilidad == 0) {
				ta = false;
			}
		}
		este->vida -= atake;
	}
}






mob* personaje::elegir(vector<enemy>* enemys, vector<personaje*>* pary, int cual)
{
	if (cual < pary->size()) {
		return (*pary)[cual]; 
	}
	else {
		return &(*enemys)[cual - pary->size()];
	}
	
}

personaje::~personaje()
{
	cout << name << " ha muerto";
}
