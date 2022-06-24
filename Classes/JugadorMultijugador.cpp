//
// Created by Davila on 23/6/2022.
//

#include "JugadorMultijugador.h"

JugadorMultijugador::JugadorMultijugador(Jugador *jugador) {
    this->jugador = jugador;
}

void JugadorMultijugador::setHoraFinalizacion(DT_Time hora_finalizacion) {
    this->hora_finalizacion = hora_finalizacion;
}
