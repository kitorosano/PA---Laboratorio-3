//
// Created by esteban.rosano on 20/6/2022.
//
#include "UsuarioController.h"
using namespace std;

UsuarioController* UsuarioController::instance = NULL;

UsuarioController::UsuarioController() {
    this->usuarioLogeado = NULL;
    this->jugadores = vector<Jugador*>();
}

UsuarioController::~UsuarioController(){}

UsuarioController* UsuarioController::getInstance() {
    if (instance == NULL)
        instance = new UsuarioController;
    return instance;
}

Usuario UsuarioController::getUsuarioLogeado(){}
vector<Jugador*> UsuarioController::listarJugadores(){}

void UsuarioController::registroJugador(string email,string password,string nickname,string descripcion){}
void UsuarioController::registroDesarrollador(string email,string password,string empresa){}
void UsuarioController::confirmarRegistro(){}
void UsuarioController::cancelarRegistro(){}

void UsuarioController::iniciarSesion(string mail,string password){}
void UsuarioController::seguirJugador(string nickname){}