#pragma once
#include <iostream>
#include <string>
using namespace std;
class cCodigo
{
private:
	string sector;
	string DNI;
	int fila;
	string letra;
public:
	cCodigo(string _sector, string _DNI, int _fila, string _letra);
	~cCodigo();
	string getsector();
	string getDNI();
	int getfila();
	string getletra();
	string to_string();
	void imprimir();
};

