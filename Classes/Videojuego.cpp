//
// Created by Admin on 21/06/2022.
//
#include "Videojuego.h"
#include <string>
#include <iostream>

Videojuego::Videojuego(string nombre,string descripcion, vector<Suscripcion> suscripciones) {
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->suscripciones=suscripciones;
}
Videojuego::~Videojuego(){
}

int Videojuego::getIdVideojuego(){
    return this->idVideojuego;
}
string Videojuego::getNombre(){
    return this->nombre;
}
string Videojuego::getDescripcion(){
    return this->descripcion;
}
double Videojuego::getTotal_horas_jugadas(){
    return this->total_horas_jugadas;
};
double Videojuego::getPuntaje(){
    return this->puntaje;
}
int Videojuego::getCantidad_votos(){
    return this->cantidad_votos;
}

void Videojuego::setIdVideojuego(int idVideojuego){
    this->idVideojuego=idVideojuego;
}
void Videojuego::setNombre(string nombre){
    this->nombre=nombre;
}
void Videojuego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}
void Videojuego::setTotal_horas_jugadas(double total_horas_jugadas){
    this->total_horas_jugadas=total_horas_jugadas;
}
void Videojuego::setPuntaje(double puntaje){
    this->puntaje=puntaje;
}
void Videojuego::setCantidad_votos(int cantidad_votos){
    this->cantidad_votos=cantidad_votos;
}

void Videojuego::agregarCategoria(Categoria * categorias){
    this->categorias.push_back(categorias);
}

void Videojuego::agregarSuscripcion(Suscripcion suscripcion){
    this->suscripciones.push_back(suscripcion);
}

void Videojuego::eliminarSuscripcion(Suscripcion suscripcion){
    for(int i=0;i<this->suscripciones.size();i++){
        if(this->suscripciones[i].getId()==suscripcion.getId()){
            this->suscripciones.erase(this->suscripciones.begin()+i);
        }
    }