#include "tienda.h"
#include <iostream>
#include <fstream>
#include "excepcionRespuestaInvalida.h"

Tienda::Tienda(string nombreT, string direccionI, string direccionF, string telefono)
{
    strcpy(this->nombreT, nombreT.c_str());
    strcpy(this->direccionI, direccionI.c_str());
    strcpy(this->direccionF, direccionF.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Tienda::Tienda()
{
    strcpy(this->nombreT, "");
    strcpy(this->direccionI, "");
    strcpy(this->direccionF, "");
    strcpy(this->telefono, "");
}

Tienda::~Tienda()
{
    for (Producto *producto : this->productos)
    {
        delete producto;
    }
}

string Tienda::ObtenerNombreT()
{
    return this->nombreT;
}

string Tienda::ObtenerDireccionI()
{
    return this->direccionI;
}

string Tienda::ObtenerDireccionF()
{
    return this->direccionF;
}

string Tienda::ObtenerTelefono()
{
    return this->telefono;
}

void Tienda::AgregarProducto(Producto *nuevoProducto)
{
    this->productos.push_back(nuevoProducto);
}

void Tienda::GuardarArchivo(ostream *streamSalida)
{
    streamSalida->write((char *)nombreT, sizeof(nombreT));
    streamSalida->write((char *)direccionI, sizeof(direccionI));
    streamSalida->write((char *)direccionF, sizeof(direccionF));
    streamSalida->write((char *)telefono, sizeof(telefono));

    for (Producto *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void Tienda::CargarArchivo(istream *streamEntrada, Tienda *tienda)
{
    int location = 0;
    size_t tempSize = 0;

    // Calcule cantidad de registros
    streamEntrada->seekg(0, std::ios::end);
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = (cantidadBytesEnArchivo - (sizeof(Tienda) - 25)) / sizeof(Producto);

    cout << cantidadProductos << endl;

    streamEntrada->seekg(0, std::ios::beg);                // Empezar desde el principio del archivo
    streamEntrada->read((char *)nombreT, sizeof(nombreT)); // variable para guardar y cuántos bytes leo
    location += sizeof(nombreT);
    streamEntrada->read((char *)direccionI, sizeof(direccionI));
    location += sizeof(direccionI);
    streamEntrada->read((char *)direccionF, sizeof(direccionF));
    location += sizeof(direccionF);
    streamEntrada->read((char *)telefono, sizeof(telefono));
    location += sizeof(telefono);

    // Empezar desde abajo de la informacion de la tienda
    streamEntrada->seekg(location, ios::beg);
    for (int indice = 0; indice < cantidadProductos; indice++) // Leer cada producto
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto));
        this->AgregarProducto(producto);
    }
}

void Tienda::ModificarTienda(Tienda *tienda)
{
    string condicion;
    while (condicion != "Si" & condicion != "No")
    {   
        try{
            cout << "¿Desea modificar la información de algún producto de su tienda? 'Si' 'No' \n";
            cin >> condicion;
        }catch(const ExcepcionRespuestaInvalida& e){
            cout << "Porfavor responder con 'Si' o 'No' \n";
        }
    }

    int idAModificar;
    string nombreTemp;
    int existenciasTemp;

    if (condicion == "Si")
    {
        while (condicion == "Si")
        {
            while (cout << "Ingrese la id del producto que desea modificar:  \n" && !(cin >> idAModificar))
            {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "Dato invalido. Porfavor digite un número.\n";
            }

            cout << "¿Desea modificar el nombre del producto? 'Si' 'No' \n";
            cin >> condicion;

           while (condicion != "Si" & condicion != "No")
            {   
                try{
                    cout << "¿Desea modificar el nombre del producto 'Si' 'No' \n";
                    cin >> condicion;
                }catch(const ExcepcionRespuestaInvalida& e){
                    cout << "Porfavor responder con 'Si' o 'No' \n";
                }
            }

            if (condicion == "Si")
            {
                cout << "Ingrese el nuevo nombre \n";
                cin >> nombreTemp;
                productos[idAModificar - 1]->ModificarNombre(nombreTemp);

            }else if(condicion == "No")
            {
                cout << "El nombre no ha sido modificado \n";
            }

            cout << "¿Desea modificar las existencias del producto? 'Si' 'No' \n";
            cin >> condicion;

            while (condicion != "Si" & condicion != "No")
            {   
                try{
                    cout << "¿Desea modificar las existencias del producto 'Si' 'No' \n";
                    cin >> condicion;
                }catch(const ExcepcionRespuestaInvalida& e){
                    cout << "Porfavor responder con 'Si' o 'No' \n";
                }
            }

            if (condicion == "Si")
            {
                while (cout << "Ingrese las nuevas existencias \n" && !(cin >> existenciasTemp))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Dato invalido. Porfavor digite un número.\n";
                }
               
                productos[idAModificar - 1]->ModificarExistencias(existenciasTemp);

            }else if(condicion == "No")
            {
                cout << "Las existencias no han sido modificadas \n";
            }

            cout << "¿Desea modificar algún otro producto? 'Si' 'No' \n";
            cin >> condicion;

            while (condicion != "Si" & condicion != "No")
            {   
                try{
                    cout << "¿Desea modificar algún otro producto 'Si' 'No' \n";
                    cin >> condicion;
                }catch(const ExcepcionRespuestaInvalida& e){
                    cout << "Porfavor responder con 'Si' o 'No' \n";
                }
            } 
        }
        cout << "¿Desea generar un archivo.dat? 'Si' o 'No' \n";
        cin >> condicion;

        while (condicion != "Si" & condicion != "No")
            {   
                try{
                    cout << "¿Desea generar un archivo.dat? 'Si' o 'No' \n";
                    cin >> condicion;
                }catch(const ExcepcionRespuestaInvalida& e){
                    cout << "Porfavor responder con 'Si' o 'No' \n";
                }
            } 

        if(condicion == "Si")
        {
        string nombreArchivo;
        cout << "Ingrese el nombre del archivo que se generará: ";
        cin >> nombreArchivo;

        ofstream archivoDeSalida;
        archivoDeSalida.open(nombreArchivo + ".dat", ios::out | ios::binary);

        if (!archivoDeSalida.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_prueba.dat para escribir los datos";
        }

        tienda->GuardarArchivo(&archivoDeSalida);

        archivoDeSalida.close();
        
        cout << "Generando archivo.dat...\n";
        
        }else if(condicion == "No")
        {
            cout << "Saliendo del sistema...\n";
        }
    }else if (condicion == "No")
    {
        cout << "Saliendo del sistema...\n";
    }
}

ostream &operator<<(ostream &o, const Tienda *tienda)
{
    o << "Tienda: " << tienda->nombreT << "\nDirección de internet: " << tienda->direccionI << "\nDirección física: " << tienda->direccionF << "\nTeléfono: " << tienda->telefono << "\n"
      << std::endl;

    for (Producto *producto : tienda->productos)
    {
        o << producto << endl;
    }

    return o;
}
