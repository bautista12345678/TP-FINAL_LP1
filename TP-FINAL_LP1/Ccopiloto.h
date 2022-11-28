#pragma once
#include"Cpiloto.h"
#include"Cazafata.h"
#include<sstream>
class Ccopiloto :public Cpiloto
{
private:
	string MensajeATorre;
public:
	Ccopiloto(string _nombre, string _dni);
	~Ccopiloto();
	bool aterrizar();
	bool despegar();
	string to_string();
	void imprimir();
};

