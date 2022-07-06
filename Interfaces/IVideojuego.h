//
// Created by Admin on 20/06/2022.
//

#ifndef LAB_3_PROYECTO_IVIDEOJUEGO_H
#define LAB_3_PROYECTO_IVIDEOJUEGO_H
#include "../ColeccionesG/ICollectible.h"
#include "../ColeccionesG/ICollection.h"
#include "../ColeccionesG/IDictionary.h"
#include "Classes/Categoria.h"
#include "Classes/Videojuego.h"
#include "DataTypes/DT_NomDescVideojuego.h"
#include "DataTypes/DT_InfoVideojuego.h"
#include <string>
using namespace std;

class IVideojuego{
public:
    virtual IDictionary* listarSuscripciones()=0;
    virtual void datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia) = 0;
    virtual void confirmarVideojuego() = 0;
    virtual void seleccionarVideoJuego(string id) = 0;
    virtual Videojuego* obtenerVideojuegoPorNombre(string nombre_videojuego) = 0;
    virtual void listarNomDescVideoJuegos() = 0;
    virtual void asignarPuntaje(string nombreVideojuego, int puntaje) = 0;
    virtual void listarNombreVideojuegos() = 0;
    virtual DT_InfoVideojuego verVideojuego(string idVideojuego) = 0;
    virtual DT_InfoVideojuego verVideojuegoDesarrollador(string idVideojuego) = 0;
    virtual void listaJuegosPublicadosFinalizados() = 0;
};
#endif //LAB_3_PROYECTO_IVIDEOJUEGO_H
