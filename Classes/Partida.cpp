//
// Created by Davila on 21/6/2022.
//

#include "Partida.h"
#include <sstream>
using namespace std;

Partida::Partida() {
}

Partida::Partida(Jugador *jugador, Videojuego *videojuego) {
//    setear id
    this->jugador = jugador;
    this->videojuego = videojuego;
    this->finalizada = false;
}

Partida::~Partida() {
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

Jugador *Partida::getJugador() {
    return this->jugador;
}

Videojuego *Partida::getVideojuego() {
    return this->videojuego;
}

DT_Date Partida::getFechaFin() {
    return this->fechaFin;
}

DT_Time Partida::getHoraFin() {
    return this->horaFin;
}

bool Partida::getFinalizada() {
    return this->finalizada;
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

void Partida::setJugador(Jugador *jugador) {
    this->jugador = jugador;
}

void Partida::setVideojuego(Videojuego *videojuego) {
    this->videojuego = videojuego;
}

string Partida::toString() {
    stringstream ss;
    ss << "Partida: " << this->getIdPartida() << endl;
    ss << "Jugador: " << this->getJugador()->toString() << endl;
    ss << "Videojuego: " << this->getVideojuego()->toString() << endl;
    ss << "Fecha: " << this->getFecha().getDate() << endl;
    ss << "Hora de comienzo: " << this->getHoraComienzo().getTime() << endl;
    ss << "Horas de partida: " << this->getHorasPartida() << endl;
    return ss.str();
}

