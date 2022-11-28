#pragma once
#include"Cazafata.h"
class Cpasajero;
class Cazafata;
class Cpiloto :public Cpersona
{
private:
	bool Pilotear;
	//Cazafata *azafata=nullptr;
	bool comida;
	bool bebida;
public:
	Cpiloto(string _nombre, string _dni);
	~Cpiloto();
	void setcomida(bool _c);
	void setbebida(bool _b);
	void pilotear();
	void AnuncioAltaVoz(string msg, Cazafata* a);
	void pedirAnuncio(string m, Cazafata* a);
	void pedirAviso(Cpasajero* c, string msg, Cazafata* a);
	void pedirBebida(Cazafata* a);
	void pedirComida(Cazafata* a);
	void llamarAzafata(Cazafata* a);
	string to_string();
	void imprimir();
};

