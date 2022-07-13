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
        instance = new PartidaController();
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
    if(jugadorlogeado){
        Individual* nuevaPartidaIndividual = new Individual(jugadorlogeado, videojuegoSeleccionado);
        this->partidaSeleccionada = nuevaPartidaIndividual; // el controlador recuerda la partida
    }else{
        throw std::invalid_argument("Usted no es un Jugador");
    }


}

void PartidaController::nuevaPartidaMultijugador(bool transmitidaEnVivo){
    Factory* fabrica;
    // Obtener videojuego seleccionado
    Videojuego* videojuegoSeleccionado = fabrica->getInterfaceV()->getVideojuegoSeleccionado();

    // Obtener el usuario logeado!!
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInterfaceU()->getUsuarioLogeado());
    if(jugadorlogeado){
        Multijugador* nuevaPartidaMultijugador = new Multijugador(jugadorlogeado, videojuegoSeleccionado, transmitidaEnVivo);
        this->partidaSeleccionada = nuevaPartidaMultijugador; // el controlador recuerda la partida
    }else{
        throw std::invalid_argument("Usted no es un Jugador");
    }

}

void PartidaController::ingresarNicknameALaPartida(string nickname){
    Factory* fabrica;
    Jugador *jugador = dyamica_cast<Jugador *> (fabrica->getInterfaceU()->BuscarUsuario(nickname));
    if(jugador){
        JugadorMultijugador* jugadorDeLaPartida = new JugadorMultijugador(jugador);

        // Agregar el puntero del jugador a la lista de jugadores que tiene esta partida multijugador
        Multijugador *multi = dynamic_cast<Multijugador *>(partidaSeleccionada);
        multi->unirNicknameAPartida(jugadorDeLaPartida);
        this->partidaSeleccionada = multi; // El controlador recurda la partida
    }else{
        throw std::invalid_argument("No es un Jugador");
    }

}

void PartidaController::confirmarPartida(){
    // Indicar el ID a la partida
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
IDictionary* PartidaController::listarPartidasMultijugadorUnidasNoFinalizadas(){

    Factory* fabrica;
    IIterator *it = this->partidas->getIteratorObj();
    Multijugador *multijugador = NULL;
    IDictionary* listadepartidasMulti = new ListDicc();
    Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInterfaceU()->getUsuarioLogeado());
    if(jugadorlogeado){
        while(it->hasNext()){
            multijugador = dynamic_cast<Multijugador *>(it->getCurrent());
            if(multijugador) {
                // verificar que no este finalizado
                // obtener la lista de jugadores de esa partida multijugador y verificar si el nickanme del jugador logeado esta alli esta alli
                KeyString *nickName = new KeyString(jugadorlogeado->getNickname());
                if ((multijugador->getFinalizada() == false) &&
                    (multijugador->getJugadoresEnLaPartida()->member(nickName))) {
                    // verificar si ese usuario ya abandono esa partida mirando el atributo hora finalizacion si tiene un horario o esta ne NULL
                    JugadorMultijugador* jugadorMultijugador = dynamic_cast<JugadorMultijugador *>(multijugador->getJugadoresEnLaPartida()->find(
                            nickName));
                    if (jugadorMultijugador->getHora_finalizacion() == NULL){
                        // Guardo todo esos atributos en un Data Type para despues mostrarlos
                        int idpartida = multijugador->getIdPartida();
                        string fecha = multijugador->getFecha().getDate();
                        string horaComienzo = multijugador->getHoraComienzo().getTime();
                        string nomVideojuego = multijugador->getVideojuego()->getNombre();
                        bool transmitidaEnVivo = multijugador->isTransmitidaEnVivo();
                        string jugadorIniciador = multijugador->getJugador()->getNickname();
                        IDictionary *jugadoresEnLaPartida = multijugador->getJugadoresEnLaPartida();
                        // Se crea el DT que tenga los datos que se piden en el caso de uso y se guarda en la coleccion para despues devolver esa coleccion
                        DT_MultijugadorUnidosNoFinalizados *dt = new DT_MultijugadorUnidosNoFinalizados(idpartida, fecha,
                                                                                                        horaComienzo,
                                                                                                        nomVideojuego,
                                                                                                        transmitidaEnVivo,
                                                                                                        jugadorIniciador,
                                                                                                        jugadoresEnLaPartida)
                        listadepartidasMulti->add(dt, new KeyString(to_string(idpartida)));
                    }

                }
            }
            it->next();
        }
    }else{
        throw std::invalid_argument("Usted no es un Jugador");
    }
    return listadepartidasMulti;
}

void PartidaController::confirmarAbandonoPartida(int idPartida){
    KeyString* idpartida = new KeyString(to_string(idPartida));
    Multijugador* partidaAAbandonar = dynamic_cast<Multijugador *>(this->partidas->find(idpartida));
    JugadorMultijugador *jugadorUnido = NULL;
    if(partidaAAbandonar){
        Factory* fabrica;
        Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInterfaceU()->getUsuarioLogeado());
        if(jugadorlogeado){
            IIterator *it = partidaAAbandonar->getJugadoresEnLaPartida()->getIteratorObj();
            while(it->hasNext()){
                jugadorUnido = dynamic_cast<JugadorMultijugador *>(it->getCurrent());
                if(jugadorlogeado->getNickname() == jugadorUnido->getJugador()->getNickname()){
                    DT_Time* horafinal = New DT_Time();
                    jugadorUnido->setHoraFinalizacion(horafinal);
                }
                it->next();
            }
        }else{
            throw std::invalid_argument("Usted no es un Jugador");
        }


        }
    }

}
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
IDictionary* PartidaController::listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(){}

void PartidaController::cancelarIniciarPartida() {
    this->partidaSeleccionada = NULL;
    // setear a NULL tambien el videoJuegoSeleccionado que es la variable que esta en el controladorVideoJuego
}
// lugar 1
