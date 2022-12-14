#include "Cejecutivo.h"
#include <sstream>



Cejecutivo::Cejecutivo(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c, Casiento* _Asiento) :Cturista(_nombre, _dni, p, _c, _Asiento)
{
	notebook = false;
}

Cejecutivo::~Cejecutivo()
{
}

void Cejecutivo::prenderNotebooks()
{
	cout << "la notebook esta prendida." << endl;
	this->notebook = true;
}

void Cejecutivo::apagarNotebook()
{
	cout << "la notebook esta apagada." << endl;
	this->notebook = false;
}

string Cejecutivo::to_string()
{
	stringstream ss;
	ss << "Bebiendo: " << this->getBebida() << endl;
	ss << " Comiendo:" << this->getComida() << endl;
	ss << " durmiendo:" << this->getDormir() << endl;
	ss << " en el ba?o:" << this->getBa?o() << endl;
	//ss << "nombre de la azafata que lo atiende:" << Azafata->getnombre() << endl;
	ss << "trabajando:" << this->getnotebook() << endl;
	return ss.str();
}


bool Cejecutivo::getnotebook()
{
	return notebook;
}
void Cejecutivo::imprimir()
{
	cout << to_string() << endl;
}



ostream& Cejecutivo::operator<<(ostream& os)
{
	os << "nombre: " << getnombre() << endl
		<< "dni: " << getdni() << endl << "codigo: " << getcodigo() << endl;
	return os;
}

istream& Cejecutivo::operator>>(istream& is)
{
	string aux;
	is >> aux;
	this->setnombre(aux);
	return is;

}