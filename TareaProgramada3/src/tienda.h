#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include <string>
#include "producto.h"
#include <cstring>
#include <iostream>

using namespace std;

class Tienda {
    vector<Producto *> productos;

    char nombreT[15]; //T = Tienda
    char direccionI[24]; //I = Internet
    char direccionF[24]; //F = Fisica
    char telefono[8]; 

    public:
    Tienda(string nombreT, string direccionI, string direccionF, string telefono);
    Tienda();
    ~Tienda();

    void AgregarProducto(Producto *nuevoProducto);

    string ObtenerNombreT();
    string ObtenerDireccionI();
    string ObtenerDireccionF();
    string ObtenerTelefono(); 

    void GuardarArchivo(ostream *streamSalida);
    void CargarArchivo(istream *streamEntrada, Tienda *tienda);
    void ModificarTienda(Tienda *tienda);

    friend ostream& operator << (ostream &o, const Tienda *tienda);


};


#endif 