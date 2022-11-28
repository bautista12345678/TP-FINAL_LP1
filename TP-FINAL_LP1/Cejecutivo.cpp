#include "Cejecutivo.h"
#include <sstream>



Cejecutivo::Cejecutivo(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c) :Cturista(_nombre, _dni, p, _c)
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
	ss << " en el baño:" << this->getBaño() << endl;
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

