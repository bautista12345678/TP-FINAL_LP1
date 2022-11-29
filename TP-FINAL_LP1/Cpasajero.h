#pragma once
#include<string>
#include "cCodigo.h"
#include"Cazafata.h"
#include "cpersona.h"
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
	bool BuenaConducta;
	bool sometido;
	bool Bebida;
	bool Comida;
	bool Baño;
	bool Dormir;
public:
	Cpasajero(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c);
	~Cpasajero();
	bool getBuenaConducta();
	void someter();
	void setconduta(bool _conducta);
	cCodigo* getcodigo();
	void setComida(bool _Comida);
	void setBebida(bool _Bebida);
	bool getComida();
	bool getBebida();
	bool getDormir();
	bool getBaño();
	void pedirBebida(Cazafata* a);
	void terminarBeber();
	void pedirComida(Cazafata* a);
	void terminatComer();
	void irAlBaño();
	void volverBaño();
	void dormir();
	void despertarse();
	void llamarAzafata(Cazafata* a);
	void recibirMensaje(string m);
	virtual string to_string() = 0;
	virtual void imprimir() = 0;
};

