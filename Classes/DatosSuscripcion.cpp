//
// Created by esteban.rosano on 21/6/2022.
//

#include "DatosSuscripcion.h"
#include <sstream>

using namespace std;

DatosSuscripcion::DatosSuscripcion(Jugador *jugador, Suscripcion *suscripcion, E_MetodoPago metodo_pago,
                                   DT_Date fecha_suscripcion, DT_Time hora_suscripcion) {
    this->jugador = jugador;
    this->suscripcion = suscripcion;
    this->metodo_pago = metodo_pago;
    this->fecha_suscripcion = fecha_suscripcion;
    this->hora_suscripcion = hora_suscripcion;
    this->activo = true;
}

DatosSuscripcion::~DatosSuscripcion() {
}

Jugador *DatosSuscripcion::getJugador() {
    return jugador;
}

Suscripcion *DatosSuscripcion::getSuscripcion() {
    return suscripcion;
}

E_MetodoPago DatosSuscripcion::getMetodoPago() {
    return metodo_pago;
}

DT_Date DatosSuscripcion::getFechaSuscripcion() {
    return fecha_suscripcion;
}

DT_Time DatosSuscripcion::getHoraSuscripcion() {
    return hora_suscripcion;
}

bool DatosSuscripcion::isActivo() {
    return activo;
}

void DatosSuscripcion::setJugador(Jugador *jugador) {
    this->jugador = jugador;
}

void DatosSuscripcion::setSuscripcion(Suscripcion *suscripcion) {
    this->suscripcion = suscripcion;
}

void DatosSuscripcion::setMetodoPago(E_MetodoPago metodo_pago) {
    this->metodo_pago = metodo_pago;
}

void DatosSuscripcion::setFechaSuscripcion(DT_Date fecha_suscripcion) {
    this->fecha_suscripcion = fecha_suscripcion;
}

void DatosSuscripcion::setHoraSuscripcion(DT_Time hora_suscripcion) {
    this->hora_suscripcion = hora_suscripcion;
}

void DatosSuscripcion::setActivo(bool activo) {
    this->activo = activo;
}

string DatosSuscripcion::toString() {
    stringstream ss;
    ss << "Jugador: " << this->getJugador()->toString() << endl;
    ss << "Suscripcion: " << this->getSuscripcion()->toString() << endl;
    ss << "Metodo de pago: " << Str_MetodoPago[this->getMetodoPago()] << endl;
    ss << "Fecha de suscripcion: " << this->getFechaSuscripcion().getDate() << endl;
    ss << "Hora de suscripcion: " << this->getHoraSuscripcion().getTime() << endl;
    ss << "Activo: " << activo << endl;
    return ss.str();
}