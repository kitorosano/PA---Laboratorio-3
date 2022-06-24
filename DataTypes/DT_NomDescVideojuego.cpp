//
// Created by esteban.rosano on 23/6/2022.
//

#include "DT_NomDescVideojuego.h"

using namespace std;

DT_NomDescVideojuego::DT_NomDescVideojuego(string nombre, string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

string DT_NomDescVideojuego::getNombre() {
    return nombre;
}

string DT_NomDescVideojuego::getDescripcion() {
    return descripcion;
}