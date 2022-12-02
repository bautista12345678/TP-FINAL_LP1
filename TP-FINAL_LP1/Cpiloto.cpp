#include "Cpiloto.h"
#include <sstream>
Cpiloto::Cpiloto(string _nombre, string _dni) :Cpersona(_nombre, _dni)
{
	cont_beb = 0;
	cont_com = 0;
	cont_anuncio=0;
	 cont_pasaj=0;
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
	bebida = _b;
}

int Cpiloto::getcont_anuncio()
{
	return cont_anuncio;
}

int Cpiloto::getcont_pasaj()
{
	return cont_pasaj;
}

int Cpiloto::getcont_beb()
{
	return cont_beb;
}

int Cpiloto::getcont_com()
{
	return cont_com;
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

bool Cpiloto::pedirAnuncio(string m, Cazafata* a)
{
	llamarAzafata(a);
	if (a->getDisponibilidad() == true)
	{
		this->llamarAzafata(a);
		a->realizarAnuncio(m);
		cont_anuncio++;

	}
	else
	{
		return false;
	}
	
}

bool Cpiloto::pedirAviso(Cpasajero* p, string msg, Cazafata* a)
{
	llamarAzafata(a);
	if (a->getDisponibilidad() == true)
	{
		this->llamarAzafata(a);
		a->realizarAviso();
		cont_pasaj++;

	}
	else
	{
		return false;
	}
	
}

bool Cpiloto::pedirBebida(Cazafata* a)
{
	llamarAzafata(a);
	if (a->getDisponibilidad() == true)
	{
		a->llevarBebidaPiloto();
		setbebida(true);
		cont_beb++;

	}
	else
	{
		return false;
	}
		
		
	
}

bool Cpiloto::pedirComida(Cazafata* a)
{
	llamarAzafata(a);
	if (a->getDisponibilidad() == true)
	{
		a->llevarComidaPiloto();
		comida = true;
		cont_com++;

	}
	else
	{
		return false;
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


