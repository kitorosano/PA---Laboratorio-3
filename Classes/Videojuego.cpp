//
// Created by Admin on 21/06/2022.
//
#include "Videojuego.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Videojuego::Videojuego() {}

Videojuego::Videojuego(string nombre,string descripcion, Desarrollador *desarrollador) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->desarrollador = desarrollador;
    this->puntaje = 0;
    this->total_horas_jugadas = 0;
    this->cantidad_votos = 0;
}
Videojuego::~Videojuego(){
}

int Videojuego::getId(){
    return this->id;
}
string Videojuego::getNombre(){
    return this->nombre;
}
string Videojuego::getDescripcion(){
    return this->descripcion;
}
double Videojuego::getTotalHorasJugadas(){
    return this->total_horas_jugadas;
};
double Videojuego::getPuntaje(){
    return this->puntaje;
}
int Videojuego::getCantidad_votos(){
    return this->cantidad_votos;
}

string Videojuego::getNombreEmpresa() {
    return this->desarrollador->getNombreEmpresa();
}

void Videojuego::setId(int idVideojuego) {
    this->id = idVideojuego;
}
void Videojuego::setNombre(string nombre){
    this->nombre=nombre;
}
void Videojuego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}
void Videojuego::setTotalHorasJugadas(double total_horas_jugadas){
    this->total_horas_jugadas=total_horas_jugadas;
}
void Videojuego::setPuntaje(double puntaje){
    this->puntaje=puntaje;
}
void Videojuego::setCantidad_votos(int cantidad_votos){
    this->cantidad_votos=cantidad_votos;
}
void Videojuego::setDesarrollador(Desarrollador* desarrollador){
    this->desarrollador=desarrollador;
}