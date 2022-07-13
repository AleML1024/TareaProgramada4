#include <gtest/gtest.h>
#include "/home/alessandro/TareaProgramada3/src/tienda.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace
{
    TEST(Tienda_Tests, Tests_Crear_Tienda)
    {
        /// AAA
        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda ("Tienda1", "www.tienda1.com", "Av.39A,C.106B", "22907465");

        // Act - ejecute la operación
        string nombreActual = tienda->ObtenerNombreT();
        string direccionIActual = tienda->ObtenerDireccionI();
        string direccionFActual = tienda->ObtenerDireccionF();
        string telefonoActual = tienda->ObtenerTelefono();

        string nombreEsperado = "Tienda1";
        string direccionIEsperada = "www.tienda1.com";
        string direccionFEsperada = "Av.39A,C.106B";
        string telefonoEsperado = "22907465";

        // Assert - valide los resultados
        EXPECT_EQ(nombreActual, nombreEsperado);
        EXPECT_EQ(direccionIActual, direccionIEsperada);
        EXPECT_EQ(direccionFActual, direccionFEsperada);
        EXPECT_EQ(telefonoActual, telefonoEsperado);

        delete tienda;

    }

    TEST(Tienda_Tests, Test_Crear_Leer_Archivo_Binario)
    {
        /// AAA
        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda ("Tienda1", "www.tienda1.com", "Av.39A,C.106B", "22907465");

        Producto *producto1 = new Producto(1, "Pasta", 20);
        tiendaEsperada->AgregarProducto(producto1);

        // Act - ejecute la operación
        //Guardar Archivo
        ofstream archivoDeSalida;
        archivoDeSalida.open("archivo_tests.dat", ios::out|ios::binary);

        if (!archivoDeSalida.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_tests.dat para escribir los datos";
            FAIL();
        }

        tiendaEsperada->GuardarArchivo(&archivoDeSalida);

        archivoDeSalida.close();
        
        //Cargar Archivo
        ifstream archivoDeEntrada;
        archivoDeEntrada.open("archivo_tests.dat", ios::in|ios::binary);

        if (!archivoDeEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_tests.dat para leer los datos";
            FAIL();
        }
    
        Tienda *tiendaCargada = new Tienda();
        tiendaCargada->CargarArchivo(&archivoDeEntrada);

        ostringstream streamSalidaTiendaCargada;
        streamSalidaTiendaCargada << tiendaCargada;

        ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        delete tiendaCargada;
        delete tiendaEsperada;

        string esperado = "Tienda: Tienda1\nDirección de internet: www.tienda1.com\nDirección física: Av.39A,C.106B\nTeléfono: 22907465\n\n[1] - Pasta - Existencias: 20\n\n"; 
        string salidaTiendaEsperada = streamSalidaTiendaEsperada.str();

        // Assert - valide los resultados
        EXPECT_EQ(esperado, salidaTiendaEsperada);

        string salidaTiendaCargadaDeArchivo = streamSalidaTiendaEsperada.str();
        EXPECT_EQ(esperado, salidaTiendaCargadaDeArchivo);
    }



}