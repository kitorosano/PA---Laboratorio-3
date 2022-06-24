//
// Created by esteban.rosano on 21/6/2022.
//

#include "Suscripcion.h"

using namespace std;

Suscripcion::Suscripcion(double costo){
    this->costo = 0;
}

Suscripcion::~Suscripcion(){
}

double Suscripcion::getCosto(){
    return this->costo;
}

void Suscripcion::setCosto(double costo){
    this->costo = costo;
}