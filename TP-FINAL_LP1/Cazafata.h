#pragma once
#include"Cpersona.h"
//#include "Cpasajero.h"
#include "Cpiloto.h"
class Cpiloto;
class Cpasajero;
class Cazafata :public  Cpersona
{
private:
	bool Disponibilidad;
public:
	Cazafata(string _nombre, string _dni, bool _Disponibilidad);
	~Cazafata();
	void setDisponibilidad(bool _Disponibilidad);
	bool getDisponibilidad();
	void llevarComida();
	void llevarBebida();
	void llevarComidaPiloto();
	void llevarBebidaPiloto();
	void realizarAnuncio(string _m);
	string realizarAviso();
	void AtenderLlamados();
	bool azafataOcupada();
	string to_string();
	void imprimir();

};


