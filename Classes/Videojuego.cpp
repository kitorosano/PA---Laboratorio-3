//
// Created by Admin on 21/06/2022.
//
#include "Videojuego.h"
#include <string>
#include <iostream>

Videojuego::Videojuego(int idVideojuego,string nombre,string descripcion,double total_horas_jugadas, double puntaje, int cantidad_votos){
    this->idVideojuego=idVideojuego;
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->total_horas_jugadas=total_horas_jugadas;
    this->puntaje=puntaje;
    this->cantidad_votos=cantidad_votos;
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