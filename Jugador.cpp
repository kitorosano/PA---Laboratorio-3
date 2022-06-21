//
// Created by esteban.rosano on 21/6/2022.
//

#include "Jugador.h"

using namespace std;

Jugador::Jugador(string email, string password, string nickname, string descripcion) : Usuario(email, password) {
    this->nickname = nickname;
    this->descripcion = descripcion;
}

Jugador::~Jugador() {
}

string Jugador::getNickname() {
    return nickname;
}

string Jugador::getDescripcion() {
    return descripcion;
}

void Jugador::setNickname(string nickname) {
    this->nickname = nickname;
}

void Jugador::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}