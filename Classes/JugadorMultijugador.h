//
// Created by Davila on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H
#define PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H

#include "string"
#include <iostream>
#include "Classes/Jugador.h"

class JugadorMultijugador {
private:
    DT_TIME hora_finalizacion;
    Jugador* jugador;

public:
    JugadorMultijugador(DT_TIME hora_finalizacion, Jugador* jugador);
};


#endif //PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H
