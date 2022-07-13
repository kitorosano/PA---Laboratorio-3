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
    // Busco al jugador que quiero agregar a la partida
    Jugador *jugador = dyamica_cast<Jugador *> (fabrica->getInterfaceU()->BuscarUsuario(nickname));
    if(jugador){
        // creo un tipo de dato JugadorMultijugador y asocio a ese jugador buscado antes
        JugadorMultijugador* jugadorDeLaPartida = new JugadorMultijugador(jugador);

        // Agregar el puntero del jugadorMultijugador a la lista de jugadores que tiene esta partida multijugador
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
                        // agrego la partida multijugador a la coleccion para que despues se muestre
                        listadepartidasMulti->add(multijugador, new KeyString(to_string(idpartida)));
                    }

                }
            }
            it->next();
        }
    }else{
        throw std::invalid_argument("Usted no es un Jugador");
    }
    return listadepartidasMulti; // retorno una coleccion de partidas Multijugador
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
                    DT_Time* horafinal = new DT_Time();
                    jugadorUnido->setHoraFinalizacion(horafinal);
                }
                it->next();
            }
        }else{
            throw std::invalid_argument("Usted no es un Jugador");
        }
    }
}
IDictionary* PartidaController::listarPartidasIniciadasNoFinalizadas(){

    Factory* fabrica;
    IIterator *it = this->partidas->getIteratorObj();
    Partida *partida = NULL;
    IDictionary* listadepartidasSinFinalizar = new ListDicc();
    Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInterfaceU()->getUsuarioLogeado());
    if(jugadorlogeado){
        while(it->hasNext()) {
            partida = dynamic_cast<Partida *>(it->getCurrent());
            if (partida) {
                if ((partida->getJugador()->getNickname() == jugadorlogeado->getNickname()) &&
                    (!partida->getFinalizada())) {
                    listadepartidasSinFinalizar->add(partida, new KeyString(to_string(partida->getIdPartida())));
                }
            }
            it->next();
        }
    }
    return listadepartidasSinFinalizar; // retorno una coleccion de partidas
}
void PartidaController::confirmarFinalizarPartida(int idPartida){
    // buscar la partida
    Factory* fabrica;
    IIterator *it = this->partidas->getIteratorObj();
    Partida *partida = NULL;

    Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInterfaceU()->getUsuarioLogeado());
    if(jugadorlogeado){
        KeyString* idpartida = new KeyString(to_string(idPartida));
        partida = dynamic_cast<Partida *>(this->partidas->find(idpartida));
        Multijugador* multijugador = NULL;
        if(partida){
            DT_Date *fechaFin = new DT_Date();
            partida->setFechaFin(*fechaFin);
            DT_Time *horaFin = new DT_Time();
            partida->setHoraFin(*horaFin);
            partida->setFinalizada(true);
            // Falta calcular la hora de duración de la partida:
            /*
            if (partida->getFecha().getDate() == fechaFin->getDate()){
                double horacomienzo;
                string horacom = partida->getHoraComienzo().getTime();
                horacomienzo = stod(horacom);
                        //double num_double = std::stod(str);
            }*/
            multijugador = dynamic_cast<Multijugador *>(partida);
        }
        if (multijugador){
            IIterator *it2 = multijugador->getJugadoresEnLaPartida()->getIteratorObj();
            while(it2->hasNext()) {
                JugadorMultijugador *jm = dynamic_cast<JugadorMultijugador *>(it2->getCurrent());
                if (jm) {
                    if (jm->getHora_finalizacion() == NULL){ // Si el jugador aun no tiene hora de finalizacion se le setea porque el jugadorIniciador va a abandonar la partida
                        DT_Time *horaFinalJugador = new DT_Time();
                        jm->setHoraFinalizacion(horaFinalJugador);
                    }
                }
                it2->next();
            }
        }

    }
}
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
