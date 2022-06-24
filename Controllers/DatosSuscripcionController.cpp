//
// Created by Admin on 23/06/2022.
//
#include "DatosSuscripcionController.h"
DatosSuscripcionController::DatosSuscripcionController(){}
DatosSuscripcionController* DatosSuscripcionController::getInstance(){}
 DatosSuscripcionController::~DatosSuscripcionController(){}

void DatosSuscripcionController::listarSuscripciones(){}
void DatosSuscripcionController::listarNombreVideojuegosSuscritos(){}
void DatosSuscripcionController::obtenerSuscripcionesVideojuego(string nombre_videojuego){}
void DatosSuscripcionController::cancelarSuscripcionActiva(int idSuscripcion){}
void DatosSuscripcionController::crearDatosSuscripcion(int idSuscripcion, DT_MetodoPago metodo_pago){}
void DatosSuscripcionController::confirmarDatosSuscripcion(){}
void DatosSuscripcionController::listarNicknameJugadoresSuscritos(){}