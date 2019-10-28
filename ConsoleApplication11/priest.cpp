#include "pch.h"
#include "priest.h"
#include "curar.h"
#include "freezear.h"
#include "normalpower.h"
priest::priest()
{
	poderes = {new curar()};
}


priest::~priest()
{
}
