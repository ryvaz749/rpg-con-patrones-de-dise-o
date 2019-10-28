#include "pch.h"
#include "paladin.h"
#include "curar.h"
#include "freezear.h"
#include "normalpower.h"
paladin::paladin()
{
	poderes = {new freezear()};
}


paladin::~paladin()
{
}
