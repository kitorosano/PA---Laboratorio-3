//
// Created by Admin on 20/06/2022.
//
#include "Categoria.h"
#include <string>

Categoria::Categoria(string nombre,string descripcion){
    this->nombre=nombre;
    this->descripcion=descripcion;
}
Categoria::~Categoria(){
}
string Categoria::getNombre(){
    return this->nombre;
}
string Categoria::getDesc(){
    return this->descripcion;
}
void Categoria::setNombre(string nombre){
    this->nombre=nombre;
}
void Categoria::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

