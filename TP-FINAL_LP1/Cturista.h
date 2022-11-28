#pragma once
#include"Cpasajero.h"
class Cturista :public Cpasajero
{
private:
	bool Bebida;
	bool Comida;
	bool Baño;
	bool Dormir;
public:
	Cturista(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c);
	~Cturista();
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
	string to_string();
	void imprimir();
};

