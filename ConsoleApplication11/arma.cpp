#include "pch.h"
#include "arma.h"


arma::arma(string _nombre, string _clase, int _dao, int _durabilidad, int _precio)
{
	nombre = _nombre;
	clase = _clase;
	dao = _dao;
	durabilidad = _durabilidad;
	precio = _precio;
}

arma::arma()
{
}


arma::~arma()
{
}
