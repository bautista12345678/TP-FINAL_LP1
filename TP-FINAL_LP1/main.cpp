#include<iostream>
#include<cstdlib>
#include<string>
#include"Cpasajero.h"
#include "Cavion.h"
#include "clista.h"
#include "Cejecutivo.h"
#include "CprimeraClase.h"
#include "Cturista.h"
#include "Ccopiloto.h"
#include "Ccomisario.h"
#define N 5;
using namespace std;
//turista, ejecutivo, primaveraClase, ninguno
int main() {

	//----------------creando azafatas--------------------------------

	

	Cazafata* azafata1 = new Cazafata("soledad", "94445678", true);
	Cazafata* azafata2 = new Cazafata("lucho", "12345678", true);
    
	azafata1->imprimir();
	azafata2->imprimir();

//-----------------creo asientos----------------------------------------

	Casiento* asiento1 = new Casiento();
	Casiento* asiento2 = new Casiento();
	Casiento* asiento3 = new Casiento();
	Casiento* asiento4 = new Casiento();
	Casiento* asiento5 = new Casiento();

	clista<Casiento>* ListaAsientos = new clista<Casiento>(30);

	(*ListaAsientos) + asiento1;
	(*ListaAsientos) + asiento2;
	(*ListaAsientos) + asiento3;
	(*ListaAsientos) + asiento4;
	(*ListaAsientos) + asiento5;

	
//---------------------- generando los codigos de cada pasajero
	cCodigo* codigo1 = new cCodigo("TU", "1234", asiento1->getfila(),asiento1->getcolumna());
	cCodigo* codigo2 = new cCodigo("BS", "1233", asiento2->getfila(), asiento2->getcolumna());
	cCodigo* codigo3 = new cCodigo("BS", "1232", asiento3->getfila(), asiento3->getcolumna());
	cCodigo* codigo4 = new cCodigo("PC", "1231", asiento4->getfila(), asiento4->getcolumna());
	cCodigo* codigo5 = new cCodigo("PC", "1235", asiento5->getfila(), asiento5->getcolumna());
	     //--------------------- imprimir codigos -------------------
	codigo1->imprimir();
	codigo2->imprimir();
	codigo3->imprimir();
	codigo4->imprimir();
	codigo5->imprimir();
//-------------------- crendo los pasajeros----------------

	Cturista* pasajero1 = new Cturista("lucho", "1234", EnumPrivilegios::turista, codigo1,asiento1);
	Cejecutivo* pasajero2 = new Cejecutivo("jose", "1233", EnumPrivilegios::ejecutivo, codigo2,asiento2);
	Cejecutivo* pasajero3 = new Cejecutivo("pedro", "1232", EnumPrivilegios::ejecutivo, codigo3,asiento3);
	CprimeraClase* pasajero4 = new CprimeraClase("anais", "1231", EnumPrivilegios::primaveraClase, codigo4,asiento4);
	CprimeraClase* pasajero5 = new CprimeraClase("maria", "1235", EnumPrivilegios::primaveraClase, codigo5,asiento5);

	//------------------------- imprimiendo pasajeros -----------------------
	pasajero1->imprimir();
	pasajero2->imprimir();
	pasajero3->imprimir();
	pasajero4->imprimir();
	pasajero5->imprimir();
	
	//--------------------creando piloto, copiloto y comisario -----------------------------------

	Cpiloto* piloto1 = new Cpiloto("bau", "2242355");
	Ccopiloto* copiloto1 = new Ccopiloto("mati", "4647384");
	Ccomisario* comisario1 = new Ccomisario("marshal", "736373");
	cout << piloto1->to_string() << endl;
	cout << copiloto1->to_string() << endl;
	cout << comisario1->to_string() << endl;
	//--------------------------------------


	clista<Cpasajero>* listaDePasajeros1 = new clista<Cpasajero>(5);
	try {
		(*listaDePasajeros1) + (pasajero1);
		(*listaDePasajeros1) + (pasajero2);
		(*listaDePasajeros1) + (pasajero3);
		(*listaDePasajeros1) + (pasajero4);
		(*listaDePasajeros1) + (pasajero5);

	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	clista<cCodigo>* listaCodigos1 = new clista<cCodigo>(5);
	try {

		(*listaCodigos1) + (codigo1);
		(*listaCodigos1) + (codigo2);
		(*listaCodigos1) + (codigo3);
		(*listaCodigos1) + (codigo4);
		(*listaCodigos1) + (codigo5);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	clista<Cpersona>* ListaCompleta = new clista<Cpersona>(40);
	try {
		(*ListaCompleta) + (azafata1);
		(*ListaCompleta) + (azafata2);
		(*ListaCompleta) + (pasajero1);
		(*ListaCompleta) + (pasajero2);
		(*ListaCompleta) + (pasajero3);
		(*ListaCompleta) + (pasajero4);
		(*ListaCompleta) + (pasajero5);
		(*ListaCompleta) + (piloto1);
		(*ListaCompleta) + (copiloto1);
		(*ListaCompleta) + (comisario1);

	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	Cavion* avion1 = new Cavion(ListaCompleta, listaDePasajeros1, listaCodigos1, comisario1,ListaAsientos,30);
	avion1->getListaCompleta()->listar();
	//-----------------------------------------------------------
	cout << "llamomos a una azafata que esta no disponilble" << endl;
	pasajero1->pedirBebida(azafata2);
	pasajero1->imprimir();
	cout << "llamomos a una azafata que esta si disponilble" << endl;
	pasajero1->pedirBebida(azafata1);
	pasajero1->imprimir();
	pasajero1->terminarBeber();
	pasajero1->imprimir();
	pasajero1->pedirComida(azafata1);
	pasajero1->imprimir();
	pasajero1->terminatComer();
	pasajero1->imprimir();
	//------------------------------------------------------------
	piloto1->pedirBebida(azafata1);
	piloto1->AnuncioAltaVoz("estamos proximos a despegar.", azafata1);
	azafata1->setDisponibilidad(true);
	piloto1->pedirBebida(azafata1);
	piloto1->setbebida(false);
	azafata1->setDisponibilidad(false);
	piloto1->pilotear();
	//--------------------------- comisario ------------------------
	comisario1->comisario_pregunta();
	if (comisario1->preguntarSiTodoEstaEnOrden(avion1) == false)
	{
		cout << "el pasajero esta encarcelado" << endl;
	}
	else {
		cout << "no hay un nuevo pasajero sometido y encarcelado. " << endl;
	}
	cout << endl;
	cout << "--- despues de haber comenzado el vuelo el comisario nuevamente pregunta si todo esta bien ---" << endl;
	cout << endl;
	pasajero2->setconduta(true); //un pasajero se porto mal
	if (comisario1->preguntarSiTodoEstaEnOrden(avion1) == true)
	{
		cout << "el pasajero esta encarcelado" << endl;
	}
	else {
		cout << "no hay un nuevo pasajero sometido y encarcelado. " << endl;
	}


	pasajero4->pedirChampagne();

	cout << "cantidad de eventos: " << azafata1->getEventos() + azafata2->getEventos() << endl;
	for (int i = 0; i < avion1->getListaDePasajeros()->getcantidad(); i++)
	{
		cout << " eventos del pasajero n " << i << endl;
		cout << avion1->getListaDePasajeros()->getLista()[i]->getnombre() << " pidio ayuda " << avion1->getListaDePasajeros()->getLista()[i]->getcont_ayuda() << " veces "<<endl;
		cout << avion1->getListaDePasajeros()->getLista()[i]->getnombre() << " pidio comida " << avion1->getListaDePasajeros()->getLista()[i]->getcont_comida() << " veces " << endl;
		cout << avion1->getListaDePasajeros()->getLista()[i]->getnombre() << " pidio bebida " << avion1->getListaDePasajeros()->getLista()[i]->getcont_bebida() << " veces " << endl;
		cout << avion1->getListaDePasajeros()->getLista()[i]->getnombre() << " recibio mensajes " << avion1->getListaDePasajeros()->getLista()[i]->getcont_mensaje() << " veces " << endl;
	


	}





	/*avion1->getn_eventos();
	for (int i = 0; i < avion1->getn_eventos(); i++)
	{
		cout<<avion1->getListaEventos()[i]<<endl;
	}
	*/


	return 0;
}