#include "pch.h"
#include "brujo.h"
#include "curar.h"
#include "freezear.h"
#include "normalpower.h"
brujo::brujo()
{
	poderes = {new freezear(),new normalpower()};
}


brujo::~brujo()
{
}
