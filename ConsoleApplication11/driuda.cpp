#include "pch.h"
#include "driuda.h"
#include "curar.h"
#include "freezear.h"
#include "normalpower.h"
driuda::driuda()
{
	poderes = {new curar(),new freezear()};
}


driuda::~driuda()
{
}
