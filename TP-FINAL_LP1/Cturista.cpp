#include "Cturista.h"#include "Cturista.h"
#include <sstream>
Cturista::Cturista(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c) :Cpasajero(_nombre, _dni, p, _c)
{
	turista = 1;
}

Cturista::~Cturista()
{
}

string Cturista::to_string()
{
	stringstream ss;
	ss << "Bebiendo: " << this->getBebida() << endl;
	ss << " Comiendo:" << this->getComida() << endl;
	ss << " durmiendo:" << this->getDormir() << endl;
	ss << " en el baño:" << this->getBaño() << endl;
	return ss.str();
}

void Cturista::imprimir()
{
	cout << this->to_string() << endl;
}


void Cturista::setComida(bool _Comida)
{
	Comida = _Comida;
}
void Cturista::setBebida(bool _Bebida)
{
	Bebida = _Bebida;
}
bool Cturista::getComida()
{
	return Comida;
}
bool Cturista::getBebida()
{
	return Bebida;
}
bool Cturista::getDormir()
{
	return Dormir;
}
bool Cturista::getBaño()
{
	return Baño;
}
void Cturista::pedirBebida(Cazafata* a)
{
	if (a->getDisponibilidad() == true)
	{
		this->llamarAzafata(a);
		a->llevarBebida();
		Bebida = true;
		a->setDisponibilidad(true);
	}
	else
	{
		cout << "la zafata no esta disponible. " << endl;
	}
}

void Cturista::terminarBeber()
{
	Bebida = false;
}

void Cturista::pedirComida(Cazafata* a)
{
	if (a->getDisponibilidad() == true)
	{
		this->llamarAzafata(a);
		a->llevarComida();
		Comida = true;
		a->setDisponibilidad(true);
	}
	else
	{
		cout << "la azafata no esta disponible" << endl;
	}

}

void Cturista::terminatComer()
{
	Comida = false;
}

void Cturista::irAlBaño()
{
	Baño = true;
}

void Cturista::volverBaño()
{
	Baño = false;
}

void Cturista::dormir()
{
	Dormir = true;
}

void Cturista::despertarse()
{
	Dormir = false;
}

void Cturista::llamarAzafata(Cazafata* a)
{
	if (a->getDisponibilidad() == true) {
		a->AtenderLlamados();
	}
	else
	{
		cout << "esta ocupada" << endl;
	}

}

void Cturista::recibirMensaje(string m)
{
	cout << "mensaje recibido:" << m << endl;
}