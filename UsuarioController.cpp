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

void UsuarioController::registroUsuario(string mail, string password){}

void UsuarioController::registroAdicionalDesarrollador(string empresa){}

void UsuarioController::registroAdicionalJugador(string nickname, string descripcion){}

//    void UsuarioController::cancelarRegistro(){}

void UsuarioController::iniciarSesion(string mail, string password){}

//    void UsuarioController::cancelarIniciarSesion(){}

Set<Jugador> UsuarioController::listarJugadores(){}

void UsuarioController::seguirJugador(string nickname){}

void UsuarioController::asignarPuntaje(string videojuego, int puntaje){}

Set<DT_SuscripcionVideojuego> UsuarioController::listarSuscripciones(){}

void UsuarioController::seleccionarVideojuego(string videojuego){}

void UsuarioController::seleccionarSuscripcion(int tipo, int metodo_pago){}

void UsuarioController::confirmarSuscripcion(){}