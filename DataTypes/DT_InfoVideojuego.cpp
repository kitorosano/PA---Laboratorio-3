//
// Created by esteban.rosano on 23/6/2022.
//

#include "DT_InfoVideojuego.h"
#include "ColeccionesG/ListaDicc.h"

using namespace std;

DT_InfoVideojuego::DT_InfoVideojuego() {
    this->categorias = new ListDicc();
    this->suscripciones = new ListDicc();
}

DT_InfoVideojuego::~DT_InfoVideojuego() {
    delete this->categorias;
    delete this->suscripciones;
}

string DT_InfoVideojuego::getNombre() {
    return nombre;
}

IDictionary* DT_InfoVideojuego::getCategorias() {
    return categorias;
}

IDictionary* DT_InfoVideojuego::getSuscripciones() {
    return suscripciones;
}

string DT_InfoVideojuego::getEmpresa() {
    return empresa;
}

double DT_InfoVideojuego::getPuntaje() {
    return puntaje;
}

double DT_InfoVideojuego::getTotalHorasJugadas() {
    return totalHorasJugadas;
}

void DT_InfoVideojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void DT_InfoVideojuego::setCategorias(IDictionary* categorias) {
    this->categorias = categorias;
}

void DT_InfoVideojuego::setSuscripciones(IDictionary* suscripciones) {
    this->suscripciones = suscripciones;
}

void DT_InfoVideojuego::setEmpresa(string empresa) {
    this->empresa = empresa;
}

void DT_InfoVideojuego::setPuntaje(double puntaje) {
    this->puntaje = puntaje;
}

void DT_InfoVideojuego::setTotalHorasJugadas(double totalHorasJugadas) {
    this->totalHorasJugadas = totalHorasJugadas;
}

string DT_InfoVideojuego::toString() {
    stringstream ss;
    ss << "Nombre: " << nombre << endl;
    ss << "Categorias: " << categorias->toString() << endl;
    ss << "Suscripciones: " << suscripciones->toString() << endl;
    ss << "Empresa: " << empresa << endl;
    ss << "Puntaje: " << puntaje << endl;
    ss << "Total de horas jugadas: " << totalHorasJugadas << endl;
    return ss.str();
}