#pragma once
#include <vector>
#include <iostream>
#include "personaje.h"
using namespace std;
class party :
	 public vector<personaje*>
{
public:
	int dinero,tdinero, exp;
	void ayardinero();
	party();
	~party();
};

