#include "Cpersona.h"
#include <sstream>
Cpersona::Cpersona(string _nombre, string _dni)
{
	nombre = _nombre;
	dni = _dni;
}
Cpersona::Cpersona(const Cpersona& _copia)
{
	nombre = _copia.nombre;
	dni = _copia.dni;
}

Cpersona::~Cpersona()
{
}

string Cpersona::getnombre()
{
	return nombre;
}

string Cpersona::getdni()
{
	return dni;
}

/*void Cpersona::imprimir()
{
	cout << to_string() << endl;
}

string Cpersona::to_string()
{
	stringstream ss;
	ss << "nombre: " << nombre<< endl;
	ss << " dni:" << dni << endl;
	return ss.str();
}*/

