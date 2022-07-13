//
// Created by Admin on 23/06/2022.
//
#include "DatosSuscripcionController.h"
#include "ColeccionesG/ListaDicc.h"

using namespace std;

DatosSuscripcionController* DatosSuscripcionController::instance = NULL;

DatosSuscripcionController::DatosSuscripcionController(){
    this->datosSuscripciones = new ListDicc();
}

DatosSuscripcionController::~DatosSuscripcionController(){}

DatosSuscripcionController* DatosSuscripcionController::getInstance(){
    if(instance == NULL){
        instance = new DatosSuscripcionController();
    }
    return instance;
}

//IDictionary* DatosSuscripcionController::obtenerSuscripcionesVideojuego(string nombre_videojuego){}
//
//
//IDictionary* DatosSuscripcionController::listarNombreVideojuegosSuscritos(){}
//void DatosSuscripcionController::cancelarSuscripcionActiva(int idSuscripcion){}
//
//void DatosSuscripcionController::crearDatosSuscripcion(int idSuscripcion, E_MetodoPago metodo_pago){}
//void DatosSuscripcionController::confirmarDatosSuscripcion(){}
//
//IDictionary* DatosSuscripcionController::listarNicknameJugadoresSuscritos(){}