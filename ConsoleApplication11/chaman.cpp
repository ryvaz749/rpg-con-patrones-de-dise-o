#include "pch.h"
#include "chaman.h"
#include "curar.h"
#include "freezear.h"
#include "normalpower.h"
chaman::chaman()
{
	poderes = {new normalpower(),new curar()};
}


chaman::~chaman()
{
}
