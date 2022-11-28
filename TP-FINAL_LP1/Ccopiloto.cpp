#include "Ccopiloto.h"

Ccopiloto::Ccopiloto(string _nombre, string _dni) :Cpiloto(_nombre, _dni)
{
}

Ccopiloto::~Ccopiloto()
{
}

bool Ccopiloto::aterrizar()
{
	MensajeATorre = "aterrizar";
	return false;
}

bool Ccopiloto::despegar()
{
	MensajeATorre = "despegar";
	return true;
}

string Ccopiloto::to_string()
{
	stringstream ss;
	ss << "nombre del copiloto: " << getnombre() << endl;
	ss << "dni: " << getdni() << endl;

	return ss.str();
}

void Ccopiloto::imprimir()
{
	cout << MensajeATorre << endl;;
}
