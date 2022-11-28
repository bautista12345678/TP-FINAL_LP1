#include "Cpasajero.h"
#include <sstream>
Cpasajero::Cpasajero(string _nombre, string _dni, EnumPrivilegios p, cCodigo* _c) :Cpersona(_nombre, _dni)
{
    TipoDePrivilegio = p;
    codigo = _c;
    BuenaConducta = true;;
    sometido = false;


}


bool Cpasajero::getBuenaConducta()
{
    return BuenaConducta;
}

void Cpasajero::someter()
{
    sometido = true;
}

void Cpasajero::setconduta(bool _conducta)
{
    this->BuenaConducta = _conducta;
}

cCodigo* Cpasajero::getcodigo()
{
    return codigo;
}

/*string Cpasajero::to_string()
{
    stringstream ss;
    ss << "nombre: " << this->getnombre() << endl;
    ss << "dni: " << this->getdni() << endl;
    ss << "codigo: " << this->getcodigo() << endl;
    return ss.str();
}

void Cpasajero::imprimir()
{
    cout << to_string();
}*/






