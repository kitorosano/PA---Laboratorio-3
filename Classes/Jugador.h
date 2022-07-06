//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_JUGADOR_H
#define PA___LABORATORIO_3_JUGADOR_H
#include "Usuario.h"
#include "Suscripcion.h"
#include <string>
#include <iostream>

using namespace std;

class Jugador: public Usuario {
private:
    string nickname;
    string descripcion;
    IDictionary* jugadores_seguidos;

public:
    Jugador(string email, string password, string nickname, string descripcion);
    virtual ~Jugador();

    string getNickname();
    string getDescripcion();

    void setNickname(string nickname);
    void setDescripcion(string descripcion);
    void registroJugador(string, string);
    string toString();
};


#endif //PA___LABORATORIO_3_JUGADOR_H
