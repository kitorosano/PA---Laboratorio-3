//
// Created by Admin on 20/06/2022.
//

#include "Controllers/VideojuegoController.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/KeyInt.h"
#include "ColeccionesG/IIterator.h"
#include "DataTypes/E_PeriodoValidez.h"
#include "DataTypes/DT_InfoVideojuego.h"
#include "Classes/Suscripcion.h"


using namespace std;

VideojuegoController* VideojuegoController::instance = NULL;

VideojuegoController::VideojuegoController() {
    videojuegoSeleccionado = NULL;
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

IDictionary* VideojuegoController::listarSuscripciones(){}
void VideojuegoController::datosNuevoVideojuego(string nombre, string descripcion, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia) {
    // TODO implementar la fabrica para acceder al desarrollador logeado
    videojuegoSeleccionado = new Videojuego(nombre, descripcion, );

    // TODO FIX:
    Suscripcion* suscripcionMensual = new Suscripcion(videojuegoSeleccionado ,E_PeriodoValidez::MENSUAL, costoMensual);
}
void VideojuegoController::confirmarVideojuego(){
    videojuegos->add(this->videojuegoSeleccionado, new KeyInt(this->videojuegoSeleccionado->getIdVideojuego()));
}
void VideojuegoController::seleccionarVideoJuego(int id){
    Videojuego* videojuego = dynamic_cast<Videojuego *>(this->videojuegos->find(new KeyInt(id)));
    if(videojuego != NULL)
        this->videojuegoSeleccionado = videojuego;
    else
        throw std::invalid_argument("El idenficador no corresponde a un videojuego en el sistema");
}
Videojuego* VideojuegoController::obtenerVideojuegoPorNombre(string nombre_videojuego){
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
    throw std::invalid_argument("El nombre no corresponde a un videojuego en el sistema");
}
void VideojuegoController::listarNomDescVideoJuegos(){
    IIterator *it = this->videojuegos->getIteratorObj();
    Videojuego *videojuego = NULL;

    while(it->hasNext()){
        videojuego = dynamic_cast<Videojuego *>(it->getCurrent());
        //TODO borrar DT_NomDescVideojuego ya que no lo estoy usando
        cout << videojuego->getNombre() << " - " << videojuego->getDescripcion() << endl;
        it->next();
    }
    delete it;
}
void VideojuegoController::asignarPuntaje(string nombreVideojuego, int puntaje){
    Videojuego* videojuego = this->obtenerVideojuegoPorNombre(nombreVideojuego);
    this->puntuaciones->add(videojuego, new KeyInt(videojuego->getIdVideojuego()));
}
void VideojuegoController::listarNombreVideojuegos(){
    IIterator *it = this->videojuegos->getIteratorObj();
    Videojuego *videojuego = NULL;

    while(it->hasNext()){
        videojuego = dynamic_cast<Videojuego *>(it->getCurrent());
        cout << videojuego->getNombre() << endl;
        it->next();
    }
    delete it;
}
DT_InfoVideojuego VideojuegoController::verVideojuego(int idVideojuego){
    Videojuego* videojuego = dynamic_cast<Videojuego *>(this->videojuegos->find(new KeyInt(idVideojuego)));
    if(videojuego != NULL) {
        DT_InfoVideojuego *info = new DT_InfoVideojuego();
        info->setNombre(videojuego->getNombre());
        //TODO: obtener las categorias del videojuego
        info->setCategorias( );
        //TODO: obtener las suscripciones del videojuego
        info->setSuscripciones( );
        info->setEmpresa(videojuego->getNombreEmpresa());
        info->setPuntaje(videojuego->getPuntaje());

        cout << info->toString();
        delete info;
    } else
        throw std::invalid_argument("El idenficador no corresponde a un videojuego en el sistema");
}
DT_InfoVideojuego VideojuegoController::verVideojuegoDesarrollador(int idVideojuego){
    Videojuego* videojuego = dynamic_cast<Videojuego *>(this->videojuegos->find(new KeyInt(idVideojuego)));
    if(videojuego != NULL) {
        DT_InfoVideojuego *info = new DT_InfoVideojuego();
        info->setNombre(videojuego->getNombre());
        //TODO: obtener las categorias del videojuego
        info->setCategorias( );
        //TODO: obtener las suscripciones del videojuego
        info->setSuscripciones( );
        info->setEmpresa(videojuego->getNombreEmpresa());
        info->setPuntaje(videojuego->getPuntaje());
        info->setTotalHorasJugadas(videojuego->getTotalHorasJugadas());

        cout << info->toString();
        delete info;
    } else
        throw std::invalid_argument("El idenficador no corresponde a un videojuego en el sistema");
}
void VideojuegoController::listaJuegosPublicadosFinalizados(){
    //TODO Depende de las partidas de este videojuego
}