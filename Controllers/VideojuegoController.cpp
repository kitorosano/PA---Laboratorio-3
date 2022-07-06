//
// Created by Admin on 20/06/2022.
//

#include "Controllers/VideojuegoController.h"
using namespace std;

VideojuegoController* VideojuegoController::instance = NULL;

VideojuegoController::VideojuegoController() {
    videojuegoSeleccionado = NULL;
    videojuegos.clear();
    videojuegosJugador.clear();
}

VideojuegoController::~VideojuegoController(){}

VideojuegoController* VideojuegoController::getInstance() {
    if (instance == NULL) {
        instance = new VideojuegoController();
    }
    return instance;
}

void VideojuegoController::datosNuevoVideojuego(string nombre, string descripcion, int costoMensual, int costoTrimestral, int costoAnual, int costoVitalicia){}
void VideojuegoController::confirmarVideojuego(){}
void VideojuegoController::seleccionarVideoJuego(int id){}
//Videojuego* VideojuegoController::obtenerVideojuegoPorNombre(string nombre_videojuego){}
//vector<DT_NomDescVideojuego> VideojuegoController::listarNomDescVideoJuegos(){}
void VideojuegoController::asignarPuntaje(string nombreVideojuego, int puntaje){}
//vector<string> VideojuegoController::listarNombreVideojuegos(){}
//DT_InfoVideojuegoJugador VideojuegoController::verVideojuego(int idVideojuego){}
//DT_InfoVideojuegoDesarrollador VideojuegoController::verVideojuegoDesarrollador(int idVideojuego){}
//vector<string> VideojuegoController::listaJuegosPublicadosFinalizados(){}