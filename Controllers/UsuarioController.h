//
// Created by esteban.rosano on 20/6/2022.
//

#ifndef PA___LABORATORIO_3_USUARIOCONTROLLER_H
#define PA___LABORATORIO_3_USUARIOCONTROLLER_H

#include "Interfaces/IUsuario.h"
#include "Classes/Jugador.h"
#include "Classes/Desarrollador.h"
#include <string>
#include <iostream>
using namespace std;

class UsuarioController: public IUsuario {
private:
    static UsuarioController* instance;
    UsuarioController();

    Usuario* usuarioLogeado;
    Usuario* controller_memory;
    IDictionary* usuarios; //clave correo
public:
    static UsuarioController* getInstance();
    ~UsuarioController();

    Usuario* getUsuarioLogeado();
    Usuario* buscarUsuario(string email);

    void registroJugador(string email,string password,string nickname,string descripcion);
    void registroDesarrollador(string email,string password,string empresa);
    bool verificarNickname(string nickname);
    void confirmarRegistro();
    void cancelarRegistro();

    int iniciarSesion(string mail,string password);
    void listarJugadores();
    void seguirJugador(string nickname);

};


#endif //PA___LABORATORIO_3_USUARIOCONTROLLER_H
