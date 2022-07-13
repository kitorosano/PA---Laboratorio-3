//
// Created by Admin on 20/06/2022.
//
#include "Categoria.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/KeyInt.h"
#include "ColeccionesG/IIterator.h"
#include <sstream>

using namespace std;

Categoria::Categoria() {
}

Categoria::Categoria(string nombre,string descripcion, E_TipoCategoria tipo){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->videojuegos = new ListDicc();
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
IDictionary* Categoria::getVideojuegos(){
    return this->videojuegos;
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
void Categoria::agregarVideojuego(Videojuego* videojuego){
    this->videojuegos->add(videojuego, new KeyInt(videojuego->getId()));
}

string Categoria::toString(){
    stringstream ss;
    ss<<"Nombre: "<<this->getNombre()<<endl;
    ss<<"Descripcion: "<<this->getDescription()<<endl;
    ss << "Tipo: " << Str_TipoCategoria[this->tipo] << endl;
    return ss.str();
}r