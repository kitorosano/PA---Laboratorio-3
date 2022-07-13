//
// Created by Davila on 21/6/2022.
//

#include "Multijugador.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/KeyInt.h"
using namespace std;

Multijugador::Multijugador() {
}

Multijugador::Multijugador(Jugador *jugador, Videojuego *videojuego, bool transmitidaEnvivo): Partida(jugador, videojuego) {
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->comentarios = new ListDicc();
}

Multijugador::~Multijugador() {
}

bool Multijugador::isTransmitidaEnVivo() {
    return this->transmitidaEnVivo;
}

double Multijugador::getDuracionTotal() {
    return this->duracionTotal;
}

void Multijugador::setIsTransmitidaEnVivo(bool transmitidaEnVivo) {
    this->transmitidaEnVivo = transmitidaEnVivo;
}

void Multijugador::setDuracionTotal(double duracionTotal) {
    this->duracionTotal = duracionTotal;
}

Comentario* Multijugador::obtenerComentario(int idComentario){
    if(this->comentarios){
        KeyInt* key_id = new KeyInt(idComentario);
        Comentario* comentario = (Comentario*) (this->comentarios->find(key_id));
        if(!comentario){
            throw invalid_argument("El comentario no existe en la partida");
            return NULL;
        }
        else{
            return comentario;
        }
    }
}

IDictionary* Multijugador::obtenerComentariosDePartida(){
    IIterator *it = this->comentarios->getIteratorObj();
    IDictionary* comentarios_multijugador = new ListDicc();
    while(it->hasNext()){
        Comentario* comentario= dynamic_cast<Comentario*>(it->getCurrent());
                DT_Comentario *dt_comentario = new DT_Comentario(comentario->getIdComentario(),comentario->getFechaEnvio(),comentario->getHoraEnvio(),comentario->getEscritor()->getNickname(),comentario->getContenido());
                comentarios_multijugador->add(dt_comentario, new KeyInt(comentario->getIdComentario()));
        it->next();
    }
    return comentarios_multijugador;
}

void Multijugador::agregarComentario(Comentario* comentario){
    this->comentarios->add(comentario,new KeyInt(comentario->getIdComentario()));
}

void Multijugador::unirNicknameAPartida(JugadorMultijugador* jugadorMultijugador) {
    this->jugadoresEnLaPartida->add(jugadorMultijugador, new KeyString(jugadorMultijugador->getJugador()->getNickname()));
    // reinterpret_cast<ICollectible *>(jugadorMultijugador)
}
