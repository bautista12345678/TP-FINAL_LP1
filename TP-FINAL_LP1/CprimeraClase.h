#pragma once
#include"Cejecutivo.h"
class CprimeraClase :public Cejecutivo
{
private:
	bool Masaje;
	bool Champagne;
	int cont_masaje;
	int cont_cham;
public:
	CprimeraClase(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c, Casiento* _Asiento);
	~CprimeraClase();
	bool pedirMasaje(Cazafata* a);
	void terminarMasaje();
	int getcont_masaje();
	int getcont_cham();
	bool pedirChampagne(Cazafata* a);
	void terminarChampagne();
	string to_string();
	void imprimir();
};

