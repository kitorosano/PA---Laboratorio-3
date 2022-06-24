//
// Created by Admin on 20/06/2022.
//

#ifndef LAB_3_PROYECTO_IVIDEOJUEGO_H
#define LAB_3_PROYECTO_IVIDEOJUEGO_H
#include "Classes/Categoria.h"
#include "Classes/Videojuego.h"
#include "DataTypes/DT_NomDescVideojuego.h"
#include "DataTypes/DT_InfoVideojuegoJugador.h"
#include "DataTypes/DT_InfoVideojuegoDesarrollador.h"
#include <string>
#include <vector>
using namespace std;

class IVideojuego{
public:
    virtual void datosNuevoVideojuego(string nombre, string descripcion, int costoMensual, int costoTrimestral, int costoAnual, int costoVitalicia) = 0;
    virtual void confirmarVideojuego() = 0;
    virtual void seleccionarVideoJuego(int id) = 0;
    virtual Videojuego* obtenerVideojuegoPorNombre(string nombre_videojuego) = 0;
    virtual vector<DT_NomDescVideojuego> listarNomDescVideoJuegos() = 0;
    virtual void asignarPuntaje(string nombreVideojuego, int puntaje) = 0;
    virtual vector<string> listarNombreVideojuegos() = 0;
    virtual DT_InfoVideojuegoJugador verVideojuego(int idVideojuego) = 0;
    virtual DT_InfoVideojuegoDesarrollador verVideojuegoDesarrollador(int idVideojuego) = 0;
    virtual vector<string> listaJuegosPublicadosFinalizados() = 0;
};
#endif //LAB_3_PROYECTO_IVIDEOJUEGO_H
