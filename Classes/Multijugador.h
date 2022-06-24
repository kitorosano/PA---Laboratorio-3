//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_MULTIJUGADOR_H
#define PA___LABORATORIO_3_MULTIJUGADOR_H

#include "Classes/Partida.h"
#include "Classes/JugadorMultijugador.h"
#include "Classes/Comentario.h"

class Multijugador : public Partida {
private:
    bool transmitidaEnVivo;
    double dur_total;
    vector<JugadorMultijugador> jugadoresEnLaPartida;
    vector<Comentario> comentarios;

public:

};

#endif //PA___LABORATORIO_3_MULTIJUGADOR_H
