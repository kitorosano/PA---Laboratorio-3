//
// Created by Davila on 12/7/2022.
//

#include "DT_MultijugadorUnidosNoFinalizados.h"

DT_MultijugadorUnidosNoFinalizados::DT_MultijugadorUnidosNoFinalizados(int idPartida, string fecha, string horaComienzo,
                                                                       string nombreVideoJuego, bool transmitidaEnVivo,
                                                                       string nicknamejugadorIniciador,
                                                                       IDictionary *jugadoresEnLaPartida) {
    this->idPartida = idPartida;
    this->fecha = fecha;
    this->horaComienzo = horaComienzo;
    this->nombreVideoJuego = nombreVideoJuego;
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->nicknamejugadorIniciador = nicknamejugadorIniciador;
    this->jugadoresEnLaPartida = jugadoresEnLaPartida;
}

int DT_MultijugadorUnidosNoFinalizados::getidPartida() {
    return this->idPartida;
}

string DT_MultijugadorUnidosNoFinalizados::getfecha() {
    return this->fecha;
}

string DT_MultijugadorUnidosNoFinalizados::gethoraComienzo() {
    return this->horaComienzo;
}

string DT_MultijugadorUnidosNoFinalizados::getnombreVideoJuego() {
    return this->nombreVideoJuego;
}

bool DT_MultijugadorUnidosNoFinalizados::gettransmitidaEnVivo() {
    return this->transmitidaEnVivo;
}

string DT_MultijugadorUnidosNoFinalizados::getnicknamejugadorIniciador() {
    return this->nicknamejugadorIniciador;
}

IDictionary *DT_MultijugadorUnidosNoFinalizados::getjugadoresEnLaPartida() {
    return this->jugadoresEnLaPartida;
}





