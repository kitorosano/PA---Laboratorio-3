//
// Created by Admin on 23/06/2022.
//
#include "DatosSuscripcionController.h"

using namespace std;

DatosSuscripcionController* DatosSuscripcionController::instance = NULL;

DatosSuscripcionController::DatosSuscripcionController(){
    this->suscripciones = vector<Suscripcion*>();
    this->datosSuscripciones = vector<DatosSuscripcion*>();
}

DatosSuscripcionController::~DatosSuscripcionController(){}

DatosSuscripcionController* DatosSuscripcionController::getInstance(){
    if(instance == NULL){
        instance = new DatosSuscripcionController();
    }
    return instance;
}

vector<Suscripcion*> DatosSuscripcionController::listarSuscripciones(){}
vector<Suscripcion*> DatosSuscripcionController::obtenerSuscripcionesVideojuego(string nombre_videojuego){}


vector<string> DatosSuscripcionController::listarNombreVideojuegosSuscritos(){}
void DatosSuscripcionController::cancelarSuscripcionActiva(int idSuscripcion){}

void DatosSuscripcionController::crearDatosSuscripcion(int idSuscripcion, E_MetodoPago metodo_pago){}
void DatosSuscripcionController::confirmarDatosSuscripcion(){}

vector<string> DatosSuscripcionController::listarNicknameJugadoresSuscritos(){}