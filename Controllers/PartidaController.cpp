//
// Created by Davila on 21/6/2022.
//

#include "PartidaController.h"
#include "VideojuegoController.h"
#include "Classes/Multijugador.h"
#include "Interfaces/IVideojuego.h"
#include "DataTypes/DT_MultijugadorVideojuego.h"
#include "DataTypes/DT_Comentario.h"
#include "Factory/Factory.h"
using namespace std;

PartidaController* PartidaController::instance = NULL;

PartidaController::PartidaController() {
    partidas = new ListDicc();
    partidaSeleccionada = NULL;
    comentarioAResponder = NULL;
    nuevoComentario = NULL;
    idpartida = 1;
    idComentario = 1;
}

PartidaController::~PartidaController(){}

PartidaController *PartidaController::getInstance() {
    if(instance == NULL)
        instance = new PartidaController();
    return instance;
}

void PartidaController::continuarPartidaIndividual(int idPartida, Jugador* jugadorIniciador) {
//    TODO: verificar que la partida pertenece al jugadorIniciador
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

void PartidaController::nuevaPartidaIndividual(Jugador *jugadorIniciador){
    if(jugadorIniciador == NULL)
        throw std::invalid_argument("No se ha logeado ningun jugador");

    // Obtener el videojuego seleccionado!!
    Factory* fabrica;
    Videojuego* videojuegoSeleccionado = fabrica->getInstance()->getInterfaceV()->getVideojuegoSeleccionado();
    if(videojuegoSeleccionado == NULL)
        throw std::invalid_argument("No se ha seleccionado ningun videojuego");

    Individual* nuevaPartida = new Individual(jugadorIniciador,videojuegoSeleccionado);
    this->partidaSeleccionada = nuevaPartida;
}

void PartidaController::nuevaPartidaMultijugador(Jugador *jugadorIniciador, bool transmitidaEnVivo){
    if(jugadorIniciador == NULL)
        throw std::invalid_argument("No se ha logeado ningun jugador");

    // Obtener el videojuego seleccionado!!
    Factory* fabrica;
    Videojuego* videojuegoSeleccionado = fabrica->getInstance()->getInterfaceV()->getVideojuegoSeleccionado();
    if(videojuegoSeleccionado == NULL)
        throw std::invalid_argument("No se ha seleccionado ningun videojuego");

    Multijugador* nuevaPartidaMultijugador = new Multijugador(jugadorIniciador, videojuegoSeleccionado, transmitidaEnVivo);
    this->partidaSeleccionada = nuevaPartidaMultijugador; // el controlador recuerda la partida
}

void PartidaController::ingresarNicknameALaPartida(string nickname){
    Factory* fabrica;
    // Busco al jugador que quiero agregar a la partida
    IIterator *it = fabrica->getInstance()->getInterfaceU()->getUsuarios()->getIteratorObj();
    while (it->hasNext()){
        Jugador* jugador = dynamic_cast<Jugador*>(it->next());
        if(jugador && jugador->getNickname().compare(nickname) == 0){
//            TODO: verificar que el jugador no esta en la partida

            // creo un tipo de dato JugadorMultijugador y asocio a ese jugador buscado antes
            JugadorMultijugador* jugadorDeLaPartida = new JugadorMultijugador(jugador);

            // Agregar el puntero del jugadorMultijugador a la lista de jugadores que tiene esta partida multijugador
            Multijugador *multi = dynamic_cast<Multijugador *>(this->partidaSeleccionada);
            multi->unirNicknameAPartida(jugadorDeLaPartida);
            return;
        }
    }

    throw std::invalid_argument("El jugador no existe");
}

Partida* PartidaController::confirmarPartida(DT_Fecha* fecha_comienzo){
    // Indicar el ID a la partida
    int idPartida = this->idpartida++;
    this->partidaSeleccionada->setIdPartida(idPartida);

    this->partidaSeleccionada->setFechaComienzo(fecha_comienzo);

    // Agregar a la colección la nueva partida;
    partidas->add(partidaSeleccionada, new KeyInt(idPartida));

    // Borrar los datos que el controlador guardo y retornar la partida
    Partida *partida = this->partidaSeleccionada;
    this->partidaSeleccionada = NULL;
    return partida;
}

void PartidaController::cancelarIniciarPartida() {
    Factory* fabrica;
    this->partidaSeleccionada = NULL;
    fabrica->getInstance()->getInterfaceV()->setVideojuegoSeleccionado(NULL);
}

void PartidaController::confirmarAbandonoPartida(int idPartida, Jugador* jugadorAbandona, DT_Fecha* fechaFinalizacion){
    KeyInt* idpartida = new KeyInt(idPartida);
    Multijugador* partidaAAbandonar = dynamic_cast<Multijugador *>(this->partidas->find(idpartida));

    if(!partidaAAbandonar)
        throw std::invalid_argument("La partida no existe");

    IIterator *it = partidaAAbandonar->getJugadoresEnLaPartida()->getIteratorObj();
    while(it->hasNext()){
        JugadorMultijugador *jm = dynamic_cast<JugadorMultijugador *>(it->getCurrent());
        if(jm->getJugador() == jugadorAbandona){
            partidaAAbandonar->nicknameAbandonaPartida(jugadorAbandona->getNickname());
            jm->setFechaFinalizacion(fechaFinalizacion);
            break;
        }
        it->next();
    }
    delete it;

//    TODO: verificar que si todos los jugadores abandonaron se finalice la partida
}

void PartidaController::confirmarFinalizarPartida(int idPartida, Jugador* jugadorIniciador, DT_Fecha* fechaFinalizacion){
    // buscar la partida
    Factory* fabrica;
    IIterator *it = this->partidas->getIteratorObj();
    Partida *partida = NULL;
    Multijugador* multijugador = NULL;

    KeyInt* idpartida = new KeyInt(idPartida);
    partida = dynamic_cast<Partida *>(this->partidas->find(idpartida));

    if(!partida)
        throw std::invalid_argument("No se encontro la partida");

    partida->finalizarPartida(fechaFinalizacion);

    multijugador = dynamic_cast<Multijugador *>(partida);
    if (multijugador){
        IIterator *it = multijugador->getJugadoresEnLaPartida()->getIteratorObj();
        while(it->hasNext()) {
            JugadorMultijugador *jm = dynamic_cast<JugadorMultijugador *>(it->next());
            this->confirmarAbandonoPartida(idPartida, jm->getJugador(), fechaFinalizacion);
        }
        delete it;
    }
}

void PartidaController::seleccionarPartida(int idPartida){
    KeyInt* key_idPartida = new KeyInt(idPartida);
    Multijugador* partida;
    Partida* aux = (Partida *) (this->partidas->find(key_idPartida));
    this->partidaSeleccionada=aux;
}

IDictionary* PartidaController::listarComentariosDePartida(){
    IDictionary* comentarios_multijugador = NULL;
    Multijugador* multijugador_recordada = dynamic_cast<Multijugador*>(this->partidaSeleccionada);
    if(multijugador_recordada){
        comentarios_multijugador=multijugador_recordada->obtenerComentariosDePartida();
        return comentarios_multijugador;
    }
    return NULL;
}

void PartidaController::seleccionarComentarioAResponder(int idComentario){
    Multijugador* multijugador_recordada = dynamic_cast<Multijugador*>(this->partidaSeleccionada);
    if(multijugador_recordada){
       if(multijugador_recordada->obtenerComentario(idComentario)){
           this->comentarioAResponder=multijugador_recordada->obtenerComentario(idComentario);
       }
    }
}

void PartidaController::enviarComentario(string contenido){
    Factory* factory;
    string autor;
    Usuario* usuario_logueado= factory->getInstance()->getInterfaceU()->getUsuarioLogeado();
    Jugador* jugador = dynamic_cast<Jugador*>(usuario_logueado);
    if(jugador){
        if(this->comentarioAResponder){
            //respuesta
            DT_Fecha* fechaRespuesta =new DT_Fecha();
            this->nuevoComentario= new Comentario(jugador,fechaRespuesta,contenido,this->comentarioAResponder);
            this->comentarioAResponder=NULL;
        }
        else{
            //envio
            DT_Fecha* fechaEnvio = new DT_Fecha();
            this->nuevoComentario= new Comentario(jugador,fechaEnvio,contenido);
        }
    }
}

void PartidaController::confirmarComentario(){
    //aca se setea el id del comentario
    Multijugador* multijugador_recordada = dynamic_cast<Multijugador*>(this->partidaSeleccionada);
    if(multijugador_recordada && this->nuevoComentario){
        nuevoComentario->setIdComentario(this->idComentario++); //TODO: Utilizar contador en el controlador
        multijugador_recordada->agregarComentario(this->nuevoComentario);
        this->nuevoComentario=NULL;
    }
}

void PartidaController::cancelarComentario(){
    //aca se setea el id del comentario
    if(this->nuevoComentario){
        delete nuevoComentario;
        nuevoComentario=NULL;
    }
}

IDictionary* PartidaController::listarHistorialPartidasFinalizadasCronologicamente(){
    // Obtener el usuario logeado!!
    Factory* fabrica;
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());

    // Comparar si el usuario jugador le pertenece la partida y si es finalizada
    IIterator *it = this->partidas->getIteratorObj();
    Individual *partida = NULL;
    IDictionary* listadepartidas = new ListDicc();
    while(it->hasNext()){
        partida = dynamic_cast<Individual *>(it->getCurrent());
        if(partida){
            if((partida->getJugador()->getNickname() == jugadorlogeado->getNickname()) && (partida->isFinalizada())){
                // Guardar todo en una coleccion y retorna esa coleccion
                DT_PartidasIndividualesFinalizadas *dt_partida = new DT_PartidasIndividualesFinalizadas(partida->getIdPartida(), partida->getFechaComienzo(), partida->getHorasPartida());
                listadepartidas->add(reinterpret_cast<ICollectible *>(dt_partida), new KeyInt(dt_partida->getIdPartida()));
            }
        }
        it->next();
    }
    return listadepartidas;
}
IDictionary* PartidaController::listarPartidasIniciadasNoFinalizadas(){

    Factory* fabrica;
    IIterator *it = this->partidas->getIteratorObj();
    Partida *partida = NULL;
    IDictionary* listadepartidasSinFinalizar = new ListDicc();
    Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());
    if(jugadorlogeado){
        while(it->hasNext()) {
            partida = dynamic_cast<Partida *>(it->getCurrent());
            if (partida) {
                if ((partida->getJugador()->getNickname() == jugadorlogeado->getNickname()) &&
                    (!partida->isFinalizada())) {
                    listadepartidasSinFinalizar->add(partida, new KeyInt(partida->getIdPartida()));
                }
            }
            it->next();
        }
    }
    return listadepartidasSinFinalizar; // retorno una coleccion de partidas
}

IDictionary* PartidaController::listarPartidasMultijugadorUnidasNoFinalizadas(){
    Factory* fabrica;
    IIterator *it = this->partidas->getIteratorObj();
    Multijugador *multijugador = NULL;
    IDictionary* listadepartidasMulti = new ListDicc();
    Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());
    if(jugadorlogeado){
        while(it->hasNext()){
            multijugador = dynamic_cast<Multijugador *>(it->getCurrent());
            if(multijugador) {
                // verificar que no este finalizado
                // obtener la lista de jugadores de esa partida multijugador y verificar si el nickanme del jugador logeado esta alli
                KeyString *nickName = new KeyString(jugadorlogeado->getNickname());
                if ((multijugador->isFinalizada() == false) &&
                    (multijugador->getJugadoresEnLaPartida()->member(nickName))) {
                    // verificar si ese usuario ya abandono esa partida mirando el atributo hora finalizacion si tiene un horario o esta ne NULL
                    JugadorMultijugador* jugadorMultijugador = dynamic_cast<JugadorMultijugador *>(multijugador->getJugadoresEnLaPartida()->find(
                            nickName));
                    if (jugadorMultijugador->getFechaFinalizacion() == NULL){
                        // agrego la partida multijugador a la coleccion para que despues se muestre
                        listadepartidasMulti->add(multijugador, new KeyInt(idpartida));
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

IDictionary* PartidaController::listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(){
    IIterator *it = this->partidas->getIteratorObj();
    Multijugador *partida = NULL;
    IDictionary* listadepartidas_multijugador = new ListDicc();
    while(it->hasNext()){
        partida = dynamic_cast<Multijugador *>(it->getCurrent());
        if(partida){
            if((partida->isFinalizada() == false && ( (partida->isTransmitidaEnVivo() == true)||(partida->isTransmitidaEnVivo() == 240)))){
                // Guardar todo en una coleccion y retorna esa coleccion
                //DT_MultijugadorVideojuego(int idPartida,string nombreVideojuego, Jugador* jugadorIniciador, IDictionary* jugadoresUnidos, Multijugador* multijugador);
                DT_MultijugadorVideojuego *dt_partida = new DT_MultijugadorVideojuego(partida->getIdPartida(),partida->getVideojuego()->getNombre(),partida->getJugador(),partida->getJugadoresEnLaPartida(),partida);
                listadepartidas_multijugador->add(dt_partida, new KeyInt(partida->getIdPartida()));
            }
        }
        it->next();
    }
    return listadepartidas_multijugador;
} // lugar 1
// lugar 1
