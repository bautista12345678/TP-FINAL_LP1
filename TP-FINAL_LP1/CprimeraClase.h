#pragma once
#include"Cejecutivo.h"
class CprimeraClase :public Cejecutivo
{
private:
	bool Masaje;
	bool Champagne;
public:
	CprimeraClase(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c, Casiento* _Asiento);
	~CprimeraClase();
	void pedirMasaje();
	void terminarMasaje();
	void pedirChampagne();
	void terminarChampagne();
	string to_string();
	void imprimir();
};

