//
// Created by Davila on 21/6/2022.
//

#include "Individual.h"

Individual::Individual(string idPartida, DT_Date fecha, DT_Time horaComienzo, double horasPartida, Jugador *jugador,
                       Videojuego *videojuego, Individual *partidaAContinuar) : Partida(idPartida, fecha, horaComienzo, horasPartida, jugador, videojuego) {
    this->partidaAContinuar = partidaAContinuar;
}

Individual *Individual::getContPartAnterior() {
    return this->partidaAContinuar;
}

void Individual::setContPartAnterior(Individual* partidaAContinuar) {
    this->partidaAContinuar = partidaAContinuar;
}





