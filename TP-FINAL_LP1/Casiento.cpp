#include "Casiento.h"

Casiento::Casiento()
{
		fila = rand() % 16;
		int aux = rand() % 2;;
		if (aux == 0)
		{
			columna = "a";
		}
		else if (aux == 1)
		{
			columna = "b";
		}
		else {
			cout << "columna no valida" << endl;
		}
		
}

Casiento::~Casiento()
{

}

int Casiento::getfila()
{
	return fila;
}

string Casiento::getcolumna()
{
	return columna;
}
