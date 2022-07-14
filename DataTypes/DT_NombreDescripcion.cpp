//
// Created by esteban.rosano on 13/7/2022.
//

#include "DT_NombreDescripcion.h"

DT_NombreDescripcion::DT_NombreDescripcion() {
}

DT_NombreDescripcion::DT_NombreDescripcion(string nombre) {
    this->nombre = nombre;
}

DT_NombreDescripcion::DT_NombreDescripcion(string nombre, string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

string DT_NombreDescripcion::getNombre() {
    return nombre;
}

void DT_NombreDescripcion::setNombre(string nombre) {
    this->nombre = nombre;
}

string DT_NombreDescripcion::getDescripcion() {
    return descripcion;
}

void DT_NombreDescripcion::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}