//
// Created by esteban.rosano on 24/6/2022.
//

#include "DT_MultijugadorVideojuego.h"

using namespace std;

DT_MultijugadorVideojuego::DT_MultijugadorVideojuego(int idPartida,string nombreVideojuego, Jugador* jugadorIniciador, IDictionary* jugadoresUnidos, Multijugador* multijugador) {
    this->idPartida=idPartida;
    this->nombreVideojuego = nombreVideojuego;
    this->jugadorIniciador = jugadorIniciador;
    this->jugadoresUnidos = jugadoresUnidos;
    this->multijugador = multijugador;
}
int DT_MultijugadorVideojuego::getIdPartida(){
    return this->idPartida;
}

string DT_MultijugadorVideojuego::getNombreVideojuego() {
    return this->nombreVideojuego;
}

Jugador* DT_MultijugadorVideojuego::getJugadorIniciador() {
    return this->jugadorIniciador;
}

IDictionary* DT_MultijugadorVideojuego::getJugadoresUnidos() {
    return this->jugadoresUnidos;
}

Multijugador* DT_MultijugadorVideojuego::getMultijugador() {
    return this->multijugador;
}