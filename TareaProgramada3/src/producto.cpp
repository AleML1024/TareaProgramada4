#include "producto.h"


using namespace std;

Producto::Producto(int id, string nombreP, int existencias)
{
    this->id = id;
    strcpy(this->nombreP, nombreP.c_str());
    this->existencias = existencias;
}

Producto::Producto()
{
    this->id = 0;
    strcpy(this->nombreP, "");
    this->existencias = 0;
}

int Producto::ObtenerId()
{
    return this->id;
}


string Producto::ObtenerNombreP()
{
    return this->nombreP;
}


int Producto::ObtenerExistencias()
{
    return this->existencias;
}

void Producto::ModificarNombre(string nombreTemp)
{   
    string nula = "                   ";
    strcpy(nombreP, nula.c_str());    
    strcpy(nombreP, nombreTemp.c_str());
}

void Producto::ModificarExistencias(int existenciasTemp)
{
    existencias = existenciasTemp;
}

ostream& operator << (ostream &o, const Producto *producto)
{
    o << "[" << producto->id << "] - " << producto->nombreP << " - Existencias: " << producto->existencias << "\n";
    return o; 
}