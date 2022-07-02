//
// Created by Admin on 20/06/2022.
//
#include "Categoria.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Categoria::Categoria() {
}

Categoria::Categoria(string nombre,string descripcion){
//    setear id
    this->nombre=nombre;
    this->descripcion=descripcion;
}
Categoria::~Categoria(){
}
string Categoria::getNombre(){
    return this->nombre;
}
string Categoria::getDescription(){
    return this->descripcion;
}
E_TipoCategoria Categoria::getTipo(){
    return this->tipo;
}
void Categoria::setNombre(string nombre){
    this->nombre=nombre;
}
void Categoria::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}
void Categoria::setTipo(E_TipoCategoria tipo){
    this->tipo=tipo;
}

string Categoria::toString(){
    stringstream ss;
    ss<<"Nombre: "<<this->getNombre()<<endl;
    ss<<"Descripcion: "<<this->getDescription()<<endl;
    ss << "Tipo: " << Str_TipoCategoria[this->tipo] << endl;
    return ss.str();
}r