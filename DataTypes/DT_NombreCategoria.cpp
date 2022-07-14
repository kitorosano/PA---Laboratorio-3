//
// Created by esteban.rosano on 13/7/2022.
//

#include "DT_NombreCategoria.h"

DT_NombreCategoria::DT_NombreCategoria() {
}

DT_NombreCategoria::DT_NombreCategoria(string nombre) {
    this->nombre = nombre;
}

string DT_NombreCategoria::getNombre() {
    return nombre;
}

void DT_NombreCategoria::setNombre(string nombre) {
    this->nombre = nombre;
}

string DT_NombreCategoria::toString() {
    return nombre;
}