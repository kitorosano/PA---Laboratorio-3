//
// Created by Davila on 21/6/2022.
//

#include "Individual.h"

Individual::Individual(string idPartida, DT_Date fecha, DT_Time horaComienzo, double horasPartida,
                       bool contPartAnterior) : Partida(idPartida, fecha, horaComienzo, horasPartida) {
    this->contPartAnterior = contPartAnterior;
}

void Individual::setContPartAnterior(bool contPartAnterior) {
    this->contPartAnterior = contPartAnterior;
}

bool Individual::getContPartAnterior() {
    return this->contPartAnterior;
}
