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
    Videojuego* videojuegoSeleccionado = fabrica->getInstance()->getInterfaceV()->getVideojuegoSeleccionado();

     // Obtener el usuario logeado!!
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());
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
    Videojuego* videojuegoSeleccionado = fabrica->getInstance()->getInterfaceV()->getVideojuegoSeleccionado();

    // Obtener el usuario logeado!!
    Jugador *jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());
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
    Jugador *jugador = dynamic_cast<Jugador *> (fabrica->getInstance()->getInterfaceU()->buscarUsuario(nickname));
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
    partidas->add(partidaSeleccionada, new KeyInt(idPartida));

    // Borrar los datos que el controlador guardo
    this->partidaSeleccionada = NULL;

}

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
            this->nuevoComentario= new Comentario(jugador,fechaRespuesta,horaRespuesta,contenido,this->comentarioAResponder);
            this->comentarioAResponder=NULL;
        }
        else{
            //envio
            DT_Date fechaEnvio = DT_Date();
            DT_Time horaEnvio = DT_Time();
            this->nuevoComentario= new Comentario(jugador,fechaEnvio,horaEnvio,contenido);
        }
    }
}

void PartidaController::confirmarComentario(){
    //aca se setea el id del comentario
    Multijugador* multijugador_recordada = dynamic_cast<Multijugador*>(this->partidaSeleccionada);
    if(multijugador_recordada && this->nuevoComentario){
        nuevoComentario->setIdComentario(1); //TODO: Utilizar contador en el controlador
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
                if ((multijugador->getFinalizada() == false) &&
                    (multijugador->getJugadoresEnLaPartida()->member(nickName))) {
                    // verificar si ese usuario ya abandono esa partida mirando el atributo hora finalizacion si tiene un horario o esta ne NULL
                    JugadorMultijugador* jugadorMultijugador = dynamic_cast<JugadorMultijugador *>(multijugador->getJugadoresEnLaPartida()->find(
                            nickName));
                    if (jugadorMultijugador->getHora_finalizacion() == NULL){
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

void PartidaController::confirmarAbandonoPartida(int idPartida){
    KeyInt* idpartida = new KeyInt(idPartida);
    Multijugador* partidaAAbandonar = dynamic_cast<Multijugador *>(this->partidas->find(idpartida));
    JugadorMultijugador *jugadorUnido = NULL;
    if(partidaAAbandonar){
        Factory* fabrica;
        Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());
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
    Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());
    if(jugadorlogeado){
        while(it->hasNext()) {
            partida = dynamic_cast<Partida *>(it->getCurrent());
            if (partida) {
                if ((partida->getJugador()->getNickname() == jugadorlogeado->getNickname()) &&
                    (!partida->getFinalizada())) {
                    listadepartidasSinFinalizar->add(partida, new KeyInt(partida->getIdPartida()));
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

    Jugador* jugadorlogeado = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());
    if(jugadorlogeado){
        KeyInt* idpartida = new KeyInt(idPartida);
        partida = dynamic_cast<Partida *>(this->partidas->find(idpartida));
        Multijugador* multijugador = NULL;
        if(partida){
           //VER SI ES POSIBLE MOVER ESTO COMO UN METODO DE UTILIDAD PARA NO SOBRECARGAR ESTE METODO DEL CONTROLADOR??
        
            DT_Date *fechaFin = new DT_Date();
            partida->setFechaFin(*fechaFin);
            DT_Time *horaFin = new DT_Time();
            partida->setHoraFin(*horaFin);
            partida->setFinalizada(true);

            // calcular la hora de duración de la partida:
            string valor;

            // Separar en partes la Fecha y hora de Comienzo
            string fechacom = partida->getFecha().getDate();
            int valoresFechacom[3];
            stringstream input_stringstream(fechacom);
            for(int i = 0; getline(input_stringstream, valor, '-'); i++){
                // convertir a int cada parte
                valoresFechacom[i] = stoi(valor);
            }

            string horacom = partida->getHoraComienzo().getTime();
            int valoresHoracom[3];
            stringstream input_stringstream2(horacom);
            for(int i = 0; getline(input_stringstream2, valor, ':'); i++){
                // convertir a int cada parte
                valoresHoracom[i] = stoi(valor);
            }


            // Separar en partes la Fecha y hora de Finalización
            cout<<"----------------------------- FIN"<<endl;
            string fechafin = partida->getFechaFin().getDate();
            int valoresFechafin[3];
            stringstream input_stringstream3(fechafin);
            for(int i = 0; getline(input_stringstream3, valor, '-'); i++){
                // convertir a int cada parte
                valoresFechafin[i] = stoi(valor);
            }


            string horafin = partida->getHoraFin().getTime();
            int valoresHorafin[3];
            stringstream input_stringstream4(horafin);
            for(int i = 0; getline(input_stringstream4, valor, ':'); i++){
                // convertir a int cada parte
                valoresHorafin[i] = stoi(valor);
            }

            // Restar el tiempo de comienzo con el tiempo de Finalizacion con la funcion difftime()
            time_t now;
            struct tm comienzo;
            struct tm fin;
            double seconds;
            time(&now);  // get current time; same as: now = time(NULL)
            comienzo = *localtime(&now);
            fin = *localtime(&now);
            // fechaComienzo de la partida
            comienzo.tm_hour = valoresHoracom[0];
            comienzo.tm_min = valoresHoracom[1];
            comienzo.tm_sec = valoresHoracom[2];
            comienzo.tm_mday = valoresFechacom[0]; // itn - day of the month	1-31
            comienzo.tm_mon = valoresFechacom[1]-1;  // int - months since January	0-11

            // fechafinal de la partida
            fin.tm_hour = valoresHorafin[0];
            fin.tm_min = valoresHorafin[1];
            fin.tm_sec = valoresHorafin[2];
            fin.tm_mday = valoresFechafin[0]; // itn - day of the month	1-31
            fin.tm_mon = valoresFechafin[1]-1;  // int - months since January	0-11

            seconds = difftime(mktime(&fin),mktime(&comienzo));
            double totalhorasJugadas = seconds/3600;
            //cout<<"Horas jugadas: "<<totalhorasJugadas<<endl;
            partida->setHorasPartida(totalhorasJugadas);

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
            if((partida->getJugador()->getNickname() == jugadorlogeado->getNickname()) && (partida->getFinalizada())){
                // Guardar todo en una coleccion y retorna esa coleccion
                DT_PartidasIndividualesFinalizadas *dt_partida = new DT_PartidasIndividualesFinalizadas(partida->getIdPartida(), partida->getFecha().getDate(), partida->getHoraComienzo().getTime(), partida->getHorasPartida());
                listadepartidas->add(reinterpret_cast<ICollectible *>(dt_partida), new KeyInt(dt_partida->getIdPartida()));
            }
        }
        it->next();
    }
    return listadepartidas;
}

void PartidaController::cancelarIniciarPartida() {
    Factory* fabrica;
    this->partidaSeleccionada = NULL;
    fabrica->getInterfaceV()->setVideojuegoSeleccionado(NULL);
    // setear a NULL tambien el videoJuegoSeleccionado que es la variable que esta en el controladorVideoJuego
}
// lugar 1
