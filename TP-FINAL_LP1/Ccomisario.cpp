#include "Ccomisario.h"
#include <sstream>
Ccomisario::Ccomisario(string _nombre, string _dni):Cpersona(_nombre, _dni)
{
    TodoEnOrden = true;
}

Ccomisario::~Ccomisario()
{
}



bool Ccomisario::preguntarSiTodoEstaEnOrden(Cavion* a)
{
    for (int i = 0; i < a->getListaDePasajeros()->getcantidad(); i++)
    {
        if (a->getListaDePasajeros()->getLista()[i]->getBuenaConducta() == false)
        {
            this->someterPasajero(a->getListaDePasajeros()->getLista()[i]);
            this->encerrapasajero(a, a->getListaDePasajeros()->getLista()[i]);
            return false;
        }
        else {
            return true;
        }
    }
    return true;
}

bool Ccomisario::someterPasajero(Cpasajero* p)
{
    p->someter();
    return true;
}

void Ccomisario::encerrapasajero(Cavion* a, Cpasajero* p)
{
    (*a->getprision()) + (p);
}

string Ccomisario::to_string()
{
    stringstream ss;
    ss << "nombre del comisario: " << this->getnombre() << endl;
    ss << "dni: " << this->getdni() << endl;
    return ss.str();
}

void Ccomisario::imprimir()
{
    cout << to_string() << endl;
}

void Ccomisario::comisario_pregunta()
{
    cout << "comisario pregunta si todo esta en orden?. " << endl;
    cout << endl;
}

