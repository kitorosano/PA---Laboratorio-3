//
// Created by Admin on 20/06/2022.
//
#ifndef LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
#define LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
#include "Interfaces/IVideojuego.h"
#include <string>

using namespace std;

class VideojuegoController: public IVideojuego{
private:
    static VideojuegoController* instance;
    VideojuegoController();

    Videojuego* videojuegoSeleccionado = NULL;
    IDictionary* videojuegos;
    IDictionary* suscripciones;

public:
    static VideojuegoController* getInstance();
    virtual ~VideojuegoController();

    IDictionary* listarSuscripciones();
    void datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia);
    void confirmarVideojuego();
    void seleccionarVideoJuego(string id);
    Videojuego* obtenerVideojuegoPorNombre(string nombre_videojuego);
    IDictionary* listarNomDescVideoJuegos();
    void asignarPuntaje(string nombreVideojuego, int puntaje);
    IDictionary* listarNombreVideojuegos();
    DT_InfoVideojuegoJugador verVideojuego(string idVideojuego);
    DT_InfoVideojuegoDesarrollador verVideojuegoDesarrollador(string idVideojuego);
    IDictionary* listaJuegosPublicadosFinalizados();
};
#endif //LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
