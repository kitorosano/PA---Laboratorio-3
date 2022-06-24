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
