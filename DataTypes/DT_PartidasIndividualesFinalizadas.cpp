//
// Created by Davila on 12/7/2022.
//

#include "DT_PartidasIndividualesFinalizadas.h"
#include <sstream>

DT_PartidasIndividualesFinalizadas::DT_PartidasIndividualesFinalizadas(int idPartida, DT_Fecha* fecha, int horasPartida) {
    this->idPartida = idPartida;
    this->fechaComienzo = fecha;
    this->horasPartida = horasPartida;
}

int DT_PartidasIndividualesFinalizadas::getIdPartida() {
    return this->idPartida;
}

DT_Fecha* DT_PartidasIndividualesFinalizadas::getFechaComienzo() {
    return this->fechaComienzo;
}

int DT_PartidasIndividualesFinalizadas::getHorasPartida() {
    return this->horasPartida;
}

string DT_PartidasIndividualesFinalizadas::toString() {
    stringstream ss;
    ss << "Id Partida: " << this->idPartida << endl;
    ss << "Fecha de comienzo: " << this->fechaComienzo->toString() << endl;
    ss << "Horas de partida: " << this->horasPartida << endl;
    return ss.str();
}