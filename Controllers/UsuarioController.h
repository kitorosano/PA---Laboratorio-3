//
// Created by esteban.rosano on 20/6/2022.
//

#ifndef PA___LABORATORIO_3_USUARIOCONTROLLER_H
#define PA___LABORATORIO_3_USUARIOCONTROLLER_H

#include "Interfaces/IUsuario.h"
#include "Classes/Jugador.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class UsuarioController: public IUsuario {
private:
    static UsuarioController* instance;
    UsuarioController();

    Jugador* usuarioLogeado;
    vector<Jugador*> jugadores;
public:
    static UsuarioController* getInstance();
    virtual ~UsuarioController();

    Usuario getUsuarioLogeado();
    vector<Jugador*> listarJugadores();

    void registroJugador(string email,string password,string nickname,string descripcion);
    void registroDesarrollador(string email,string password,string empresa);
    void confirmarRegistro();
    void cancelarRegistro();

    void iniciarSesion(string mail,string password);
    void seguirJugador(string nickname);

};


#endif //PA___LABORATORIO_3_USUARIOCONTROLLER_H
