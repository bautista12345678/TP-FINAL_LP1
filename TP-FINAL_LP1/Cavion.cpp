#include "Cavion.h"
int Cavion::cantidadDeAsientos = 0;
int Cavion::cont_id = 0;
//int Cavion::n_eventos = 0;
Cavion::Cavion(clista<Cpersona>* _ListaCompleta, clista<Cpasajero>* _ListaDePasajeros, clista<cCodigo>* _listaCodigos, Ccomisario* m, clista<Casiento>* _ListaAsientos,int n, clista<Cpasajero>* _prision) :id(cont_id + 1)
{
	marshal = m;
	ListaCompleta = _ListaCompleta;
	ListaDePasajeros = _ListaDePasajeros;
	listaCodigos = _listaCodigos;
	NumeroDeAsiento = n;
	ListaAsientos = _ListaAsientos;
	prision = _prision;
	
}

Cavion::~Cavion()
{
	for (int i = 0; i < ListaCompleta->getcantidad(); i++)
	{
		ListaCompleta[i] = NULL;
	}
	for (int j = 0; j < ListaDePasajeros->getcantidad(); j++)
	{
		ListaDePasajeros[j] = NULL;
	}
	for (int k = 0; k < listaCodigos->getcantidad(); k++)
	{
		listaCodigos[k] = NULL;
	}
	delete ListaCompleta;
	delete ListaDePasajeros;
	delete listaCodigos;
}

/*int Cavion::getn_eventos()
{
	for (int i = 0; i < ListaDePasajeros->getcantidad(); i++)
	{
		n_eventos = n_eventos + 1;
	}
	return n_eventos;
}*/

/*string* Cavion::getListaEventos()
{
	return ListaEventos;
}*/

Casiento* Cavion::asientocomisario()
{
	int cont = 0;
	for (int i = 0; i < ListaAsientos->getcantidad(); i++)
	{
		if (ListaAsientos->getLista()[i] == NULL)
		{
			cont++;
		}
	}
	clista<Casiento>* aux = new clista<Casiento>(cont);
	Casiento* randasiento;
	for (int i = 0; i < ListaAsientos->getcantidad(); i++)
	{
		
		if (ListaAsientos->getLista()[i]==NULL)
		{
			for (int k = 0; i < cont; k++) {
				aux->getLista()[k] = ListaAsientos->getLista()[i];
					
			}
		}
	}
	randasiento = aux->getLista()[rand() % cont];

	return randasiento;
}

clista<Cpasajero>* Cavion::getListaDePasajeros()
{
	return ListaDePasajeros;
}

clista<cCodigo>* Cavion::getlistaCodigos()
{
	return listaCodigos;
}

clista<Cpasajero>* Cavion::getprision()
{
	return prision;
}

clista<Cpersona>* Cavion::getListaCompleta()
{
	return ListaCompleta;
}

clista<Casiento>* Cavion::getListaAsientos()
{
	return ListaAsientos;
}


/*void Cavion::agregar(Cazafata *a)
{
	string* aux1 = new string[n_eventos + 1];
	for (int i = 0; i < n_eventos; i++)
	{
		aux1[i] = ListaEventos[i];
    }
	delete[] ListaEventos;
	for (int j = 0; j < ListaDePasajeros->getcantidad(); j++)
	{
		if (ListaDePasajeros->getLista()[j]->PedirAyuda(a) == true)
		{
			string* aux1 = new string[n_eventos + 1];
			for (int i = 0; i < n_eventos; i++)
			{
				aux1[i] = ListaEventos[i];
			}
			string y = ListaDePasajeros->getLista()[j]->getnombre()+"pidio ayuda";
				aux1[n_eventos + 1] = y;
				ListaEventos = aux1;
				delete aux1;
		}
		if (ListaDePasajeros->getLista()[j]->pedirBebida(a) == true)
		{
			string* aux2 = new string[n_eventos + 1];
			for (int i = 0; i < n_eventos; i++)
			{
				aux2[i] = ListaEventos[i];
			}
			string y = ListaDePasajeros->getLista()[j]->getnombre() + "pidio bebida";
			aux1[n_eventos + 1] = y;
			ListaEventos = aux2;
			delete aux2;
		}
		if (ListaDePasajeros->getLista()[j]->pedirComida(a) == true)
		{
			string* aux3 = new string[n_eventos + 1];
			for (int i = 0; i < n_eventos; i++)
			{
				aux3[i] = ListaEventos[i];
			}
			string y = ListaDePasajeros->getLista()[j]->getnombre() + "pidio comida";
			aux1[n_eventos + 1] = y;
			ListaEventos = aux3;
			delete aux3;
		}
		if (ListaDePasajeros->getLista()[j]->recibirMensaje(a) == true)
		{
			string* aux4 = new string[n_eventos + 1];
			for (int i = 0; i < n_eventos; i++)
			{
				aux4[i] = ListaEventos[i];
			}
			string y = ListaDePasajeros->getLista()[j]->getnombre() + "recibio mensaje";
			aux1[n_eventos + 1] = y;
			ListaEventos = aux4;
			delete aux4;
		}
	}
	
}*/

void Cavion::comparaAmbasListas(clista<Cpasajero>* ListaP)
{
	for (int i = 0; i < ListaDePasajeros->getcantidad(); i++)
	{
		if (listaCodigos->getLista()[i]->getDNI() == ListaP->getLista()[i]->getcodigo()->getDNI()
			&& listaCodigos->getLista()[i]->getsector() == ListaP->getLista()[i]->getcodigo()->getsector()
			&& listaCodigos->getLista()[i]->getfila() == ListaP->getLista()[i]->getcodigo()->getfila()
			&& listaCodigos->getLista()[i]->getletra() == ListaP->getLista()[i]->getcodigo()->getletra())
		{
			this->SubirAlAvion(ListaP->getLista()[i]);
		}
		else {
			this->BajarAlAvion(ListaP->getLista()[i]);
		}
	}
}

void Cavion::SubirAlAvion(Cpasajero* p)
{
	(*ListaDePasajeros) + (p);
	for (int i = 0; i < ListaAsientos->getcantidad(); i++)
	{
		if (ListaAsientos->getLista()[i]->getfila() == p->getAsiento()->getfila() &&
			ListaAsientos->getLista()[i]->getcolumna() == p->getAsiento()->getcolumna())
		{
			cout << "asiento ocupado" << endl;
			return;
		}
		else {
			(*ListaAsientos) + (p->getAsiento());
			return;
		}
	}
}

void Cavion::BajarAlAvion(Cpasajero* p)
{
	delete p;

}

void Cavion::imprimirPasajerosAbordo()
{

	ListaDePasajeros->listar();

}

void Cavion::imprimircantidadDePasajerosAbordo()
{
	cout << this->CatidadDeAsientosOcupados << endl;
}

Ccomisario* Cavion::getmarshal()
{
	return marshal;
}
