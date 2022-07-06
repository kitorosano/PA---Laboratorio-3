//
// Created by Admin on 20/06/2022.
//

#include "Controllers/VideojuegoController.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/KeyString.h"
#include "DataTypes/E_PeriodoValidez.h"
#include "Classes/Suscripcion.h"


using namespace std;

VideojuegoController* VideojuegoController::instance = NULL;

VideojuegoController::VideojuegoController() {
    videojuegoSeleccionado = NULL;
    videojuegos = new ListDicc();
suscripciones = new ListDicc();
}

VideojuegoController::~VideojuegoController(){}

VideojuegoController* VideojuegoController::getInstance() {
    if (instance == NULL) {
        instance = new VideojuegoController();
    }
    return instance;
}

IDictionary* VideojuegoController::listarSuscripciones(){}
void VideojuegoController::datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia) {
    videojuegoSeleccionado = new Videojuego(nombre, descripcion);

    // TO FIX:
    Suscripcion* suscripcionMensual = new Suscripcion(videojuegoSeleccionado ,E_PeriodoValidez::MENSUAL, costoMensual);
}
void VideojuegoController::confirmarVideojuego(){
    videojuegos->add(this->videojuegoSeleccionado, new KeyString(this->videojuegoSeleccionado->getIdVideojuego()));
}
void VideojuegoController::seleccionarVideoJuego(string id){
    this->videojuegoSeleccionado = dynamic_cast<Videojuego *>(this->videojuegos->find(new KeyString(id)));
}
Videojuego* VideojuegoController::obtenerVideojuegoPorNombre(string nombre_videojuego){}
IDictionary* VideojuegoController::listarNomDescVideoJuegos(){}
void VideojuegoController::asignarPuntaje(string nombreVideojuego, int puntaje){}
IDictionary* VideojuegoController::listarNombreVideojuegos(){}
DT_InfoVideojuegoJugador VideojuegoController::verVideojuego(string idVideojuego){}
DT_InfoVideojuegoDesarrollador VideojuegoController::verVideojuegoDesarrollador(string idVideojuego){}
IDictionary* VideojuegoController::listaJuegosPublicadosFinalizados(){}