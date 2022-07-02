//
// Created by esteban.rosano on 1/7/2022.
//

#include "VideojuegoJugador.h"

using namespace std;

VideojuegoJugador::VideojuegoJugador(Jugador* jugador, Videojuego* videojuego, int puntaje) {
    this->jugador = jugador;
    this->videojuego = videojuego;
    this->puntaje = puntaje;
}

VideojuegoJugador::~VideojuegoJugador() {
}

int VideojuegoJugador::getPuntaje() {
    return puntaje;
}

void VideojuegoJugador::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}
