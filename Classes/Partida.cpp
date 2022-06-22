//
// Created by Davila on 21/6/2022.
//

#include "Partida.h"

Partida::Partida(string idPartida, DT_Date fecha, DT_Time horaComienzo, double horasPartida) {
    this->idPartida = idPartida;
    this->fecha = fecha;
    this->horaComienzo = horaComienzo;
    this->horasPartida = horasPartida;
}

void Partida::setIdPartida(string idPartida) {
    this->idPartida = idPartida;
}

void Partida::setFecha(DT_Date fecha) {
    this->fecha = fecha;
}

void Partida::setHoraComienzo(DT_Time horaCominezo) {
    this->horaComienzo = horaCominezo;
}

void Partida::setHorasPartida(double horasPartida) {
    this->horasPartida = horasPartida;
}

string Partida::getIdPartida() {
    return this->idPartida;
}

DT_Date Partida::getFecha() {
    return this->fecha;
}

DT_Time Partida::getHoraComienzo() {
    return this->horaComienzo;
}

double Partida::getHorasPartida() {
    return this->horasPartida;
}

