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

void JugadorMultijugador::setHoraFinalizacion(DT_Time hora_finalizacion) {
    this->hora_finalizacion = hora_finalizacion;
}
