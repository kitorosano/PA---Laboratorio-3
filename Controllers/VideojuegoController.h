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
    VideojuegoController();
    static VideojuegoController* instance;

    Videojuego* videojuegoSeleccionado = nullptr;
    vector<Videojuego> videojuegos;
    vector<Videojuego> videojuegosJugador;

public:
    static VideojuegoController* getInstance();

    void datosNuevoVideojuego(string nombre, string descripcion, int costoMensual, int costoTrimestral, int costoAnual, int costoVitalicia);
    void confirmarVideojuego();
    void seleccionarVideoJuego(int id);
    Videojuego* obtenerVideojuegoPorNombre(string nombre_videojuego);
    vector<DT_NomDescVideojuego> listarNomDescVideoJuegos();
    void asignarPuntaje(string nombreVideojuego, int puntaje);
    vector<string> listarNombreVideojuegos();
    DT_InfoVideojuegoJugador verVideojuego(int idVideojuego);
    DT_InfoVideojuegoDesarrollador verVideojuegoDesarrollador(int idVideojuego);
    vector<string> listaJuegosPublicadosFinalizados();
};
#endif //LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
