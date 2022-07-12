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
#include "DataTypes/DT_Date.h"
#include "DataTypes/DT_Time.h"
#include "string"
#include <iostream>

using namespace std;

class Partida: public ICollectible {
private:
    string idPartida;
    Jugador* jugador;
    Videojuego* videojuego;
    DT_Date fecha;
    DT_Time horaComienzo;
    double horasPartida;
    DT_Date fechaFin; //NUEVO, preguntar?
    DT_Time horaFin; // NUEVO, preguntar?
    bool finalizada; // NUEVO, preguntar?

public:
    Partida();
    Partida(Jugador* jugador, Videojuego* videojuego);
    virtual ~Partida();

    string getIdPartida();
    Videojuego* getVideojuego();
    DT_Date getFecha();
    DT_Time getHoraComienzo();
    double getHorasPartida();
    Jugador* getJugador();
    DT_Date getFechaFin(); //NUEVO, preguntar?
    DT_Time getHoraFin(); // NUEVO, preguntar?
    bool getFinalizada(); // NUEVO, preguntar?


    void setJugador(Jugador* jugador);
    void setVideojuego(Videojuego* videojuego);
    void setFecha(DT_Date fecha);
    void setHoraComienzo(DT_Time horaCominezo);
    void setHorasPartida(double horasPartida);
    void setIdPartida(string idpartida);
    void setFechaFin(DT_Date getFechaFin); //NUEVO, preguntar?
    void setHoraFin(DT_Time getHoraFin); // NUEVO, preguntar?
    void setFinalizada(bool getFinalizada); // NUEVO, preguntar?

    string toString();
};


#endif //PA___LABORATORIO_3_PARTIDA_H
