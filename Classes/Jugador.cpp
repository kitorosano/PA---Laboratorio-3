//
// Created by esteban.rosano on 21/6/2022.
//

#include "Jugador.h"
#include "ColeccionesG/KeyString.h"
#include "ColeccionesG/ListaDicc.h"
#include <sstream>

using namespace std;

Jugador::Jugador(string email, string password, string nickname, string descripcion) : Usuario(email, password) {
    this->nickname = nickname;
    this->descripcion = descripcion;
    this->jugadores_seguidos= new ListDicc();
}

Jugador::~Jugador() {
}

string Jugador::getNickname() {
    return nickname;
}

string Jugador::getDescripcion() {
    return descripcion;
}
IDictionary* Jugador::getjugadores_seguidos(){
    return this->jugadores_seguidos;
}
void Jugador::setNickname(string nickname) {
    this->nickname = nickname;
}

void Jugador::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Jugador::registroJugador(string, string){}

string Jugador::toString(){
    stringstream ss;
    ss << "Jugador: " << endl;
    ss << "Nickname: " << this->getNickname() << endl;
    ss << "Descripcion: " << this->getDescripcion() << endl;
    return ss.str();
}