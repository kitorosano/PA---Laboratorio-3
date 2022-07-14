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
    return contadorIdVideojuego++;
}
int VideojuegoController::getNuevoIdSuscripcion() {
    return contadorIdSuscripcion++;
}

IDictionary* VideojuegoController::getSuscripciones(){
    return suscripciones;
}

void VideojuegoController::datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia) {
    Factory* fabrica;
    Desarrollador* desarrolladorLogeado = dynamic_cast<Desarrollador*>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());

    Videojuego* videojuego = new Videojuego(nombre, descripcion, desarrolladorLogeado);

    Suscripcion* SMensual = new Suscripcion(videojuego, E_PeriodoValidez::MENSUAL, costoMensual);
    suscripcionesEnMemoria->add(SMensual);

    Suscripcion* STrimestral = new Suscripcion(videojuego, E_PeriodoValidez::TRIMESTRAL, costoTrimestral);
    suscripcionesEnMemoria->add(STrimestral);

    Suscripcion* SAnual = new Suscripcion(videojuego, E_PeriodoValidez::ANUAL, costoAnual);
    suscripcionesEnMemoria->add(SAnual);

    Suscripcion* SVitalicia = new Suscripcion(videojuego, E_PeriodoValidez::VITALICIA, costoVitalicia);
    suscripcionesEnMemoria->add(SVitalicia);

    setVideojuegoSeleccionado(videojuego);
}
void VideojuegoController::confirmarVideojuego(){
    //Iterar por cada suscripcion en memoria y almacenarla en coleccion de suscripciones con su key
    IIterator* iter = suscripcionesEnMemoria->iterator();
    while (iter->hasNext()) {
        Suscripcion* suscripcion= dynamic_cast<Suscripcion *>(iter->getCurrent());
        suscripcion->setId(this->getNuevoIdSuscripcion());
        KeyInt* key = new KeyInt(suscripcion->getId());
        suscripciones->add(suscripcion, key);
    }
    delete iter;

    this->videojuegoSeleccionado->setId(this->getNuevoIdVideojuego());
    videojuegos->add(this->videojuegoSeleccionado, new KeyInt(this->videojuegoSeleccionado->getId()));
    this->videojuegoSeleccionado = NULL;
}
void VideojuegoController::cancelarVideojuego(){
    // Iterar por cada suscripcion en memoria y eliminarlas
    IIterator* iter = suscripcionesEnMemoria->iterator();
    while (iter->hasNext()) {
        Suscripcion* suscripcion= dynamic_cast<Suscripcion *>(iter->getCurrent());
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
Videojuego* VideojuegoController::obtenerVideojuegoPorNombre(string nombre_videojuego){
    if(!this->videojuegos){
        cout<<"no hay videojuegos ingresados"<<endl;
        return NULL;
    }
    IIterator *it = this->videojuegos->getIteratorObj();
    Videojuego *videojuego = NULL;

    while(it->hasNext()){
        videojuego = dynamic_cast<Videojuego *>(it->getCurrent());
        if(videojuego->getNombre() == nombre_videojuego){
            return videojuego;
        }
        it->next();
    }
    delete it;
    //throw std::invalid_argument("El nombre no corresponde a un videojuego en el sistema");
    cout<<"El nombre no corresponde a un videojuego en el sistema"<<endl;
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

        info->setSuscripciones(fabrica->getInstance()->getInterfaceD()->obtenerSuscripcionesVideojuego(this->videojuegoSeleccionado->getNombre()));

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

        info->setSuscripciones(fabrica->getInstance()->getInterfaceD()->obtenerSuscripcionesVideojuego(this->videojuegoSeleccionado->getNombre()));

        info->setEmpresa(this->videojuegoSeleccionado->getNombreEmpresa());
        info->setPuntaje(this->videojuegoSeleccionado->getPuntaje());
        info->setTotalHorasJugadas(this->videojuegoSeleccionado->getTotalHorasJugadas());

        cout << info->toString();
        delete info;

}

//TODO: DEPENDE DE LAS PARTIDAS
//void VideojuegoController::listaJuegosPublicadosFinalizados(){}