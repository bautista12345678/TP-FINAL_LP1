#pragma once
#include"Cturista.h"
class Cejecutivo :public Cturista
{
private:
	bool notebook;
   
public:
	Cejecutivo(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c, Casiento* _Asiento);
	~Cejecutivo();
	void prenderNotebooks();
	bool getnotebook();
	void apagarNotebook();
	string to_string();
	void imprimir();
	ostream& operator<<(ostream& os);
	istream& operator>>(istream& is);
};


