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
#include "DataTypes/DT_InfoVideojuego.h"
#include <string>
using namespace std;

class IVideojuego{
public:
    virtual IDictionary* getVideojuegos()=0;
    virtual IDictionary* getSuscripciones()=0;

    virtual IDictionary* obtenerSuscripcionesVideojuego(string nombre_videojuego)=0;
    virtual Suscripcion* obtenerSuscripcionVideojuego(int id_videojuego, E_PeriodoValidez periodoValidez)=0;

    virtual void datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia, Desarrollador* desarrollador) = 0;
    virtual Videojuego* confirmarVideojuego() = 0;
    virtual void cancelarVideojuego() = 0;

    virtual void seleccionarVideoJuego(string nombre_videojuego) = 0;
    virtual Videojuego* getVideojuegoSeleccionado() = 0;
    virtual void setVideojuegoSeleccionado(Videojuego* videojuego) = 0;
    virtual Videojuego* obtenerVideojuegoPorId(int id_videojuego) = 0;
    virtual Videojuego* obtenerVideojuegoPorNombre(string nombre_videojuego) = 0;

    virtual IDictionary* listarNombreVideojuegos() = 0;
    virtual void listarNomDescVideoJuegos() = 0;
    virtual void listaJuegosPublicadosFinalizados() = 0;

    virtual void asignarPuntaje(string nombreVideojuego, int puntaje) = 0;
    virtual void verVideojuego() = 0;

    virtual void verVideojuegoDesarrollador() = 0;
};
#endif //LAB_3_PROYECTO_IVIDEOJUEGO_H
