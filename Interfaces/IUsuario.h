//
// Created by esteban.rosano on 20/6/2022.
//

#ifndef PA_LABORATORIO_3_IUSUARIO_H
#define PA_LABORATORIO_3_IUSUARIO_H

#include <string>
#include "Classes/Usuario.h"
#include "Classes/Jugador.h"
#include <vector>
using namespace std;

class IUsuario {
public:
    virtual void registroJugador(string mail,string password,string nickname,string descripcion)=0;
    virtual void registroDesarrollador(string mail,string password,string empresa)=0;
    virtual bool verificarNickname(string nickname)=0;
    virtual Usuario* confirmarRegistro()=0;
    virtual void cancelarRegistro()=0;
    virtual int tipoUsuario(Usuario* user)=0;
    virtual int iniciarSesion(string mail,string password)=0;
    virtual Usuario* getUsuarioLogeado()=0;
    virtual void listarJugadores()=0;
    virtual void seguirJugador(string nickname)=0;
    virtual Usuario* buscarUsuario(string email)=0;
};

#endif //PA_LABORATORIO_3_IUSUARIO_H
