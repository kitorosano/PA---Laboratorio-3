//
// Created by Davila on 21/6/2022.
//

#include "Multijugador.h"

using namespace std;

Multijugador::Multijugador() {
}

Multijugador::Multijugador(Jugador *jugador, Videojuego *videojuego, bool transmitidaEnvivo): Partida(jugador, videojuego) {
    this->transmitidaEnVivo = transmitidaEnVivo;
}

Multijugador::~Multijugador() {
}

bool Multijugador::isTransmitidaEnVivo() {
    return this->transmitidaEnVivo;
}

double Multijugador::getDuracionTotal() {
    return this->duracionTotal;
}

void Multijugador::setIsTransmitidaEnVivo(bool transmitidaEnVivo) {
    this->transmitidaEnVivo = transmitidaEnVivo;
}

void Multijugador::setDuracionTotal(double duracionTotal) {
    this->duracionTotal = duracionTotal;
}

void Multijugador::unirNicknameAPartida(Jugador *jugador) {
    this->jugadoresEnLaPartida->add(jugador, new KeyString(jugador->getNickname()))
}
