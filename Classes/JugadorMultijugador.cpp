//
// Created by Davila on 23/6/2022.
//

#include "JugadorMultijugador.h"

using namespace std;

JugadorMultijugador::JugadorMultijugador() {
}

JugadorMultijugador::JugadorMultijugador(Jugador *jugador) {
    this->jugador = jugador;
}

JugadorMultijugador::~JugadorMultijugador() {
}

Jugador *JugadorMultijugador::getJugador() {
    return this->jugador;
}

DT_Fecha *JugadorMultijugador::getFechaFinalizacion() {
    return this->fecha_finalizacion;
}

void JugadorMultijugador::setFechaFinalizacion(DT_Fecha* fecha_finalizacion) {
    this->fecha_finalizacion = fecha_finalizacion;
}

string JugadorMultijugador::toString() {
    if(this->fecha_finalizacion) {
        return this->jugador->toString() + " " + this->fecha_finalizacion->toString();
    }
    else{
        return this->jugador->toString();
    }
}