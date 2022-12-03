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
	clista<Cpasajero>* prision = new clista<Cpasajero>(10);
	Cavion* avion1 = new Cavion(ListaCompleta, listaDePasajeros1, listaCodigos1, comisario1,ListaAsientos,30,prision);
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
	piloto1->pilotear();
	piloto1->imprimir();
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
		
		avion1->getprision()->listar();
	}
	else {
		cout << "no hay un nuevo pasajero sometido y encarcelado. " << endl;
	}
	comisario1->imprimir();

	pasajero4->pedirChampagne(azafata1);
	pasajero4->terminarChampagne();
	//cout << "cantidad de eventos: " << azafata1->getEventos() + azafata2->getEventos() << endl;
	for (int i = 0; i < avion1->getListaCompleta()->getcantidad(); i++)
	{
		
		Cturista* turista_aux = dynamic_cast <Cturista*> (avion1->getListaCompleta()->getLista()[i]);
		if (turista_aux != nullptr) {
			cout << " eventos de "<< avion1->getListaCompleta()->getLista()[i]->getnombre() << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio ayuda " << turista_aux->getcont_ayuda() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio comida " << turista_aux->getcont_comida() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio bebida " << turista_aux->getcont_bebida() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " recibio mensajes " << turista_aux->getcont_mensaje() << " veces " << endl;
		}


		Cejecutivo* eje_aux = dynamic_cast <Cejecutivo*> (avion1->getListaCompleta()->getLista()[i]);
		if (eje_aux != nullptr) {
			cout << " eventos de " << avion1->getListaCompleta()->getLista()[i]->getnombre() << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio ayuda " << eje_aux->getcont_ayuda() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio comida " << eje_aux->getcont_comida() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio bebida " << eje_aux->getcont_bebida() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " recibio mensajes " << eje_aux->getcont_mensaje() << " veces " << endl;
		}


		CprimeraClase* primerclase_aux = dynamic_cast <CprimeraClase*> (avion1->getListaCompleta()->getLista()[i]);
		if (primerclase_aux != nullptr) {
			cout << " eventos de " << avion1->getListaCompleta()->getLista()[i]->getnombre() << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio ayuda " << primerclase_aux->getcont_ayuda() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio comida " << primerclase_aux->getcont_comida() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio bebida " << primerclase_aux->getcont_bebida() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " recibio mensajes " << primerclase_aux->getcont_mensaje() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio champagn " << primerclase_aux->getcont_cham() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio masaje " << primerclase_aux->getcont_masaje() << " veces " << endl;
		}


		Cpiloto* piloto_aux = dynamic_cast <Cpiloto*> (avion1->getListaCompleta()->getLista()[i]);
		if (piloto_aux != nullptr) {
			cout << " eventos de " << avion1->getListaCompleta()->getLista()[i]->getnombre() << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio comida " << piloto_aux->getcont_com() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio bebida " << piloto_aux->getcont_beb()<< " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " dio mensajes " << piloto_aux->getcont_pasaj() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " dio anuncios " << piloto_aux->getcont_anuncio() << " veces " << endl;

		}
		Ccopiloto* copiloto_aux = dynamic_cast <Ccopiloto*> (avion1->getListaCompleta()->getLista()[i]);
		if (copiloto_aux != nullptr) {
			cout << " eventos de " << avion1->getListaCompleta()->getLista()[i]->getnombre() << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio comida " << copiloto_aux->getcont_com() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " pidio bebida " << copiloto_aux->getcont_beb() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " dio mensajes " << copiloto_aux->getcont_pasaj() << " veces " << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " dio anuncios " << copiloto_aux->getcont_anuncio() << " veces " << endl;

		}

		Ccomisario* c_aux = dynamic_cast <Ccomisario*> (avion1->getListaCompleta()->getLista()[i]);
		if (c_aux != nullptr) {
			cout << " eventos de " << avion1->getListaCompleta()->getLista()[i]->getnombre() << endl;
			cout << avion1->getListaCompleta()->getLista()[i]->getnombre() << " encarcelo pasajeros  " << c_aux->getcont_encarcelados() << " veces " << endl;
		}
	}





	


	return 0;
}