//
// Created by Admin on 20/06/2022.
//

#ifndef LAB_3_PROYECTO_IVIDEOJUEGO_H
#define LAB_3_PROYECTO_IVIDEOJUEGO_H
#include "Classes/Categoria.h"
#include <string>
using namespace std;

class IVideojuego{
public:
    virtual void datosNuevoVideojuego(string nombre, string descripcion, int costoMensual, int costoTrimestral, int costoAnual, int costoVitalicia) = 0;
    virtual void seleccionarCategoriaGenero(Cat_Genero catGenero) = 0;
    virtual void seleccionarCategoriaOpcionales(Categoria categia) = 0;
    virtual void listarNomDescVideoJuegos() = 0;
    virtual void seleccionarCategoriaPlataforma(Cat_Plataforma catPlataforma) = 0;
    virtual void actualizarPuntaje() = 0;
    virtual void listarVideojuegos() = 0;
    virtual void seleccionarVideojuego(int idVideojuego) = 0;
    virtual void listaJuegosPublicados() = 0;
    virtual void seleccionarVideojuegoAEliminar(string nombre_videojuego) = 0;
    virtual void eliminarDatos() = 0;
};
#endif //LAB_3_PROYECTO_IVIDEOJUEGO_H
