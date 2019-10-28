#pragma once
#include<string>
#include<iostream>
#include <tuple>
#include <vector>
using namespace std;
class mob
{
public:
	mob();
	int atake, vida, exp, vidamaxima;
	bool charlar=false,  freezed = false;;
	void curarse(int);
	string name;
	~mob();
};

