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
    IDictionary* puntuaciones;
    IDictionary* suscripciones;

public:
    static VideojuegoController* getInstance();
    virtual ~VideojuegoController();

    Videojuego* getVideojuegoSeleccionado();
    void setVideojuegoSeleccionado(Videojuego* videojuego);

    IDictionary* listarSuscripciones();
    void datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia);
    void confirmarVideojuego();
    void seleccionarVideoJuego(int id);
    Videojuego* obtenerVideojuegoPorNombre(string nombre_videojuego);
    void listarNomDescVideoJuegos();
    void asignarPuntaje(string nombreVideojuego, int puntaje);
    void listarNombreVideojuegos();
    DT_InfoVideojuego verVideojuego(int idVideojuego);
    DT_InfoVideojuego verVideojuegoDesarrollador(int idVideojuego);
    void listaJuegosPublicadosFinalizados();
};
#endif //LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
