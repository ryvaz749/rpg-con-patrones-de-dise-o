#include "pch.h"
#include "party.h"


void party::ayardinero()
{
	tdinero = 0;
	while (rand() % 13 != 0) {
		tdinero += 1;
	}
	dinero += tdinero;
	cout << "has encontrado " << tdinero << "$" << endl;
	system("pause");
}
party::party()
{
}

party::~party()
{
}
