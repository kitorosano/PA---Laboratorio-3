//
// Created by esteban.rosano on 23/6/2022.
//

#include "DT_InfoVideojuegoDesarrollador.h"

using namespace std;

DT_InfoVideojuegoDesarrollador::DT_InfoVideojuegoDesarrollador(string nombre, vector<string> categorias, vector<Suscripcion *> suscripciones, string empresa, double totalHorasJugadas) {
    this->nombre = nombre;
    this->categorias = categorias;
    this->suscripciones = suscripciones;
    this->empresa = empresa;
    this->totalHorasJugadas = totalHorasJugadas;
}

string DT_InfoVideojuegoDesarrollador::getNombre() {
    return nombre;
}

vector<string> DT_InfoVideojuegoDesarrollador::getCategorias() {
    return categorias;
}

vector<Suscripcion *> DT_InfoVideojuegoDesarrollador::getSuscripciones() {
    return suscripciones;
}

string DT_InfoVideojuegoDesarrollador::getEmpresa() {
    return empresa;
}

double DT_InfoVideojuegoDesarrollador::getTotalHorasJugadas() {
    return totalHorasJugadas;
}