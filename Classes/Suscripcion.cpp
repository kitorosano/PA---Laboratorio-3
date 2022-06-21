//
// Created by esteban.rosano on 21/6/2022.
//

#include "Suscripcion.h"

using namespace std;

Suscripcion::Suscripcion(){
    this->costo = 0;
    this->activo = false;
    this->datos_suscripcion = nullptr;
}

Suscripcion::~Suscripcion(){
    delete this->datos_suscripcion;
}

double Suscripcion::getCosto(){
    return this->costo;
}

bool Suscripcion::getActivo(){
    return this->activo;
}

void Suscripcion::setCosto(double costo){
    this->costo = costo;
}

void Suscripcion::setActivo(bool activo){
    this->activo = activo;
}