#include "Cazafata.h"
#include <sstream>
int Cazafata::eventos = 0;
Cazafata::Cazafata(string _nombre, string _dni, bool _Disponibilidad):Cpersona(_nombre, _dni)
{
	Disponibilidad = _Disponibilidad;
	for (int i = 0; i < 1000; i++)
	{
	   ListaEventos[i] = "NULL";
	}
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

void Cazafata::atenderPaciente()
{
	cout << "ayudando pasajero" << endl;
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
	if (azafataOcupada() == true)
	{
	Disponibilidad = false;
	eventos = eventos + 1;
    }
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
string Cazafata::getListaEventos()
{
	return ListaEventos[1000];
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
