//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_PARTIDA_H
#define PA___LABORATORIO_3_PARTIDA_H

#include "string"
#include <iostream>
#include "Classes/Jugador.h"
#include "Classes/Videojuego.h"
using namespace std;

class Partida {
private:
    string idPartida;
    DT_Date fecha;
    DT_Time horaComienzo;
    double horasPartida;
    Jugador* jugador;
    Videojuego* videojuego;


public:
    Partida(string idPartida, DT_Date fecha, DT_Time horaComienzo, double horasPartida, Jugador* jugador, Videojuego* videojuego);

    string getIdPartida();
    DT_Date getFecha();
    DT_Time getHoraComienzo();
    double getHorasPartida();
    Jugador* getJugador();
    Videojuego* getVideojuego();

    void setIdPartida(string idPartida);
    void setFecha(DT_Date fecha);
    void setHoraComienzo(DT_Time horaCominezo);
    void setHorasPartida(double horasPartida);
    void setJugador(Jugador* jugador);
    void setVideojuego(Videojuego* videojuego;


};


#endif //PA___LABORATORIO_3_PARTIDA_H
