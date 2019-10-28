#include "pch.h"
#include "curador.h"


curador::curador()
{
}

void curador::curar(vector<personaje*>* otro)
{
	int cual;
	cout << "a quien quieres curar" << endl;
	cin >> cual;
	(*otro)[cual]->vida += 5;

}



curador::~curador()
{
}
