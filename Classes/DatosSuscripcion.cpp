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
    this->fecha_suscripcion = new DT_Fecha();
}

DatosSuscripcion::DatosSuscripcion(string nickname, Suscripcion *suscripcion, DT_Fecha *fecha_suscripcion, E_MetodoPago metodo_pago) {
    this->nickname = nickname;
    this->suscripcion = suscripcion;
    this->metodo_pago = metodo_pago;
    this->fecha_suscripcion = fecha_suscripcion;
}

DatosSuscripcion::~DatosSuscripcion() {
}

string DatosSuscripcion::getNickName() {
    return this->nickname;
}
int DatosSuscripcion::getId(){
    return this->id;
}
Suscripcion *DatosSuscripcion::getSuscripcion() {
    return suscripcion;
}

E_MetodoPago DatosSuscripcion::getMetodoPago() {
    return metodo_pago;
}

DT_Fecha* DatosSuscripcion::getFechaSuscripcion() {
    return fecha_suscripcion;
}



bool DatosSuscripcion::isActivo() {
    bool activo = false;
    switch (this->getSuscripcion()->getPeriodoValidez()) {
        case E_PeriodoValidez::VITALICIA:
            return true;
        case E_PeriodoValidez::MENSUAL: //TODO: Implementar logica para comparar con la fechaComienzo actual
            return true;
        case E_PeriodoValidez::TRIMESTRAL: //TODO: Implementar logica para comparar con la fechaComienzo actual
            return true;
        case E_PeriodoValidez::ANUAL: //TODO: Implementar logica para comparar con la fechaComienzo actual
            return true;
        default:
            break;
    }
    return activo;
}

void DatosSuscripcion::setId(int id){
    this->id=id;
}
void DatosSuscripcion::setFechaSuscripcion(DT_Fecha* fechaSuscripcion){
    this->fecha_suscripcion=fechaSuscripcion;
}

string DatosSuscripcion::toString() {
    stringstream ss;
    ss << "Nickname: " << this->getNickName() << endl;
    ss << "Suscripcion: " << this->getSuscripcion()->toString() << endl;
    ss << "Metodo de pago: " << Str_MetodoPago[this->getMetodoPago()] << endl;
    ss << "Fecha de suscripcion: " << this->getFechaSuscripcion()->toString() << endl;
    ss << "Suscripcion Activa: " << (isActivo() ? "No" : "Si") << endl;
    return ss.str();
}