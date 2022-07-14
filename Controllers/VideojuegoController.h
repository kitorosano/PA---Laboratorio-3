//
// Created by Admin on 20/06/2022.
//
#ifndef LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
#define LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
#include "Interfaces/IVideojuego.h"
#include "DataTypes/DT_InfoVideojuego.h"
#include "Classes/Suscripcion.h"
#include <string>

using namespace std;

class VideojuegoController: public IVideojuego{
private:
    static VideojuegoController* instance;
    VideojuegoController();

    int contadorIdVideojuego = 1;
    int contadorIdSuscripcion = 1;

    Videojuego* videojuegoSeleccionado = NULL;
    ICollection* suscripcionesEnMemoria;

    IDictionary* videojuegos;
    IDictionary* puntuaciones;
    IDictionary* suscripciones;

public:
    static VideojuegoController* getInstance();
    virtual ~VideojuegoController();

    int getNuevoIdVideojuego();
    int getNuevoIdSuscripcion();
    Videojuego* getVideojuegoSeleccionado();
    void setVideojuegoSeleccionado(Videojuego* videojuego);

    IDictionary* getSuscripciones();

    void datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia);
    void confirmarVideojuego();
    void cancelarVideojuego();

    void seleccionarVideoJuego(int id);
    Videojuego* obtenerVideojuegoPorNombre(string nombre_videojuego);

    IDictionary* listarNombreVideojuegos();
    void listarNomDescVideoJuegos();
    void listaJuegosPublicadosFinalizados();

    void asignarPuntaje(string nombreVideojuego, int puntaje);

    void verVideojuego();
    void verVideojuegoDesarrollador();
};
#endif //LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
