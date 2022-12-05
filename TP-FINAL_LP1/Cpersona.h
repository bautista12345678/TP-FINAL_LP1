#pragma once
#include <iostream>
#include<string>
using namespace std;
enum class EnumPersonalDeVuelo
{
	pasajero, comisario, azafata, piloto, ninguno

};
class Cpersona
{
private:
	string nombre;
	string dni;
	bool sexo;
	EnumPersonalDeVuelo personalDeVuelo;
	static int numeroDeAsiento;
public:
	Cpersona(string _nombre, string _dni);
	Cpersona(const Cpersona&);
	~Cpersona();
	string getnombre();
	void setnombre(string n);
	string getdni();
	virtual void imprimir() = 0;
	virtual string to_string() = 0;
};



