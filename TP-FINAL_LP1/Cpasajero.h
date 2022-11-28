#pragma once
#include<string>
#include "cCodigo.h"
#include"Cazafata.h"
using namespace std;
enum class EnumPrivilegios
{
	turista, ejecutivo, primaveraClase, ninguno
};
enum class EnumEstadoDeDescompensacion
{
	SaludEstable, SaludRegular, SaludCritica
};
class Cpasajero : public Cpersona
{
private:
	EnumEstadoDeDescompensacion Descompensacion;
	EnumPrivilegios TipoDePrivilegio;
	cCodigo* codigo;   //codigo alfanumerico
	Cpasajero* ClaseDeservicio;
	bool BuenaConducta;
	bool sometido;
public:
	Cpasajero(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c);
	~Cpasajero();
	bool getBuenaConducta();
	void someter();
	void setconduta(bool _conducta);
	cCodigo* getcodigo();
	virtual string to_string() = 0;
	virtual void imprimir() = 0;
};

