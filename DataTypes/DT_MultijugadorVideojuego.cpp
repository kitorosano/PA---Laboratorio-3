//
// Created by esteban.rosano on 24/6/2022.
//

#include "DT_MultijugadorVideojuego.h"

using namespace std;

DT_MultijugadorVideojuego::DT_MultijugadorVideojuego(string nombreVideojuego, Jugador* jugadorIniciador, vector<Jugador*> jugadoresUnidos, Multijugador* multijugador) {
    this->nombreVideojuego = nombreVideojuego;
    this->jugadorIniciador = jugadorIniciador;
    this->jugadoresUnidos = jugadoresUnidos;
    this->multijugador = multijugador;
}

string DT_MultijugadorVideojuego::getNombreVideojuego() {
    return nombreVideojuego;
}

Jugador* DT_MultijugadorVideojuego::getJugadorIniciador() {
    return jugadorIniciador;
}

vector<Jugador*> DT_MultijugadorVideojuego::getJugadoresUnidos() {
    return jugadoresUnidos;
}

Multijugador* DT_MultijugadorVideojuego::getMultijugador() {
    return multijugador;
}