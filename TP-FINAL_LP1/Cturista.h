#pragma once
#include"Cpasajero.h"
class Cturista :public Cpasajero
{
private:
	int a;
public:
	Cturista(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c);
	~Cturista();
	string to_string();
	void imprimir();
};

