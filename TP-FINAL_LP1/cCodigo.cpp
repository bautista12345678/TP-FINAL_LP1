#include "cCodigo.h"
#include <sstream>
cCodigo::cCodigo(string _sector, string _DNI, int _fila, string _letra)
{
	sector = _sector;
	DNI = _DNI;
	fila = _fila;
	letra = _letra;
}

cCodigo::~cCodigo()
{
}

string cCodigo::getsector()
{
	return sector;
}

string cCodigo::getDNI()
{
	return DNI;
}

int cCodigo::getfila()
{
	return fila;
}

string cCodigo::getletra()
{
	return letra;
}

string cCodigo::to_string()
{
	stringstream ss;
	ss << sector;
	ss << DNI;
	ss << fila;
	ss << letra;

	return ss.str();
}

void cCodigo::imprimir()
{
	to_string();
}
