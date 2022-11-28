#pragma once
#include"Cturista.h"
class Cejecutivo :public Cturista
{
private:
	bool notebook;
public:
	Cejecutivo(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c);
	~Cejecutivo();
	void prenderNotebooks();
	bool getnotebook();
	void apagarNotebook();
	string to_string();
	void imprimir();
};


