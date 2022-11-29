#include "Cazafata.h"
#include <sstream>
Cazafata::Cazafata(string _nombre, string _dni, bool _Disponibilidad) :Cpersona(_nombre, _dni)
{
	Disponibilidad = _Disponibilidad;
}
Cazafata::~Cazafata()
{
}

void Cazafata::setDisponibilidad(bool _Disponibilidad)
{
	Disponibilidad = _Disponibilidad;
}

bool Cazafata::getDisponibilidad()
{
	return Disponibilidad;
}

void Cazafata::llevarComida()
{
	cout << "llevando comida" << endl;
}

void Cazafata::llevarBebida()
{
	cout << "llevando bebida" << endl;

}

void Cazafata::llevarComidaPiloto()
{
	//p->setcomida(true);
	cout << "llevando comida al piloto" << endl;
}

void Cazafata::llevarBebidaPiloto()
{
	//p->setbebida(true);
	cout << "llevando bebida al piloto" << endl;

}

void Cazafata::realizarAnuncio(string _m)
{
	cout << _m << endl;
}


string Cazafata::realizarAviso()
{
	string msj = "mensaje";
	return msj;
}

void Cazafata::AtenderLlamados()
{
	Disponibilidad = false;
}

bool Cazafata::azafataOcupada()
{
	if (Disponibilidad == true)
	{
		cout << "asafata disponible" << endl;
		return true;
	}
	else
	{
		cout << "asafasta no disponible" << endl;
		return false;
	}
}

string Cazafata::to_string()
{
	stringstream ss;
	ss << "nombre" << this->getnombre() << endl;
	ss << "dni" << this->getdni() << endl;
	if (Disponibilidad == true)
	{
		ss << "disponibilidad" << endl;
	}
	else {
		ss << "no disponible" << endl;
	}

	return ss.str();
}
void Cazafata::imprimir()
{
	cout << to_string() << endl;
}
