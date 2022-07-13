//
// Created by esteban.rosano on 12/7/2022.
//

#include "Suscripcion.h"
#include <sstream>

Suscripcion::Suscripcion() {}

Suscripcion::Suscripcion(Videojuego *videojuego, E_PeriodoValidez periodoValidez, double costo){
    this->videojuego = videojuego;
    this->periodoValidez = periodoValidez;
    this->costo = costo;
};

Suscripcion::~Suscripcion() {};

int Suscripcion::getId() {
    return this->id;
}
double Suscripcion::getCosto() {
    return this->costo;
}
E_PeriodoValidez Suscripcion::getPeriodoValidez() {
    return this->periodoValidez;
}
Videojuego* Suscripcion::getVideojuego() {
    return this->videojuego;
}

void Suscripcion::setId(int id) {
    this->id = id;
}
void Suscripcion::setCosto(double costo) {
    this->costo = costo;
}

string Suscripcion::toString() {
    stringstream ss;
    ss << "Suscripcion: " << this->getId() << " - " << this->getVideojuego()->toString() << " - "<< Str_PeriodoValidez[this->getPeriodoValidez()] << " - " << " - " << this->getCosto();
    return ss.str();
}