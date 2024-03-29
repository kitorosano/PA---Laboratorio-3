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

DatosSuscripcion* DatosSuscripcionController::getDatoSuscripcionSeleccionado() {
    return this->datoSuscripcionSeleccionado;
}

IDictionary* DatosSuscripcionController::listarVideojuegoSuscripciones() {
    Factory* factory;
    IDictionary* videojuegoSuscripciones = new ListDicc();
    IIterator* iterVideojuegos = factory->getInstance()->getInterfaceV()->listarNombreVideojuegos()->getIteratorObj();
    while(iterVideojuegos->hasNext()){
        string nombreVideojuego = dynamic_cast<DT_NombreDescripcion*>(iterVideojuegos->next())->getNombre();
        double costoMensual, costoTrimestral, costoAnual, costoVitalicio;
        
        IIterator* iterSuscripciones = factory->getInstance()->getInterfaceV()->obtenerSuscripcionesVideojuego(nombreVideojuego)->getIteratorObj();
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

IDictionary* DatosSuscripcionController::listarNombreVideojuegosSuscritos(Jugador * jugadorLogueado) {
    Factory* factory;

    IDictionary* nombreVideojuegosSuscritos = new ListDicc();

    IIterator* iter = this->datosSuscripciones->getIteratorObj();
    while(iter->hasNext()){
        DatosSuscripcion* datosSuscripcion = dynamic_cast<DatosSuscripcion*>(iter->next());
        if(datosSuscripcion->getNickName().compare(jugadorLogueado->getNickname()) == 0 && datosSuscripcion->isActivo()){
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
        Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(iter->next());
        if(suscripcion->getId() == idSuscripcion){
            iter->remove();
        }
    }
}

void DatosSuscripcionController::crearDatosSuscripcion(string nickname, int idSuscripcion, E_MetodoPago metodo_pago){
    Factory* factory;
    Suscripcion* suscripcion = dynamic_cast<Suscripcion *>(factory->getInstance()->getInterfaceV()->getSuscripciones()->find(new KeyInt(idSuscripcion)));
    this->datoSuscripcionSeleccionado = new DatosSuscripcion(nickname, suscripcion, metodo_pago);
}

void DatosSuscripcionController::confirmarDatosSuscripcion(DT_Fecha* fecha_suscripcion){
    this->datoSuscripcionSeleccionado->setId(this->getNuevoIdDatosSuscripcion());
    this->datoSuscripcionSeleccionado->setFechaSuscripcion(fecha_suscripcion);
    this->datosSuscripciones->add(this->datoSuscripcionSeleccionado, new KeyInt(this->datoSuscripcionSeleccionado->getId()));
    this->datoSuscripcionSeleccionado = NULL;
}

void DatosSuscripcionController::cancelarDatosSuscripcion() {
    delete this->datoSuscripcionSeleccionado;
    this->datoSuscripcionSeleccionado = NULL;
}

void DatosSuscripcionController::listarNicknameJugadoresSuscritos(){
    IIterator* iter = this->datosSuscripciones->getIteratorObj();

    while(iter->hasNext()){
        DatosSuscripcion* datosSuscripcion = dynamic_cast<DatosSuscripcion*>(iter->next());
        cout << datosSuscripcion->getNickName() << endl;
    }
}

IDictionary* DatosSuscripcionController::listarNicknameJugadoresSuscritosConRetorno(){
    //Factory* fabrica;
    IIterator* iter = this->datosSuscripciones->getIteratorObj();
    IDictionary * listadeJugadores = new ListDicc();
    /*
    while(iter->hasNext()){
        DatosSuscripcion* datosSuscripcion = dynamic_cast<DatosSuscripcion*>(iter->getCurrent());
        Videojuego * videojuego = datosSuscripcion->getSuscripcion()->getVideojuego();
        Videojuego* videojuegoSeleccionado = fabrica->getInstance()->getInterfaceV()->getVideojuegoSeleccionado();
        if(videojuegoSeleccionado == videojuego){
            KeyString* nickname = new KeyString(datosSuscripcion->getNickName());
            DT_NombreDescripcion* nicknameJugador = new DT_NombreDescripcion(datosSuscripcion->getNickName());
            listadeJugadores->add(nicknameJugador, nickname);
            //cout << datosSuscripcion->getNickName() << endl;
        }
        iter->next();
    }
    */
    while(iter->hasNext()){
        DatosSuscripcion* datosSuscripcion = dynamic_cast<DatosSuscripcion*>(iter->getCurrent());
        KeyString* nickname = new KeyString(datosSuscripcion->getNickName());
        DT_NombreDescripcion* nicknameJugador = new DT_NombreDescripcion(datosSuscripcion->getNickName());
        if(!listadeJugadores->member(nickname)) {
            listadeJugadores->add(nicknameJugador, nickname);
        }
        iter->next();
    }
    return listadeJugadores;
}