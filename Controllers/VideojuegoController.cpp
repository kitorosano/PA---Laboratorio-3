//
// Created by Admin on 20/06/2022.
//

#include "Controllers/VideojuegoController.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/Lista.h"
#include "ColeccionesG/KeyInt.h"
#include "ColeccionesG/IIterator.h"
#include "Factory/Factory.h"
#include "DataTypes/DT_NombreDescripcion.h"

using namespace std;

VideojuegoController* VideojuegoController::instance = NULL;

VideojuegoController::VideojuegoController() {
    videojuegoSeleccionado = NULL;
    suscripcionesEnMemoria = new Lista();
    videojuegos = new ListDicc();
    puntuaciones = new ListDicc();
    suscripciones = new ListDicc();
}

VideojuegoController::~VideojuegoController(){}

VideojuegoController* VideojuegoController::getInstance() {
    if (instance == NULL) {
        instance = new VideojuegoController();
    }
    return instance;
}

Videojuego* VideojuegoController::getVideojuegoSeleccionado() {
    return videojuegoSeleccionado;
}
void VideojuegoController::setVideojuegoSeleccionado(Videojuego* videojuego) {
    this->videojuegoSeleccionado = videojuego;
}

int VideojuegoController::getNuevoIdVideojuego() {
    return this->contadorIdVideojuego++;
}
int VideojuegoController::getNuevoIdSuscripcion() {
    return this->contadorIdSuscripcion++;
}

IDictionary* VideojuegoController::getVideojuegos() {
    return this->videojuegos;
}

IDictionary* VideojuegoController::getSuscripciones(){
    return this->suscripciones;
}

void VideojuegoController::datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia, Desarrollador* desarrollador) {
    Factory* fabrica;

    Videojuego* videojuego = new Videojuego(nombre, descripcion, desarrollador);

    Suscripcion* SMensual = new Suscripcion(videojuego, E_PeriodoValidez::MENSUAL, costoMensual);
    this->suscripcionesEnMemoria->add(SMensual);

    Suscripcion* STrimestral = new Suscripcion(videojuego, E_PeriodoValidez::TRIMESTRAL, costoTrimestral);
    this->suscripcionesEnMemoria->add(STrimestral);

    Suscripcion* SAnual = new Suscripcion(videojuego, E_PeriodoValidez::ANUAL, costoAnual);
    this->suscripcionesEnMemoria->add(SAnual);

    Suscripcion* SVitalicia = new Suscripcion(videojuego, E_PeriodoValidez::VITALICIA, costoVitalicia);
    this->suscripcionesEnMemoria->add(SVitalicia);

    this->videojuegoSeleccionado = videojuego;
}

Videojuego* VideojuegoController::confirmarVideojuego(){
    Videojuego *videojuego = NULL;

    if(this->suscripcionesEnMemoria && this->videojuegoSeleccionado) {
        //Iterar por cada suscripcion en memoria y almacenarla en coleccion de suscripciones con su key
        IIterator *iter = suscripcionesEnMemoria->iterator();
        while (iter->hasNext()) {
            Suscripcion *suscripcion = dynamic_cast<Suscripcion *>(iter->next());
            suscripcion->setId(this->getNuevoIdSuscripcion());
            KeyInt *key = new KeyInt(suscripcion->getId());
            this->suscripciones->add(suscripcion, key);
        }
        delete iter;

        this->videojuegoSeleccionado->setId(this->getNuevoIdVideojuego());
        videojuegos->add(this->videojuegoSeleccionado, new KeyInt(this->videojuegoSeleccionado->getId()));
        videojuego = this->videojuegoSeleccionado;
    }
    this->suscripcionesEnMemoria = new Lista();
    this->videojuegoSeleccionado = NULL;

    return videojuego;
}
void VideojuegoController::cancelarVideojuego(){
    // Iterar por cada suscripcion en memoria y eliminarlas
    IIterator* iter = suscripcionesEnMemoria->iterator();
    while (iter->hasNext()) {
        Suscripcion* suscripcion= dynamic_cast<Suscripcion *>(iter->next());
        suscripcionesEnMemoria->remove(suscripcion);
    }
    delete iter;

    delete this->videojuegoSeleccionado;
    this->videojuegoSeleccionado = NULL;
}
void VideojuegoController::seleccionarVideoJuego(int id){
    Videojuego* videojuego = dynamic_cast<Videojuego *>(this->videojuegos->find(new KeyInt(id)));
    if(videojuego != NULL)
        this->videojuegoSeleccionado = videojuego;
    else
        throw std::invalid_argument("El idenficador no corresponde a un videojuego en el sistema");
}
Videojuego* VideojuegoController::obtenerVideojuegoPorId(int id_videojuego){
    if(!this->videojuegos){
        cout<<"no hay videojuegos ingresados"<<endl;
        return NULL;
    }

    Videojuego* videojuego = dynamic_cast<Videojuego*>(videojuegos->find(new KeyInt(id_videojuego)));
    if(videojuego) return videojuego;

    //throw std::invalid_argument("El nombre no corresponde a un videojuego en el sistema");
    cout<<"El id no corresponde a un videojuego en el sistema"<<endl;
    return NULL;
}
Videojuego* VideojuegoController::obtenerVideojuegoPorNombre(string nombre_videojuego){
    if(this->videojuegos) {
        IIterator *it = this->videojuegos->getIteratorObj();
        Videojuego *videojuego = NULL;

        while (it->hasNext()) {
            videojuego = dynamic_cast<Videojuego *>(it->getCurrent());
            if (videojuego->getNombre() == nombre_videojuego) {
                return videojuego;
            }
            it->next();
        }
        delete it;
    }
    //throw std::invalid_argument("El nombre no corresponde a un videojuego en el sistema");
    cout<<"No se encontro el videojuego en el sistema"<<endl;
    return NULL;
}

void VideojuegoController::listarNomDescVideoJuegos(){
    IIterator *it = this->videojuegos->getIteratorObj();
    Videojuego *videojuego = NULL;

    while(it->hasNext()){
        videojuego = dynamic_cast<Videojuego *>(it->getCurrent());
        cout << videojuego->getNombre() << " - " << videojuego->getDescripcion() << endl;
        it->next();
    }
    delete it;
}
void VideojuegoController::asignarPuntaje(string nombreVideojuego, int puntaje){
    Videojuego* videojuego = this->obtenerVideojuegoPorNombre(nombreVideojuego);
    this->puntuaciones->add(videojuego, new KeyInt(videojuego->getId()));
}
IDictionary* VideojuegoController::listarNombreVideojuegos(){
    IIterator *it = this->videojuegos->getIteratorObj();
    Videojuego *videojuego = NULL;
    IDictionary* nombres = new ListDicc();

    while(it->hasNext()){
        videojuego = dynamic_cast<Videojuego *>(it->getCurrent());
        nombres->add(new DT_NombreDescripcion(videojuego->getNombre()), new KeyString(videojuego->getNombre()));
        it->next();
    }
    delete it;

    return nombres;
}
void VideojuegoController::verVideojuego(){
    Factory* fabrica;

        DT_InfoVideojuego *info = new DT_InfoVideojuego();
        info->setNombre(this->videojuegoSeleccionado->getNombre());

        info->setCategorias(fabrica->getInstance()->getInterfaceC()->obtenerCategoriasVideojuego(this->videojuegoSeleccionado->getNombre()));

        info->setSuscripciones(this->obtenerSuscripcionesVideojuego(this->videojuegoSeleccionado->getNombre()));

        info->setEmpresa(this->videojuegoSeleccionado->getNombreEmpresa());

        info->setPuntaje(this->videojuegoSeleccionado->getPuntaje());

        cout << info->toString();
        delete info;

}
void VideojuegoController::verVideojuegoDesarrollador(){
    Factory* fabrica;

        DT_InfoVideojuego *info = new DT_InfoVideojuego();
        info->setNombre(this->videojuegoSeleccionado->getNombre());

        info->setCategorias(fabrica->getInstance()->getInterfaceC()->obtenerCategoriasVideojuego(videojuegoSeleccionado->getNombre()));

        info->setSuscripciones(this->obtenerSuscripcionesVideojuego(this->videojuegoSeleccionado->getNombre()));

        info->setEmpresa(this->videojuegoSeleccionado->getNombreEmpresa());
        info->setPuntaje(this->videojuegoSeleccionado->getPuntaje());
        info->setTotalHorasJugadas(this->videojuegoSeleccionado->getTotalHorasJugadas());

        cout << info->toString();
        delete info;

}


IDictionary* VideojuegoController::obtenerSuscripcionesVideojuego(string nombre_videojuego){
    Factory* factory;
    Videojuego* videojuego = factory->getInstance()->getInterfaceV()->obtenerVideojuegoPorNombre(nombre_videojuego);
    IIterator* iter = factory->getInstance()->getInterfaceV()->getSuscripciones()->getIteratorObj();
    IDictionary* suscripcionesVideojuego = new ListDicc();
    while(iter->hasNext()){
        Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(iter->next());
        if(suscripcion->getVideojuego()->getId() == videojuego->getId()){
            suscripcionesVideojuego->add(suscripcion, new KeyInt(suscripcion->getId()));
        }
    }
    delete iter;

    return suscripcionesVideojuego;
}

Suscripcion* VideojuegoController::obtenerSuscripcionVideojuego(int id_videojuego, E_PeriodoValidez periodoValidez){
    Factory* factory;

    if(!factory->getInstance()->getInterfaceV()->getVideojuegos()->find(new KeyInt(id_videojuego))) {
        cout<<"El id no corresponde a un videojuego en el sistema"<<endl;
        return NULL;
    }

    IIterator* iter = factory->getInstance()->getInterfaceV()->getSuscripciones()->getIteratorObj();
    while(iter->hasNext()){
        Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(iter->next());
        if(suscripcion->getVideojuego()->getId() == id_videojuego && suscripcion->getPeriodoValidez() == periodoValidez){
            return suscripcion;
        }
    }
    delete iter;

    cout << "No se encontro la suscripcion"<<endl;
    return NULL;
}

void VideojuegoController::listaJuegosPublicadosFinalizados(){}