#include "Cavion.h"
int Cavion::cantidadDeAsientos = 0;
int Cavion::cont_id = 0;
Cavion::Cavion(clista<Cpersona>* _ListaCompleta, clista<Cpasajero>* _ListaDePasajeros, clista<cCodigo>* _listaCodigos, Ccomisario* m) :id(cont_id + 1)
{
	marshal = m;
	ListaCompleta = _ListaCompleta;
	ListaDePasajeros = _ListaDePasajeros;
	listaCodigos = _listaCodigos;
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
