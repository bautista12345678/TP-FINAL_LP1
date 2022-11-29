#include "Cpiloto.h"
#include <sstream>
Cpiloto::Cpiloto(string _nombre, string _dni) :Cpersona(_nombre, _dni)
{

	comida = false;
	bebida = false;
}

Cpiloto::~Cpiloto()
{
}

void Cpiloto::setcomida(bool _c)
{
	comida = _c;
}

void Cpiloto::setbebida(bool _b)
{
	if (_b == false)
	{
		cout << "termino de beber. " << endl;
		bebida = _b;
	}
	else
	{
		cout << "esta bebiendo. " << endl;
		bebida = _b;
	}
}

void Cpiloto::pilotear()
{
	Pilotear = true;
}

void Cpiloto::AnuncioAltaVoz(string msg, Cazafata* a)
{
	this->llamarAzafata(a);
	cout << msg << endl;

}

void Cpiloto::pedirAnuncio(string m, Cazafata* a)
{
	this->llamarAzafata(a);
	a->realizarAnuncio(m);
}

void Cpiloto::pedirAviso(Cpasajero* p, string msg, Cazafata* a)
{
	this->llamarAzafata(a);
	a->realizarAviso(p, msg);
}

void Cpiloto::pedirBebida(Cazafata* a)
{
	if (a->getDisponibilidad() == true)
	{
		this->llamarAzafata(a);
		a->llevarBebidaPiloto();
		setbebida(true);//?????
	}
	else {
		cout << "esta ocupada" << endl;
	}
}

void Cpiloto::pedirComida(Cazafata* a)
{
	if (a->getDisponibilidad() == true)
	{
		this->llamarAzafata(a);
		a->llevarComidaPiloto();
	}
	else {
		cout << "esta ocupada" << endl;
	}

}

void Cpiloto::llamarAzafata(Cazafata* a)
{
	if (a->getDisponibilidad() == true) {
		a->AtenderLlamados();
	}
	else {
		cout << "esta ocupada" << endl;
	}
}

string Cpiloto::to_string()
{
	stringstream ss;
	ss << "nombre del piloto: " << getnombre() << endl;
	ss << "dni: " << getdni() << endl;
	/*ss << "Bebiendo: " << bebida << endl;
	ss << " Comiendo:" << comida << endl;
	ss << " pilotear:" << Pilotear << endl;*/
	//ss << "nombre de la azafata que lo atiende:" << Azafata->getnombre() << endl;
	return ss.str();
}

void Cpiloto::imprimir()
{
	cout << this->to_string() << endl;
}


