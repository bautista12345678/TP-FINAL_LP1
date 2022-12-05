#pragma once
#include<string>
#include "cCodigo.h"
#include"Cazafata.h"
#include "cpersona.h"
#include "Casiento.h"
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
	friend class Casiento;
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
	int cont_bebida;
	int cont_comida;
	int cont_mensaje;
	int cont_ayuda;
	Casiento *Asiento;
public:
	Cpasajero(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c, Casiento* _Asiento);
	~Cpasajero();
	int getcont_bebida();
	int getcont_comida();
	int getcont_mensaje();
	int getcont_ayuda();
	bool getBuenaConducta();
	 void someter();
	void setconduta(bool _conducta);
	cCodigo* getcodigo();
	EnumEstadoDeDescompensacion getEstado();
	bool PedirAyuda(Cazafata* a);
	void terminarAyuda(Cazafata* a);
	void setComida(bool _Comida);
	void setBebida(bool _Bebida);
	bool getComida();
	bool getBebida();
	bool getDormir();
	bool getBaño();
	bool pedirBebida(Cazafata* a);
	void terminarBeber();
	bool pedirComida(Cazafata* a);
	void terminatComer();
	void irAlBaño();
	void volverBaño();
	void dormir();
	void despertarse();
	bool llamarAzafata(Cazafata* a);
	bool recibirMensaje(Cazafata* a);
	Casiento *getAsiento();
	virtual string to_string() = 0;
	virtual void imprimir() = 0;
	ostream& operator<<(ostream& os);
	istream& operator>>(istream& is);
};

