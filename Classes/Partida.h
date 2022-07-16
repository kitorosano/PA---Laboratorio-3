//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_PARTIDA_H
#define PA___LABORATORIO_3_PARTIDA_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "Classes/Jugador.h"
#include "Classes/Videojuego.h"
#include "DataTypes/DT_Fecha.h"
#include "string"
#include <iostream>

using namespace std;

class Partida: public ICollectible {
private:
    int idPartida;
    Jugador* jugador;
    Videojuego* videojuego;
    DT_Fecha* fechaComienzo;
    DT_Fecha* fechaFin;
    int horasPartida;
    bool finalizada;

public:
    Partida();
    Partida(Jugador* jugador, Videojuego* videojuego);
    virtual ~Partida();

    int getIdPartida();
    Videojuego* getVideojuego();
    Jugador* getJugador();
    DT_Fecha* getFechaComienzo();
    DT_Fecha* getFechaFin();
    int getHorasPartida();
    bool isFinalizada();

    void setIdPartida(int idpartida);
    void setJugador(Jugador* jugador);
    void setVideojuego(Videojuego* videojuego);
    void setFechaComienzo(DT_Fecha* fecha);
    void finalizarPartida(DT_Fecha* fechaFin);

    string toString();
};


#endif //PA___LABORATORIO_3_PARTIDA_H
