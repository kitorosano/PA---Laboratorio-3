//
// Created by Davila on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H
#define PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H

#include "string"
#include <iostream>
#include "Classes/Jugador.h"
#include "DataTypes/DT_Time.h"

class JugadorMultijugador {
private:
    DT_Time hora_finalizacion;
    Jugador* jugador;

public:
    JugadorMultijugador(Jugador* jugador);

    void setHoraFinalizacion(DT_Time hora_finalizacion);
};


#endif //PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H
