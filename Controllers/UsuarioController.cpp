//
// Created by esteban.rosano on 20/6/2022.
//
#include "UsuarioController.h"
using namespace std;

UsuarioController::UsuarioController() {

    usuarioSeleccionado = NULL;
    videojuegoSeleccionado = NULL;
    suscripcionSeleccionada = NULL;
}

UsuarioController::~UsuarioController() {
}

UsuarioController* UsuarioController::getInstance() {
    if (instance == NULL)
        instance = new UsuarioController;
    return instance;
}

void UsuarioController::registroJugador(string mail,string password,string nickname,string descripcion){}

void UsuarioController::registroDesarrollador(string mail,string password,string empresa){}

void UsuarioController::confirmarRegistro(){}

void UsuarioController::cancelarRegistro(){}

void UsuarioController::iniciarSesion(string mail,string password){}

Usuario UsuarioController::getUsuarioLogeado(){}

void UsuarioController::seguirJugador(string nickname){}

vector<Jugador*> UsuarioController::listarJugadores(){}