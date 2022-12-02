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
	int cont_beb;
	int cont_com;
	int cont_anuncio;
	int cont_pasaj;
public:
	Cpiloto(string _nombre, string _dni);
	~Cpiloto();
	void setcomida(bool _c);
	void setbebida(bool _b);
	int getcont_anuncio();
	int getcont_pasaj();
	int getcont_beb();
	int getcont_com();
	void pilotear();
	void AnuncioAltaVoz(string msg, Cazafata* a);
	bool pedirAnuncio(string m, Cazafata* a);
	bool pedirAviso(Cpasajero* c, string msg, Cazafata* a);
	bool pedirBebida(Cazafata* a);
	bool pedirComida(Cazafata* a);
	void llamarAzafata(Cazafata* a);
	string to_string();
	void imprimir();
};

