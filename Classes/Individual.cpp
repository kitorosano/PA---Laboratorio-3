//
// Created by Davila on 21/6/2022.
//

#include "Individual.h"

Individual::Individual() {
}

Individual::Individual(Jugador *jugador, Videojuego *videojuego, Individual *partidaAContinuar) : Partida(jugador, videojuego) {
    this->partidaAContinuar = partidaAContinuar;
}

Individual::~Individual() {
}

Individual *Individual::getContPartAnterior() {
    return this->partidaAContinuar;
}

void Individual::setContPartAnterior(Individual* partidaAContinuar) {
    this->partidaAContinuar = partidaAContinuar;
}

string Individual::toString() {
    stringstream ss;
    ss << "Partida: " << Partida::toString() << " - " << "Partida a Continuar: " << this->getContPartAnterior()->toString();
    return ss.str();
}



