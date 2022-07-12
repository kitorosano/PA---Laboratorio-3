//
// Created by Davila on 12/7/2022.
//

#include "DT_PartidasIndividualesFinalizadas.h"

DT_PartidasIndividualesFinalizadas::DT_PartidasIndividualesFinalizadas(string idPartida, string fecha,
                                                                       string horaComienzo, double horasPartida) {
    this->idPartida = idPartida;
    this->fecha = fecha;
    this->horaComienzo = horaComienzo;
    this->horasPartida = horasPartida;
}

string DT_PartidasIndividualesFinalizadas::getIdPartida() {
    return this->idPartida;
}

string DT_PartidasIndividualesFinalizadas::getFecha() {
    return this->fecha;
}

string DT_PartidasIndividualesFinalizadas::getHoraComienzo() {
    return this->horaComienzo;
}

double DT_PartidasIndividualesFinalizadas::getHorasPartida() {
    return this->horasPartida;
}
