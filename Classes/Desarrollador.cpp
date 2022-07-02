//
// Created by esteban.rosano on 1/7/2022.
//

#include "Desarrollador.h"

using namespace std;

Desarrollador::Desarrollador(string email, string password, string nombreEmpresa) : Usuario(email, password) {
//    setear id
    this->nombreEmpresa = nombreEmpresa;
}

Desarrollador::~Desarrollador() {
}

int Desarrollador::getIdDesarrollador() {
    return this->idDesarrollador;
}

void Desarrollador::setNombreEmpresa(string nombreEmpresa) {
    this->nombreEmpresa = nombreEmpresa;
}

string Desarrollador::getNombreEmpresa() {
    return this->nombreEmpresa;
}

string Desarrollador::toString() {
    return "Desarrollador: " + Usuario::toString() + " idDesarrollador: " + to_string(idDesarrollador) + " nombreEmpresa: " + nombreEmpresa;
}
