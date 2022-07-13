//
// Created by Davila on 21/6/2022.
//

#include "PartidaController.h"
#include "/Classes/Multijugador.h"
#include "DataTypes/DT_MultijugadorVideojuego.h"
#include "DataTypes/DT_Comentario.h"
#include "/Factory/Factory.h"
using namespace std;

PartidaController* PartidaController::instance = NULL;

PartidaController::PartidaController() {
    partidas = vector<Partida *>();
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

void PartidaController::continuarPartidaIndividual(string idPartida){
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


    VideojuegoController* videojuegoController;
    Videojuego* videojuegoSeleccionado = videojuegoController->getInstance()->getVideojuegoSeleccionado();


     // Obtener el usuario logeado!! Necesito que el getUsuarioLogeado() Devuelva un puntero
    UsuarioController* usuarioController;
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(usuarioController->getInstance()->getUsuarioLogeado());

    Individual* nuevaPartidaIndividual = new Individual(jugadorlogeado, videojuegoSeleccionado);
    this->partidaSeleccionada = nuevaPartidaIndividual; // el controlador recuerda la partida


}

void PartidaController::nuevaPartidaMultijugador(bool transmitidaEnVivo){



    // Obtener el videojuego que se selecciona, mas arriba en el caso de uso Iniciar partida
    VideojuegoController* videojuegoController;
    Videojuego* videojuegoSeleccionado = videojuegoController->getInstance()->getVideojuegoSeleccionado();


    // Obtener el usuario logeado!! Necesito que el getUsuarioLogeado() Devuelva un puntero
    UsuarioController* usuarioController;
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(usuarioController->getInstance()->getUsuarioLogeado());


    Multijugador* nuevaPartidaMulti = new Multijugador(jugadorlogeado, videojuegoSeleccionado, transmitidaEnVivo);
    this->partidaSeleccionada = nuevaPartidaMulti; // el controlador recuerda la partida


}

void PartidaController::ingresarNicknameALaPartida(string nickname){


    UsuarioController* usuarioController;
    Jugador *jugadorDeLaPartida = dyamica_cast<Jugador * > (usuarioController->getInstance()->BuscarUsuario(nickname));


    // Agregar el puntero del jugador a la lista de jugadores que tiene esta partida multijugador
    Multijugador *multi = dynamic_cast<Multijugador *>(partidaSeleccionada);
    multi->unirNicknameAPartida(jugadorDeLaPartida);
    this->partidaSeleccionada = multi; // El controlador recurda la partida
    */
}

void PartidaController::confirmarPartida(){

        // Asignar la Referencia para la partida
    string idPartida = "P";
    idPartida += to_string(idpartida++);
    this->partidaSeleccionada->setIdPartida(idPartida);

    // Asignar la Fecha para la partida
    DT_Date *fecha = new DT_Date();
    this->partidaSeleccionada->setFecha(*fecha);

    // Asignar la hora de comienzo de la partida
    DT_Time *horaComienzo = new DT_Time();
    this->partidaSeleccionada->setHoraComienzo(*horaComienzo);

    // Agregar a la collecion la nueva partida;
    partidas->add(partidaSeleccionada,new KeyString(idPartida));

    // Borrar los datos que el controlador guardo
    this->partidaSeleccionada = NULL;

}

IDictionary* PartidaController::listarPartidasMultijugadorUnidasNoFinalizadasEnVivo(){

}

void PartidaController::confirmarAbandonoPartida(string idPartida){}

vector<Multijugador*> PartidaController::listarPartidasIniciadasNoFinalizadas(){}

void PartidaController::confirmarFinalizarPartida(string idPartida){}


IDictionary* PartidaController::listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(){
    IIterator *it = this->partidas->getIteratorObj();
    Multijugador *partida = NULL;
    IDictionary* listadepartidas_multijugador = new ListDicc();
    while(it->hasNext()){
        partida = dynamic_cast<Multijugador *>(it->getCurrent());
        if(partida){
            if((partida->getFinalizada()==false && partida->isTransmitidaEnVivo()==true)){
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
            DT_Date fechaRespuesta = DT_Date();
            DT_Time horaRespuesta = DT_Time();
            this->nuevoComentario= new Comentario(usuario_logueado,fechaRespuesta,horaRespuesta,contenido,this->comentarioAResponder);
            this->comentarioAResponder=NULL;
        }
        else{
            //envio
            DT_Date fechaEnvio = DT_Date();
            DT_Time horaEnvio = DT_Time();
            this->nuevoComentario= new Comentario(usuario_logueado,fechaEnvio,horaEnvio,contenido);
        }
    }
}

void PartidaController::confirmarComentario(){
    //aca se setea el id del comentario
    Multijugador* multijugador_recordada = dynamic_cast<Multijugador*>(this->partidaSeleccionada);
    if(multijugador_recordada && this->nuevoComentario){
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


    // Obtener el usuario logeado!! Necesito que el getUsuarioLogeado() Devuelva un puntero
    UsuarioController* usuarioController;
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(usuarioController->getInstance()->getUsuarioLogeado());


    // Comparar el usuario por cada partida y tamibien si es finalizada
    IIterator *it = this->partidas->getIteratorObj();
    Individual *partida = NULL;
    IDictionary* listadepartidas = new ListDicc();
    while(it->hasNext()){
        partida = dynamic_cast<Individual *>(it->getCurrent());
        if(partida){
            if((partida->getJugador()->getNickname() == jugadorlogeado->getNickname()) && (partida->getFinalizada())){
                // Guardar todo en una coleccion y retorna esa coleccion
                DT_PartidasIndividualesFinalizadas *dt_partida = new DT_PartidasIndividualesFinalizadas(partida->getIdPartida(), partida->getFecha().getDate(), partida->getHoraComienzo().getTime(), partida->getHorasPartida());
                listadepartidas->add(reinterpret_cast<ICollectible *>(dt_partida), new KeyString(dt_partida->getIdPartida()));
            }
        }
        it->next();
    }
    return listadepartidas;


}
