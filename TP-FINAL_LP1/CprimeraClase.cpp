#include "CprimeraClase.h"
#include <sstream>

CprimeraClase::CprimeraClase(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c, Casiento* _Asiento) :Cejecutivo(_nombre, _dni, p, _c, _Asiento)
{

	Masaje = false;
	Champagne = false;
	cont_masaje = 0;
	cont_cham = 0;
}

CprimeraClase::~CprimeraClase()
{
}





bool CprimeraClase::pedirMasaje(Cazafata *a)
{

	llamarAzafata(a);
	if (a->getDisponibilidad() == true)
	{
		cout << " el pasajero recibe un masaje. " << endl;
		this->Masaje = true;
		cont_masaje++;
	}
	else
	{
		return false;
	}
	
}

void CprimeraClase::terminarMasaje()
{
	cout << "el pasajero termino de darse un masaje. " << endl;
	this->Masaje = false;
}

int CprimeraClase::getcont_masaje()
{
	return cont_masaje;
}

int CprimeraClase::getcont_cham()
{
	return cont_cham;
}

bool CprimeraClase::pedirChampagne(Cazafata *a)
{
	llamarAzafata(a);
	if (a->getDisponibilidad() == true)
	{
		cout << "el pasajero pide un champagne. " << endl;
		this->Champagne = true;
		cont_cham++;
	}
	else
	{
		return false;
	}
	
}

void CprimeraClase::terminarChampagne()
{
	cout << "termino su champagne el pasajero. " << endl;
	this->Champagne = false;
}

string CprimeraClase::to_string()
{
	stringstream ss;
	ss << "Bebiendo: " << this->getBebida() << endl;
	ss << " Comiendo:" << this->getComida() << endl;
	ss << " durmiendo:" << this->getDormir() << endl;
	ss << " en el baño:" << this->getBaño() << endl;
	//	ss << "nombre de la azafata que lo atiende:" << Azafata->getnombre() << endl;
	return ss.str();
}

void CprimeraClase::imprimir()
{
	cout << to_string() << endl;
}


ostream& CprimeraClase::operator<<(ostream& os)
{
	os << "nombre: " << getnombre() << endl
		<< "dni: " << getdni() << endl << "codigo: " << getcodigo() << endl;
	return os;
}

istream& CprimeraClase::operator>>(istream& is)
{
	string aux;
	is >> aux;
	this->setnombre(aux);
	return is;

}