//
// Created by Davila on 21/6/2022.
//

#include "PartidaController.h"
using namespace std;

PartidaController* PartidaController::instance = NULL;

PartidaController::PartidaController() {
    partidas = new ListDicc();
    partidaSeleccionada = NULL;
    comentarioAResponder = NULL;
    nuevoComentario = NULL;
    idpartida = 1;
}

PartidaController::~PartidaController(){}

PartidaController *PartidaController::getInstance() {
    if(instance == NULL)
        instance = new PartidaController;
    return instance;
}

void PartidaController::continuarPartidaIndividual(int idPartida){
    IIterator *it = this->partidas->getIteratorObj();
    Individual *partidaAContinuar = NULL;

    while(it->hasNext()){
        partidaAContinuar = dynamic_cast<Individual *>(it->getCurrent());
        if(partidaAContinuar){
            if(partidaAContinuar->getIdPartida() == idPartida){
                Individual* nuevaPartida = new Individual(partidaAContinuar->getJugador(),partidaAContinuar->getVideojuego());
                nuevaPartida->setContPartAnterior(partidaAContinuar); // Se establece de quien continuara la partida nueva
                this->partidaSeleccionada = nuevaPartida; // El controlador recuerda la partida nueva que sera una continuacion de la anterior
                return;
            }
        }
        it->next();
    }
    throw std::invalid_argument("La partida no existe");
}

void PartidaController::nuevaPartidaIndividual(){
    Factory* fabrica;
    // Obtener el videojuego seleccionado!!
    Videojuego* videojuegoSeleccionado = fabrica->getInterfaceV()->getVideojuegoSeleccionado();

     // Obtener el usuario logeado!!
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInterfaceU()->getUsuarioLogeado());

    Individual* nuevaPartidaIndividual = new Individual(jugadorlogeado, videojuegoSeleccionado);
    this->partidaSeleccionada = nuevaPartidaIndividual; // el controlador recuerda la partida

}

void PartidaController::nuevaPartidaMultijugador(bool transmitidaEnVivo){
    Factory* fabrica;
    // Obtener videojuego seleccionado
    Videojuego* videojuegoSeleccionado = fabrica->getInterfaceV()->getVideojuegoSeleccionado();

    // Obtener el usuario logeado!!
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInterfaceU()->getUsuarioLogeado());

    Multijugador* nuevaPartidaMultijugador = new Multijugador(jugadorlogeado, videojuegoSeleccionado, transmitidaEnVivo);
    this->partidaSeleccionada = nuevaPartidaMultijugador; // el controlador recuerda la partida

}

void PartidaController::ingresarNicknameALaPartida(string nickname){
    Factory* fabrica;
    Jugador *jugadorDeLaPartida = dyamica_cast<Jugador *> (fabrica->getInterfaceU()->BuscarUsuario(nickname));

    // Agregar el puntero del jugador a la lista de jugadores que tiene esta partida multijugador
    Multijugador *multi = dynamic_cast<Multijugador *>(partidaSeleccionada);
    multi->unirNicknameAPartida(jugadorDeLaPartida);
    this->partidaSeleccionada = multi; // El controlador recurda la partida
}

void PartidaController::confirmarPartida(){

        // Asignar la Referencia para la partida

    int idPartida = this->idpartida++;
    this->partidaSeleccionada->setIdPartida(idPartida);

    // Asignar la Fecha para la partida
    DT_Date *fecha = new DT_Date();
    this->partidaSeleccionada->setFecha(*fecha);

    // Asignar la hora de comienzo de la partida
    DT_Time *horaComienzo = new DT_Time();
    this->partidaSeleccionada->setHoraComienzo(*horaComienzo);

    // Agregar a la colección la nueva partida;
    partidas->add(partidaSeleccionada, new KeyString(to_string(idPartida)));

    // Borrar los datos que el controlador guardo
    this->partidaSeleccionada = NULL;

}
IDictionary* PartidaController::listarPartidasMultijugadorUnidasNoFinalizadas(){}
void PartidaController::confirmarAbandonoPartida(int idPartida){}
IDictionary* PartidaController::listarPartidasIniciadasNoFinalizadas(){}
void PartidaController::confirmarFinalizarPartida(int idPartida){}
void PartidaController::seleccionarPartida(int idPartida){}
IDictionary* PartidaController::listarComentariosDePartida(){}
void PartidaController::seleccionarComentarioAResponder(int idComentario){}
void PartidaController::enviarComentario(string comentario){}
void PartidaController::confirmarComentario(){}

IDictionary* PartidaController::listarHistorialPartidasFinalizadasCronologicamente(){
    // Obtener el usuario logeado!!
    Factory* fabrica;
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInterfaceU()->getUsuarioLogeado());

    // Comparar si el usuario jugador le pertenece la partida y si es finalizada
    IIterator *it = this->partidas->getIteratorObj();
    Individual *partida = NULL;
    IDictionary* listadepartidas = new ListDicc();
    while(it->hasNext()){
        partida = dynamic_cast<Individual *>(it->getCurrent());
        if(partida){
            if((partida->getJugador()->getNickname() == jugadorlogeado->getNickname()) && (partida->getFinalizada())){
                // Guardar todo en una coleccion y retorna esa coleccion
                DT_PartidasIndividualesFinalizadas *dt_partida = new DT_PartidasIndividualesFinalizadas(partida->getIdPartida(), partida->getFecha().getDate(), partida->getHoraComienzo().getTime(), partida->getHorasPartida());
                listadepartidas->add(reinterpret_cast<ICollectible *>(dt_partida), new KeyString(to_string(dt_partida->getIdPartida())));
            }
        }
        it->next();
    }
    return listadepartidas;


}
IDictionary* PartidaController::listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(){} // lugar 1
