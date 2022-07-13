//
// Created by Davila on 23/6/2022.
//

#include "JugadorMultijugador.h"

using namespace std;

JugadorMultijugador::JugadorMultijugador() {
}

JugadorMultijugador::JugadorMultijugador(Jugador *jugador) {
    this->jugador = jugador;
    this->hora_finalizacion = NULL
}

JugadorMultijugador::~JugadorMultijugador() {
}

void JugadorMultijugador::setHoraFinalizacion(DT_Time* hora_finalizacion) {
    this->hora_finalizacion = hora_finalizacion;
}

Jugador *JugadorMultijugador::getJugador() {
    return this->jugador;
}

DT_Time *JugadorMultijugador::getHora_finalizacion() {
    return this->hora_finalizacion;
}
