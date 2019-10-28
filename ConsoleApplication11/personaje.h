#pragma once
#include <stdlib.h>
#include <string>
#include"mob.h"
#include "arma.h"
#include <iostream>
#include <vector>
class enemy;
class power;
using namespace std;
class personaje: public mob
{
public:
	personaje();
	string clase;
	arma weapon;
	vector<power*> poderes;
	int nivel = 0;
	bool ta = false,u,cansado,usararma=false,poderusar = true;
	void atak(vector<enemy>*, vector<personaje*>*);
	pair<int, personaje*> pareja;
	mob* elegir(vector<enemy>*, vector<personaje*>*, int);
	~personaje();

};

