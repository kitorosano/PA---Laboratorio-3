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
