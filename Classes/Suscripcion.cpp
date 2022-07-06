//
// Created by esteban.rosano on 21/6/2022.
//

#include "Suscripcion.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Suscripcion::Suscripcion() {}

Suscripcion::Suscripcion(Videojuego *videojuego, E_PeriodoValidez periodoValidez, double costo) {
    //    setear id
    this->videojuego = videojuego;
    this->periodoValidez = periodoValidez;
    this->costo = costo;
}

Suscripcion::~Suscripcion(){
}

int Suscripcion::getId(){
    return id;
}

Videojuego* Suscripcion::getVideojuego(){
    return this->videojuego;
}

E_PeriodoValidez Suscripcion::getPeriodoValidez(){
    return this->periodoValidez;
}

double Suscripcion::getCosto(){
    return this->costo;
}

void Suscripcion::setCosto(double costo){
    this->costo = costo;
}

string Suscripcion::toString(){
    stringstream ss;
    ss << "Suscripcion: " << this->getId() << " - " << this->getVideojuego() << " - "<< this->getPeriodoValidez() << " - " << " - " << this->getCosto();
    return ss.str();
}
