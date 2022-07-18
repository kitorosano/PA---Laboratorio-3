//
// Created by esteban.rosano on 14/7/2022.
//

#include "DT_VideojuegoSuscripciones.h"
#include "Utils/Utils.h"

DT_VideojuegoSuscripciones::DT_VideojuegoSuscripciones() {

}

DT_VideojuegoSuscripciones::DT_VideojuegoSuscripciones(string nombre, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia) {
    this->nombre = nombre;
    this->costoMensual = costoMensual;
    this->costoTrimestral = costoTrimestral;
    this->costoAnual = costoAnual;
    this->costoVitalicia = costoVitalicia;
}

string DT_VideojuegoSuscripciones::getNombre() {
    return nombre;
}
double DT_VideojuegoSuscripciones::getCostoMensual() {
    return costoMensual;
}
double DT_VideojuegoSuscripciones::getCostoTrimestral() {
    return costoTrimestral;
}
double DT_VideojuegoSuscripciones::getCostoAnual() {
    return costoAnual;
}
double DT_VideojuegoSuscripciones::getCostoVitalicia() {
    return costoVitalicia;
}

void DT_VideojuegoSuscripciones::setNombre(string nombre) {
    this->nombre = nombre;
}
void DT_VideojuegoSuscripciones::setCostoMensual(double costoMensual) {
    this->costoMensual = costoMensual;
}
void DT_VideojuegoSuscripciones::setCostoTrimestral(double costoTrimestral) {
    this->costoTrimestral = costoTrimestral;
}
void DT_VideojuegoSuscripciones::setCostoAnual(double costoAnual) {
    this->costoAnual = costoAnual;
}

string DT_VideojuegoSuscripciones::toString() {
    return nombre + "\n\tCosto Mensual: $" + printDouble(costoMensual) + "\n\tCosto Trimestral: $" + printDouble(costoTrimestral) + "\n\tCosto Anual: $" + printDouble(costoAnual) + "\n\tCosto Vitalicia: $" + printDouble(costoVitalicia);
}