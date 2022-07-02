//
// Created by esteban.rosano on 1/7/2022.
//

#ifndef PA___LABORATORIO_3_VIDEOJUEGOJUGADOR_H
#define PA___LABORATORIO_3_VIDEOJUEGOJUGADOR_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "Jugador.h"
#include "Videojuego.h"

class VideojuegoJugador: public ICollectible {
private:
    Jugador* jugador;
    Videojuego* videojuego;
    int puntaje;

public:
    VideojuegoJugador(Jugador* jugador, Videojuego* videojuego, int puntaje);
    ~VideojuegoJugador();

    Jugador* getJugador();
    Videojuego* getVideojuego();

    int getPuntaje();
    void setPuntaje(int puntaje);
};


#endif //PA___LABORATORIO_3_VIDEOJUEGOJUGADOR_H
