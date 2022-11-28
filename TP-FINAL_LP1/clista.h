#pragma once
#include <iostream>
#define AMP 10
using namespace std;

template <class T>
class clista {
private:
	T** lista;
	unsigned int cantidad;
	unsigned int capacidad;

public:
	clista(unsigned int _ct);
	void operator+ (T* Elemento);
	void eliminar(T* Elemento);
	T* operator[](string _codigo);
	T* quitarcod(unsigned int codigo);
	void operator - (T* Elemento);
	T* quitarpos(int pos);
	//ostream& operator<<(ostream& os, cListaT<T>& _lista);
	void operator ==(unsigned int codigo);//agregar estas ultimas sobrecargas
	void resize();
	unsigned int getcantidad();
	unsigned int getcapacidad();
	void listar();
	T** getLista();
	~clista();
};

template<class T>
inline void clista<T>::resize()
{
	unsigned int newct = 0;
	newct = this->capacidad + AMP;
	T** listaaux = new T * [newct];
	memcpy(listaaux, this->lista, sizeof(T*) * this->capacidad);
	delete[] lista;
	this->lista = listaaux;
	this->capacidad = newct;
}

template <class T>
clista<T>::clista(unsigned int _ct)
{
	cantidad = 0;
	capacidad = _ct;
	lista = new T * [capacidad];
	for (int i = 0; i < capacidad; i++) {
		lista[i] = nullptr;
	}
}
template<class T>
inline unsigned int clista<T>::getcantidad()
{
	return cantidad;
}
template<class T>
inline unsigned int clista<T>::getcapacidad()
{
	return capacidad;
}

template<class T>
T** clista<T>::getLista() {
	return lista;
}
template <class T>
clista<T>:: ~clista()
{
	for (unsigned int i = 0; i < capacidad; i++) {
		delete lista[i];
	}
	delete[] lista;
}

template<class T>
ostream& operator<<(ostream& os, clista<T>& _lista)
{
	// TODO: Insertar una instrucción "return" aquí
	os << _lista->getLista() << endl;
	return os;
}
template<class T>
inline void clista<T>:: operator+(T* Elemento)
{
	try {
		if (Elemento == nullptr)throw new exception("Error Elemento Nulo");

		if (cantidad >= capacidad) {
			//		throw new exception("No hay tamaño suficiente para agregar el item");
			this->resize();
		}
		else {
			lista[cantidad] = Elemento;
			cantidad++;
		}
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
}
template <class T>
inline void clista<T>::eliminar(T* Elemento) {
	unsigned int pos = 0;
	try {
		if (Elemento == nullptr)throw "Error Elemento nulo";

		if (lista[cantidad] == Elemento) {
			lista[cantidad] == nullptr;
			cantidad--;
		}
		else {
			for (int i = 0; i < cantidad - 1; i++)
			{
				if (lista[i] == Elemento)
				{
					pos = i;
				}
			}
			for (int j = pos; j < cantidad - 1; j++) {
				lista[j] = lista[j + 1];
			}
			lista[cantidad] = nullptr;
			cantidad--;
		}
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
}

template <class T>
inline T* clista<T>::operator[](string _codigo) {
	int i;
	for (i = 0; i < cantidad; i++) {
		if (lista[i]->getCodigo() == _codigo) return lista[i];
	}if (i = cantidad)return nullptr;
}
template <class T>
inline T* clista<T>::quitarcod(unsigned int codigo)
{
	int pos = 0;
	T* aux;
	for (int i = 0; i < cantidad; i++)
	{
		if (*(lista[i]) == codigo)
		{
			aux = lista[i];
			pos = i;
			this->eliminar(lista[i]);
		}
	}

	return aux;
}
template <class T>
inline void clista<T>:: operator-(T* Elemento)
{
	this->eliminar(Elemento);
}
template <class T>
inline void clista<T>:: operator==(unsigned int codigo)
{

	for (int i = 0; i < cantidad; i++) {
		if (lista[i].GetCodigo() == codigo) {
			return true;
		}
	}
}
template <class T>
inline T* clista<T>::quitarpos(int pos)
{
	T* aux;
	aux = lista[pos];
	this->eliminar(lista[pos]);
	return aux;
}
template <class T>
inline void clista<T>::listar()
{
	for (unsigned int i = 0; i < cantidad; i++)
	{
		cout << " " << i + 1 << ":  " << lista[i] << endl;
	}
}
