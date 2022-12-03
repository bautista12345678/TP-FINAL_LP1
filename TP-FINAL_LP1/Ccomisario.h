#pragma once
#include"Cpasajero.h"
#include "Cavion.h"
class Ccomisario : public Cpersona
{
private:
	bool TodoEnOrden;
	int cont_encarcelados;
public:
	Ccomisario(string _nombre, string _dni);
	~Ccomisario();
	int getcont_encarcelados();
	bool preguntarSiTodoEstaEnOrden(Cavion* a);
	bool someterPasajero(Cpasajero* p);
	void encerrapasajero(Cavion* a, Cpasajero* p);
	string to_string();
	void imprimir();
	void comisario_pregunta();
};

