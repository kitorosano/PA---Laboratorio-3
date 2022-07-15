//
// Created by Davila on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H
#define PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "Classes/Jugador.h"
#include <string>
#include <iostream>
#include "DataTypes/DT_Fecha.h"

class JugadorMultijugador: public ICollectible {
private:
    Jugador* jugador;
    DT_Fecha* fecha_finalizacion;

public:
    JugadorMultijugador();
    JugadorMultijugador(Jugador* jugador);
    ~JugadorMultijugador();

    Jugador* getJugador();
    DT_Fecha* getFechaFinalizacion();
    void setFechaFinalizacion(DT_Fecha* fecha_finalizacion);
};


#endif //PA___LABORATORIO_3_JUGADORMULTIJUGADOR_H
