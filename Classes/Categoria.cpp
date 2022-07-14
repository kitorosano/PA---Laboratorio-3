//
// Created by Admin on 20/06/2022.
//
#include "Categoria.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/KeyInt.h"
#include "ColeccionesG/IIterator.h"

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
bool Categoria::tieneVideojuego(string nombreVideojuego){
    IIterator* iter = this->videojuegos->getIteratorObj();
    while(iter->hasNext()){
        Videojuego* videojuego = dynamic_cast<Videojuego*>(iter->next());
        if(videojuego->getNombre() == nombreVideojuego){
            return true;
        }
    }
    delete iter;
    return false;
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
  IIterator* it = this->videojuegos->getIteratorObj();
  while(it->hasNext()){
    Videojuego* aux = dynamic_cast<Videojuego * >(it->next());
    if(aux->getNombre() == videojuego->getNombre()){
      cout << "No se agrego la categoria porque ya existe en el videojuego";
    }
  }

    this->videojuegos->add(videojuego, new KeyInt(videojuego->getId()));
}

string Categoria::toString(){
    return "|Nombre: " + this->getNombre() + "|Descripcion: " + this->getDescription() + "|Tipo: " + Str_TipoCategoria[this->tipo];
};