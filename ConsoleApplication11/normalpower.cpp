#include "pch.h"
#include "normalpower.h"
#include "personaje.h"

normalpower::normalpower()
{
}

void normalpower::poder(vector<enemy>* enemys, vector<personaje*>* pary, personaje* es)
{
	int cual;
	if (!(estalisto)) {
		cout << "tu poder se esta preparando" << endl;
		cin >> estalisto;
	}
	else {
		cout << "1-quieres usar tu poder? true-false" << endl;
		cin >> esta;
		if (esta) {
			cout << "contra quien?";
			cin >> cual;
			es->elegir(enemys, pary, cual)->vida -= es->atake * 2.7f;
		}
	};
}


normalpower::~normalpower()
{
}
