//
// Created by Davila on 21/6/2022.
//

#include "PartidaController.h"
using namespace std;

PartidaController* PartidaController::instance = NULL;

PartidaController::PartidaController() {
    partidas = new ListDicc();
    partidaSeleccionada = NULL;
    partidaAContinuar = NULL;
    comentarioAResponder = NULL;
    nuevoComentario = NULL;
    idpartida = 0;
}

PartidaController::~PartidaController(){}

PartidaController *PartidaController::getInstance() {
    if(instance == NULL)
        instance = new PartidaController;
    return instance;
}

void PartidaController::continuarPartidaIndividual(string idPartida){
    IIterator *it = this->partidas->getIteratorObj();
    Individual *partidaAContinuar = NULL;

    while(it->hasNext()){
        partidaAContinuar = dynamic_cast<Individual *>(it->getCurrent());
        if(partidaAContinuar){
            if(partidaAContinuar->getIdPartida() == idPartida){
                Individual* nuevaPartidaQueContinuara = new Individual(partidaAContinuar->getJugador(),partidaAContinuar->getVideojuego());
                this->partidaSeleccionada = nuevaPartidaQueContinuara; // guardo a la partida nueva que es la que sera la continuacion de la otra que se busco con el ID
                this->partidaAContinuar = partidaAContinuar; // guardo la partida a la cual van a continuar
                return;
            }
        }
        it->next();
    }
    throw std::invalid_argument("La partida no existe");
}

void PartidaController::nuevaPartidaIndividual(){

    VideojuegoController* videojuegoController;
    Videojuego* videojuegoSeleccionado = videojuegoController->getInstance()->getVideojuegoSeleccionado();

    UsuarioController* usuarioController;
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(usuarioController->getInstance()->getUsuarioLogeado());

    Individual* nuevaPartidaIndividual = new Individual(jugadorlogeado, videojuegoSeleccionado);
    this->partidaSeleccionada = nuevaPartidaIndividual; // el controlador recuerda la partida
}

void PartidaController::nuevaPartidaMultijugador(bool transmitidaEnVivo){
    VideojuegoController* videojuegoController;
    Videojuego* videojuegoSeleccionado = videojuegoController->getInstance()->getVideojuegoSeleccionado();

    UsuarioController* usuarioController;
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(usuarioController->getInstance()->getUsuarioLogeado());

    Multijugador* nuevaPartidaMulti = new Multijugador(jugadorlogeado, videojuegoSeleccionado, transmitidaEnVivo);
    this->partidaSeleccionada = nuevaPartidaMulti; // el controlador recuerda la partida

}

void PartidaController::ingresarNicknameALaPartida(string nickname){
    UsuarioController* usuarioController;
    Jugador *jugadorDeLaPartida = dyamica_cast<Jugador * > (usuarioController->getInstance()->ObtenerUsuario(nickname));
    //ObtenerUsuario(nickname) me tedria que dar un puntero al usuario con ese nickname

    // Agregar el puntero del jugador a la lista de jugadores que tiene esta partida multijugador
    Multijugador *multi = dynamic_cast<Multijugador *>(partidaSeleccionada);
    multi->unirNicknameAPartida(jugadorDeLaPartida);
}

void PartidaController::confirmarPartida(){
    // Para la parte de continuar partida individual
    if(partidaAContinuar == NULL){
        Individual *partidaQueContinuara = dynamic_cast<Individual*>(this->partidaSeleccionada);
        partidaAContinuar->setContPartAnterior(partidaQueContinuara);
    }

    // id para la partida
    string idPartida = to_string(idpartida++);
    this->partidaSeleccionada->setIdPartida(idPartida);

    // fecha  para la partida
    DT_Date *fecha = new DT_Date();
    this->partidaSeleccionada->setFecha(*fecha);

    // hora de comienzo de la partida
    DT_Time *horaComienzo = new DT_Time();
    this->partidaSeleccionada->setHoraComienzo(*horaComienzo);

    // add partidaseleccionada;
    partidas->add(partidaSeleccionada,new KeyString(idPartida));

    // borrar datos guardados
    this->partidaSeleccionada = NULL;
    this->partidaAContinuar = NULL;
}
IDictionary* PartidaController::listarPartidasMultijugadorUnidasNoFinalizadas(){}
void PartidaController::confirmarAbandonoPartida(string idPartida){}
IDictionary* PartidaController::listarPartidasIniciadasNoFinalizadas(){}
void PartidaController::confirmarFinalizarPartida(string idPartida){}
void PartidaController::seleccionarPartida(string idPartida){}
IDictionary* PartidaController::listarComentariosDePartida(){}
void PartidaController::seleccionarComentarioAResponder(int idComentario){}
void PartidaController::enviarComentario(string comentario){}
void PartidaController::confirmarComentario(){}
void PartidaController::listarHistorialPartidasFinalizadasCronologicamente(){} // lugar 9
IDictionary* PartidaController::listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(){} // lugar 1