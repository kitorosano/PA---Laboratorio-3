//
// Created by esteban.rosano on 20/6/2022.
//

#ifndef PA___LABORATORIO_3_USUARIOCONTROLLER_H
#define PA___LABORATORIO_3_USUARIOCONTROLLER_H

#include "Interfaces/IUsuario.h"
#include "Classes/Jugador.h"
#include <vector>
#include <iostream>
using namespace std;

class UsuarioController: public IUsuario {
private:
    static UsuarioController* instance;
    vector<Jugador*> jugadores;
public:
    UsuarioController();
    virtual ~UsuarioController();
    UsuarioController* getInstance();
     void registroJugador(string mail,string password,string nickname,string descripcion);
     void registroDesarrollador(string mail,string password,string empresa);
     void confirmarRegistro();
     void cancelarRegistro();
     void iniciarSesion(string mail,string password);
     Usuario getUsuarioLogeado();
     void seguirJugador(string nickname);
     vector<Jugador*> listarJugadores();



};


#endif //PA___LABORATORIO_3_USUARIOCONTROLLER_H
