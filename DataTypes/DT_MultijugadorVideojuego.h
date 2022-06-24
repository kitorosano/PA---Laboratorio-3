//
// Created by esteban.rosano on 24/6/2022.
//

#ifndef PA___LABORATORIO_3_DT_MULTIJUGADORVIDEOJUEGO_H
#define PA___LABORATORIO_3_DT_MULTIJUGADORVIDEOJUEGO_H

#include "Classes/Jugador.h"
#include "Classes/Multijugador.h"
#include <string>
using namespace std;

class DT_MultijugadorVideojuego {
private:
    string nombreVideojuego;
    Jugador* jugadorIniciador;
    vector<Jugador*> jugadoresUnidos;
    Multijugador* multijugador;

public:
    DT_MultijugadorVideojuego(string nombreVideojuego, Jugador* jugadorIniciador, vector<Jugador*> jugadoresUnidos, Multijugador* multijugador);

    string getNombreVideojuego();
    Jugador* getJugadorIniciador();
    vector<Jugador*> getJugadoresUnidos();
    Multijugador* getMultijugador();
};


#endif //PA___LABORATORIO_3_DT_MULTIJUGADORVIDEOJUEGO_H
