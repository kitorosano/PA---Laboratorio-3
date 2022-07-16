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

int Partida::getIdPartida() {
    return this->idPartida;
}

DT_Fecha* Partida::getFechaComienzo() {
    return this->fechaComienzo;
}

int Partida::getHorasPartida() {
    return this->horasPartida;
}

Jugador *Partida::getJugador() {
    return this->jugador;
}

Videojuego *Partida::getVideojuego() {
    return this->videojuego;
}

DT_Fecha* Partida::getFechaFin() {
    return this->fechaFin;
}

bool Partida::isFinalizada() {
    return this->finalizada;
}

void Partida::setIdPartida(int idpartida) {
    this->idPartida = idpartida;
}

void Partida::setJugador(Jugador *jugador) {
    this->jugador = jugador;
}

void Partida::setVideojuego(Videojuego *videojuego) {
    this->videojuego = videojuego;
}

void Partida::setFechaComienzo(DT_Fecha* fecha) {
    this->fechaComienzo = fecha;
}

void Partida::finalizarPartida(DT_Fecha* fecha) {
    this->fechaFin = fechaFin;
    this->horasPartida = getFechaComienzo()->getDiferenciaEnHoras(fecha);
    this->finalizada = true;
}

string Partida::toString() {
    stringstream ss;
    ss << "Partida: " << this->getIdPartida() << endl;
    ss << "Jugador: " << this->getJugador()->toString() << endl;
    ss << "Videojuego: " << this->getVideojuego()->toString() << endl;
    ss << "Fecha de Comienzo: " << this->getFechaComienzo()->toString()<< endl;
    ss << "Finalizada: " << this->isFinalizada() << endl;
    this->isFinalizada() ? ss << "Horas de partida: " << this->getHorasPartida() << endl : ss << "";
    this->isFinalizada() ? ss << "Fecha de Fin: " << this->getFechaFin()->toString() << endl : ss << "";
    return ss.str();
}