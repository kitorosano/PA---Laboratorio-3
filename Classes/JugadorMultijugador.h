//
// Created by Davila on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H
#define PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "Classes/Jugador.h"
#include "DataTypes/DT_Time.h"
#include <string>
#include <iostream>

class JugadorMultijugador: ICollectible {
private:
    Jugador* jugador;
    DT_Time hora_finalizacion;

public:
    JugadorMultijugador();
    JugadorMultijugador(Jugador* jugador);
    ~JugadorMultijugador();

    void setHoraFinalizacion(DT_Time hora_finalizacion);
};


#endif //PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H
