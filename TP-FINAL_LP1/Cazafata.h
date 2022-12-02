#pragma once
#include"Cpersona.h"
//#include "Cpasajero.h"
#include "Cpiloto.h"
#include "clista.h"
class Cpiloto;
class Cpasajero;
class Cazafata :public  Cpersona
{
private:
	bool Disponibilidad;
	//static int eventos;
public:
	Cazafata(string _nombre, string _dni, bool _Disponibilidad);
	~Cazafata();
	void setDisponibilidad(bool _Disponibilidad);
	bool getDisponibilidad();
	//int getEventos();
	void atenderPaciente();
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


