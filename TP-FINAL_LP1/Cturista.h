#pragma once
#include"Cpasajero.h"
class Cturista :public Cpasajero
{
private:

public:
	Cturista(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c);
	~Cturista();
	
};

