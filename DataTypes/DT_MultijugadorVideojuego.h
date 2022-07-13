//
// Created by esteban.rosano on 24/6/2022.
//

#ifndef PA___LABORATORIO_3_DT_MULTIJUGADORVIDEOJUEGO_H
#define PA___LABORATORIO_3_DT_MULTIJUGADORVIDEOJUEGO_H

#include "Classes/Jugador.h"
#include "Classes/Multijugador.h"
#include <string>
using namespace std;

class DT_MultijugadorVideojuego : public ICollectible {
private:
    int idPartida;
    string nombreVideojuego;
    Jugador* jugadorIniciador;
    IDictionary* jugadoresUnidos;
    Multijugador* multijugador;

public:
    DT_MultijugadorVideojuego(int idPartida,string nombreVideojuego, Jugador* jugadorIniciador, IDictionary* jugadoresUnidos, Multijugador* multijugador);
    int getIdPartida();
    string getNombreVideojuego();
    Jugador* getJugadorIniciador();
    IDictionary* getJugadoresUnidos();
    Multijugador* getMultijugador();
};


#endif //PA___LABORATORIO_3_DT_MULTIJUGADORVIDEOJUEGO_H
