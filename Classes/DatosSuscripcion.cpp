//
// Created by esteban.rosano on 21/6/2022.
//

#include "DatosSuscripcion.h"
#include <sstream>

using namespace std;

DatosSuscripcion::DatosSuscripcion(string nickname, Suscripcion *suscripcion, E_MetodoPago metodo_pago) {
    this->nickname = nickname;
    this->suscripcion = suscripcion;
    this->metodo_pago = metodo_pago;
    this->fecha_suscripcion = new DT_Date();
    this->hora_suscripcion = new DT_Time();
}

DatosSuscripcion::~DatosSuscripcion() {
}

string DatosSuscripcion::getNickName() {
    return this->nickname;
}

Suscripcion *DatosSuscripcion::getSuscripcion() {
    return suscripcion;
}

E_MetodoPago DatosSuscripcion::getMetodoPago() {
    return metodo_pago;
}

DT_Date* DatosSuscripcion::getFechaSuscripcion() {
    return fecha_suscripcion;
}

DT_Time* DatosSuscripcion::getHoraSuscripcion() {
    return hora_suscripcion;
}

bool DatosSuscripcion::isActivo() {
    bool activo = false;
    switch (this->getSuscripcion()->getPeriodoValidez()) {
        case E_PeriodoValidez::VITALICIA:
            return true;
        case E_PeriodoValidez::MENSUAL: //TODO: Implementar logica para comparar con la fecha actual
            return true;
        case E_PeriodoValidez::TRIMESTRAL: //TODO: Implementar logica para comparar con la fecha actual
            return true;
        case E_PeriodoValidez::ANUAL: //TODO: Implementar logica para comparar con la fecha actual
            return true;
        default:
            break;
    }
    return activo;
}

string DatosSuscripcion::toString() {
    stringstream ss;
    ss << "Nickname: " << this->getNickName() << endl;
    ss << "Suscripcion: " << this->getSuscripcion()->toString() << endl;
    ss << "Metodo de pago: " << Str_MetodoPago[this->getMetodoPago()] << endl;
    ss << "Fecha de suscripcion: " << this->getFechaSuscripcion()->getDate() << endl;
    ss << "Hora de suscripcion: " << this->getHoraSuscripcion()->getTime() << endl;
    ss << "Suscripcion Activa: " << (isActivo() ? "No" : "Si") << endl;
    return ss.str();
}