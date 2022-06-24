//
// Created by esteban.rosano on 23/6/2022.
//

#include "DT_InfoVideojuegoJugador.h"

using namespace std;

DT_InfoVideojuegoJugador::DT_InfoVideojuegoJugador(string nombre, vector<string> categorias, vector<Suscripcion *> suscripciones, string empresa, double puntaje) {
    this->nombre = nombre;
    this->categorias = categorias;
    this->suscripciones = suscripciones;
    this->empresa = empresa;
    this->puntaje = puntaje;
}

string DT_InfoVideojuegoJugador::getNombre() {
    return nombre;
}

vector<string> DT_InfoVideojuegoJugador::getCategorias() {
    return categorias;
}

vector<Suscripcion *> DT_InfoVideojuegoJugador::getSuscripciones() {
    return suscripciones;
}

string DT_InfoVideojuegoJugador::getEmpresa() {
    return empresa;
}

double DT_InfoVideojuegoJugador::getPuntaje() {
    return puntaje;
}