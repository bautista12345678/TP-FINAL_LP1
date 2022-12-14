#include "Cturista.h"
#include <sstream>

Cturista::Cturista(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c, Casiento* _Asiento):Cpasajero(_nombre, _dni, p, _c, _Asiento)
{
	a = 1;
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
	ss << " en el ba?o:" << this->getBa?o() << endl;
	//	ss << "nombre de la azafata que lo atiende:" << Azafata->getnombre() << endl;
	return ss.str();
}


void Cturista::imprimir()
{
	cout << to_string() << endl;
}



ostream& Cturista::operator<<(ostream& os)
{
	os << "nombre: " << getnombre() << endl
		<< "dni: " << getdni() << endl << "codigo: " << getcodigo() << endl;
	return os;
}

istream& Cturista::operator>>(istream& is)
{
	string aux;
	is >> aux;
	this->setnombre(aux);
	return is;

}