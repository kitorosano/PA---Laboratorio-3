//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_MULTIJUGADOR_H
#define PA___LABORATORIO_3_MULTIJUGADOR_H

#include "Classes/Partida.h"
#include "Classes/JugadorMultijugador.h"
#include "Classes/Comentario.h"
#include "DataTypes/DT_Comentario.h"
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "ColeccionesG/KeyString.h"

class Multijugador : public Partida {
private:
    bool transmitidaEnVivo;
    double duracionTotal; // Creo que es lo mismo que el atributo de horasPartida en Partida.h
    IDictionary* jugadoresEnLaPartida; // Lista de JugadorMultijugador
    IDictionary* comentarios;

public:
    Multijugador();
    Multijugador(Jugador* jugador, Videojuego* videojuego, bool transmitidaEnVivo);
    ~Multijugador();

    bool isTransmitidaEnVivo();
    double getDuracionTotal();
    IDictionary* getJugadoresEnLaPartida();
    IDictionary* obtenerComentariosDePartida();
    Comentario* obtenerComentario(int idComentario);

    void setIsTransmitidaEnVivo(bool transmitidaEnVivo);
    void setDuracionTotal(double duracionTotal);
    void unirNicknameAPartida(JugadorMultijugador* jugadorMultijugador);
    void nicknameAbandonaPartida(string nickname);
    void agregarComentario(Comentario* comentario);


    string toString();
};

#endif //PA___LABORATORIO_3_MULTIJUGADOR_H
