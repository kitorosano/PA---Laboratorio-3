//
// Created by Admin on 20/06/2022.
//
#ifndef LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
#define LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
#include "Interfaces/IVideojuego.h"
#include "Classes/Categoria.h"
#include <string>
using namespace std;

class VideojuegoController: public IVideojuego{
public:
    void datosNuevoVideojuego(string nombre, string descripcion, int costoMensual, int costoTrimestral, int costoAnual, int costoVitalicia);
    void seleccionarCategoriaGenero(Cat_Genero catGenero);
    void seleccionarCategoriaPlataforma(Cat_Plataforma catPlataforma);
    void seleccionarCategoriaOpcionales(Categoria categia);
    void listarNomDescVideoJuegos();
    void actualizarPuntaje();
    void listarVideojuegos();
    void seleccionarVideojuego(int idVideojuego);
    void listaJuegosPublicados();
    void seleccionarVideojuegoAEliminar(string nombre_videojuego);
    void eliminarDatos();
};
#endif //LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
