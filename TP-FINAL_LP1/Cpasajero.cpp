#include "Cpasajero.h"
#include <sstream>
Cpasajero::Cpasajero(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c, Casiento* _Asiento) :Cpersona(_nombre, _dni)
{
    TipoDePrivilegio = p;
    codigo = _c;
    BuenaConducta = true;;
    sometido = false;
    Dormir = false;
    Bebida = false;
    Comida = false;
    Ba?o = false;
	Asiento = _Asiento;
	cont_ayuda = 0;
	cont_bebida = 0;
	cont_comida = 0;
	cont_mensaje = 0;

}

Cpasajero::~Cpasajero()
{
}

int Cpasajero::getcont_bebida()
{
	return cont_bebida;
}

int Cpasajero::getcont_comida()
{
	return cont_comida;
}

int Cpasajero::getcont_mensaje()
{
	return cont_mensaje;
}

int Cpasajero::getcont_ayuda()
{
	return cont_ayuda;
}


bool Cpasajero::getBuenaConducta()
{
    return BuenaConducta;
}

 void Cpasajero::someter()
{
    sometido = true;
}

void Cpasajero::setconduta(bool _conducta)
{
    this->BuenaConducta = _conducta;
}

cCodigo* Cpasajero::getcodigo()
{
    return codigo;
}

EnumEstadoDeDescompensacion Cpasajero::getEstado()
{
	return 	Descompensacion;
}

bool Cpasajero::PedirAyuda(Cazafata *a)
{
	llamarAzafata(a);
	if (a->getDisponibilidad() == true)
	{
		Descompensacion = EnumEstadoDeDescompensacion::SaludRegular;
		return true;
		cont_ayuda++;
	}
	else
	{
		return false;
	}
}

void Cpasajero::terminarAyuda(Cazafata* a)
{
	if (Descompensacion == EnumEstadoDeDescompensacion::SaludRegular)
	{
		a->setDisponibilidad(true);
	}
}

/*string Cpasajero::to_string()
{
    stringstream ss;
    ss << "nombre: " << this->getnombre() << endl;
    ss << "dni: " << this->getdni() << endl;
    ss << "codigo: " << this->getcodigo() << endl;
    return ss.str();
}

void Cpasajero::imprimir()
{
    cout << to_string();
}*/



/*
string Cpasajero::to_string()
{
	stringstream ss;
	ss << "Bebiendo: " << this->getBebida() << endl;
	ss << " Comiendo:" << this->getComida() << endl;
	ss << " durmiendo:" << this->getDormir() << endl;
	ss << " en el ba?o:" << this->getBa?o() << endl;
	return ss.str();
}

void Cpasajero::imprimir()
{
	cout << this->to_string() << endl;
}
*/

void Cpasajero::setComida(bool _Comida)
{
	Comida = _Comida;
}
void Cpasajero::setBebida(bool _Bebida)
{
	Bebida = _Bebida;
}
bool Cpasajero::getComida()
{
	return Comida;
}
bool Cpasajero::getBebida()
{
	return Bebida;
}
bool Cpasajero::getDormir()
{
	return Dormir;
}
bool Cpasajero::getBa?o()
{
	return Ba?o;
}
bool Cpasajero::pedirBebida(Cazafata* a)
{
	
	if (llamarAzafata(a) == true)
	{
		a->llevarBebida();
		Bebida = true;
		a->setDisponibilidad(true);
		cont_bebida++;
		return true;
		
	}
	else { return false; }
}

void Cpasajero::terminarBeber()
{
	Bebida = false;
}

bool Cpasajero::pedirComida(Cazafata* a)
{

	if (llamarAzafata(a) == true)
	{
	
	a->llevarComida();
	Comida = true;
	a->setDisponibilidad(true);
	cont_comida++;
	return true;
	}
	else { return false; }

}

void Cpasajero::terminatComer()
{
	Comida = false;
}

void Cpasajero::irAlBa?o()
{
	Ba?o = true;
}

void Cpasajero::volverBa?o()
{
	Ba?o = false;
}

void Cpasajero::dormir()
{
	Dormir = true;
}

void Cpasajero::despertarse()
{
	Dormir = false;
}

bool Cpasajero::llamarAzafata(Cazafata* a)
{
	if (a->getDisponibilidad() == true) {
		a->AtenderLlamados();
		return true;
	}
	else
	{
	
		cout << "esta ocupada" << endl;
		return false;
	}

}

bool Cpasajero::recibirMensaje(Cazafata* a)
{
	
	cout << "mensaje recibido:" << a->realizarAviso()<< endl;
	cont_mensaje++;
	return true;
}

Casiento* Cpasajero::getAsiento()
{
	return Asiento;
}

ostream& Cpasajero::operator<<(ostream& os)
{
	os<< "nombre: " << getnombre() << endl
	 << "dni: " << getdni() << endl << "codigo: " <<getcodigo() << endl;
	return os;
}

istream& Cpasajero::operator>>(istream& is)
{
	string aux;
	is >> aux;
	this->setnombre(aux);
	return is;

}

