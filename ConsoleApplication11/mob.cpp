#include "pch.h"
#include "mob.h"


mob::mob()
{
}

void mob::curarse(int a)
{
	vida += a;
	if (vida > vidamaxima) {
		vida = vidamaxima;
	}
}


mob::~mob()
{
}
