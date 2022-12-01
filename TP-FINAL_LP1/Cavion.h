#pragma once
#include<string>
#include"Cpasajero.h"
#include "clista.h"
class Ccomisario;
using namespace std;

class Cavion
{
private:
	static int cont_id;
	const int id;
	static int asientos;
	int  AsientoAleatorioComisario;
	static int cantidadDeAsientos;
	int CatidadDeAsientosOcupados;
	string CodigoDeIngresoAlAvion;
	clista<Cpersona>* ListaCompleta;
	clista<Cpasajero>* ListaDePasajeros;
	clista<cCodigo>* listaCodigos;
	clista<Cpasajero>* prision;
	clista<Casiento>* ListaAsientos;
	int NumeroDeAsiento;
	Ccomisario* marshal;
public:
	Cavion(clista<Cpersona>* _ListaCompleta, clista<Cpasajero>* _ListaDePasajeros, clista<cCodigo>* _listaCodigos, Ccomisario* m, clista<Casiento>* _ListaAsientos,int n);
	~Cavion();
	clista<Cpasajero>* getListaDePasajeros();
	clista<cCodigo>* getlistaCodigos();
	clista<Cpasajero>* getprision();
	clista<Cpersona>* getListaCompleta();
	clista<Casiento>* getListaAsientos();
	void comparaAmbasListas(clista<Cpasajero>* Lista);
	void SubirAlAvion(Cpasajero* p);
	void BajarAlAvion(Cpasajero* p);
	void imprimirPasajerosAbordo();
	void imprimircantidadDePasajerosAbordo();
	Ccomisario* getmarshal();
};

