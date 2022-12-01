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
    Baño = false;
	Asiento = _Asiento;

}

Cpasajero::~Cpasajero()
{
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
	ss << " en el baño:" << this->getBaño() << endl;
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
bool Cpasajero::getBaño()
{
	return Baño;
}
bool Cpasajero::pedirBebida(Cazafata* a)
{
	
	if (llamarAzafata(a) == true)
	{
		a->llevarBebida();
		Bebida = true;
		a->setDisponibilidad(true);
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
	return true;
	}
	else { return false; }

}

void Cpasajero::terminatComer()
{
	Comida = false;
}

void Cpasajero::irAlBaño()
{
	Baño = true;
}

void Cpasajero::volverBaño()
{
	Baño = false;
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
	return true;
}

Casiento* Cpasajero::getAsiento()
{
	return Asiento;
}

