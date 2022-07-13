//
// Created by esteban.rosano on 23/6/2022.
//

#include "DT_InfoVideojuego.h"
#include "ColeccionesG/ListaDicc.h"
#include <sstream>

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

string DT_InfoVideojuego::categoriasToString(){
    stringstream ss;
    ss << "Categorias: ";
    IIterator* it = this->categorias->getIteratorObj();
    while(it->hasNext()){
        Categoria* categoria = dynamic_cast<Categoria*>(it->next());
        ss << categoria->getNombre() << " ";
    }
    delete it;
    return ss.str();
}

string DT_InfoVideojuego::suscripcionesToString(){
    stringstream ss;
    ss << "Suscripciones: ";
    IIterator* it = this->suscripciones->getIteratorObj();
    while(it->hasNext()){
        Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(it->next());
        ss << Str_PeriodoValidez[suscripcion->getPeriodoValidez()] << " - " << suscripcion->getCosto() << endl;
    }
    delete it;
    return ss.str();
}

string DT_InfoVideojuego::toString() {
    stringstream ss;
    ss << "Nombre: " << nombre << endl;
    ss << "Categorias: " << this->categoriasToString() << endl;
    ss << "Suscripciones: " << this->suscripcionesToString() << endl;
    ss << "Empresa: " << empresa << endl;
    ss << "Puntaje: " << puntaje << endl;
    ss << "Total de horas jugadas: " << totalHorasJugadas << endl;
    return ss.str();
}