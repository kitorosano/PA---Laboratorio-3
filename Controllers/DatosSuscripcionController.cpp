//
// Created by Admin on 23/06/2022.
//
#include "DatosSuscripcionController.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/Lista.h"
#include "ColeccionesG/KeyInt.h"
#include "ColeccionesG/IIterator.h"
#include "Factory/Factory.h"
#include "DataTypes/DT_NombreDescripcion.h"
#include "DataTypes/DT_VideojuegoSuscripciones.h"

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

int DatosSuscripcionController::getNuevoIdDatosSuscripcion(){
    return contadorIdDatosSuscripcion++;
}

IDictionary* DatosSuscripcionController::getDatosSuscripciones(){
    return this->datosSuscripciones;
}

IDictionary* DatosSuscripcionController::listarVideojuegoSuscripciones() {
    Factory* factory;
    IDictionary* videojuegoSuscripciones = new ListDicc();
    IIterator* iterVideojuegos = factory->getInstance()->getInterfaceV()->listarNombreVideojuegos()->getIteratorObj();
    while(iterVideojuegos->hasNext()){
        string nombreVideojuego = dynamic_cast<DT_NombreDescripcion*>(iterVideojuegos->next())->getNombre();
        double costoMensual, costoTrimestral, costoAnual, costoVitalicio;
        
        IIterator* iterSuscripciones = factory->getInstance()->getInterfaceD()->obtenerSuscripcionesVideojuego(nombreVideojuego)->getIteratorObj();
        while(iterSuscripciones->hasNext()){
            Suscripcion * suscripcion = dynamic_cast<Suscripcion*>(iterSuscripciones->next());
            switch (suscripcion->getPeriodoValidez()) {
                case E_PeriodoValidez::MENSUAL:
                    costoMensual = suscripcion->getCosto();
                    break;
                case E_PeriodoValidez::TRIMESTRAL:
                    costoTrimestral = suscripcion->getCosto();
                    break;
                case E_PeriodoValidez::ANUAL:
                    costoAnual = suscripcion->getCosto();
                    break;
                case E_PeriodoValidez::VITALICIA:
                    costoVitalicio = suscripcion->getCosto();
                    break;
                default:
                    break;
            }
        }
        delete iterSuscripciones;
        videojuegoSuscripciones->add(new DT_VideojuegoSuscripciones(nombreVideojuego, costoMensual, costoTrimestral, costoAnual, costoVitalicio), new KeyString(nombreVideojuego));
    }
    delete iterVideojuegos;
    return videojuegoSuscripciones;
}

IDictionary* DatosSuscripcionController::obtenerSuscripcionesVideojuego(string nombre_videojuego){
    Factory* factory;
    Videojuego* videojuego = factory->getInstance()->getInterfaceV()->obtenerVideojuegoPorNombre(nombre_videojuego);
    IIterator* iter = factory->getInstance()->getInterfaceV()->getSuscripciones()->getIteratorObj();
    IDictionary* suscripcionesVideojuego = new ListDicc();
    while(iter->hasNext()){
        Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(iter->getCurrent());
        if(suscripcion->getVideojuego()->getId() == videojuego->getId()){
            suscripcionesVideojuego->add(suscripcion, new KeyInt(suscripcion->getId()));
        }
    }
    delete iter;

    return suscripcionesVideojuego;
}

IDictionary* DatosSuscripcionController::listarNombreVideojuegosSuscritos(){
    Factory* factory;
    string uNickname = (dynamic_cast<Jugador*>(factory->getInstance()->getInterfaceU()->getUsuarioLogeado()))->getNickname();
    IDictionary* nombreVideojuegosSuscritos = new ListDicc();

    IIterator* iter = this->datosSuscripciones->getIteratorObj();
    while(iter->hasNext()){
        DatosSuscripcion* datosSuscripcion = dynamic_cast<DatosSuscripcion*>(iter->getCurrent());
        if(datosSuscripcion->getNickName().compare(uNickname) == 0 && datosSuscripcion->isActivo()){
            string nombreVideojuego = datosSuscripcion->getSuscripcion()->getVideojuego()->getNombre();
            nombreVideojuegosSuscritos->add(new DT_NombreDescripcion(nombreVideojuego), new KeyString(nombreVideojuego));
        }
    }
    delete iter;
    return nombreVideojuegosSuscritos;
}

void DatosSuscripcionController::cancelarSuscripcionActiva(int idSuscripcion){
    IIterator* iter = this->datosSuscripciones->getIteratorObj();

    while(iter->hasNext()){
        Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(iter->getCurrent());
        if(suscripcion->getId() == idSuscripcion){
            iter->remove();
        }
    }
}

void DatosSuscripcionController::crearDatosSuscripcion(int idSuscripcion, E_MetodoPago metodo_pago){
    Factory* factory;
    Jugador* jugadorLogueado = dynamic_cast<Jugador *>(factory->getInstance()->getInterfaceU()->getUsuarioLogeado());
    Suscripcion* suscripcion = dynamic_cast<Suscripcion *>(factory->getInstance()->getInterfaceV()->getSuscripciones()->find(new KeyInt(idSuscripcion)));

    this->controller_memory = new DatosSuscripcion(jugadorLogueado->getNickname(), suscripcion, metodo_pago);
}

void DatosSuscripcionController::confirmarDatosSuscripcion(){
    this->controller_memory->setId(this->getNuevoIdDatosSuscripcion());
    this->datosSuscripciones->add( this->controller_memory, new KeyInt( this->controller_memory->getId()));
    this->controller_memory = NULL;
}

void DatosSuscripcionController::cancelarDatosSuscripcion() {
    delete this->controller_memory;
    this->controller_memory = NULL;
}

void DatosSuscripcionController::listarNicknameJugadoresSuscritos(){
    IIterator* iter = this->datosSuscripciones->getIteratorObj();

    while(iter->hasNext()){
        DatosSuscripcion* datosSuscripcion = dynamic_cast<DatosSuscripcion*>(iter->getCurrent());
        cout << datosSuscripcion->getNickName() << endl;
    }
}