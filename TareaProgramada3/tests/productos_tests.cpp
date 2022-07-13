#include <gtest/gtest.h>
#include "/home/alessandro/TareaProgramada3/src/producto.h"
#include <string>

using namespace std;

namespace
{
    TEST(Producto_Tests, Tests_Crear_Producto)
    {
        /// AAA
        // Arrange - configurar el escenario
        Producto *producto = new Producto (1, "leche", 40);

        // Act - ejecute la operación
        int idActual = producto->ObtenerId();
        string nombreActual = producto->ObtenerNombreP();
        int existenciasActual = producto->ObtenerExistencias();

        int idEsperada = 1;
        string nombreEsperado = "leche";
        int existenciasEsperado = 40;

        // Assert - valide los resultados
        EXPECT_EQ(nombreActual, nombreEsperado);
        EXPECT_EQ(idActual, idEsperada);
        EXPECT_EQ(existenciasActual, existenciasEsperado);
        
    }


}