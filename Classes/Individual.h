//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_INDIVIDUAL_H
#define PA___LABORATORIO_3_INDIVIDUAL_H

#include "Classes/Partida.h"

class Individual : public Partida {
private:
    Individual* partidaAContinuar;

public:
    Individual();
    Individual(Jugador* jugador, Videojuego* videojuego);
    Individual(Jugador* jugador, Videojuego* videojuego, Individual* partidaAContinuar);
    virtual ~Individual();

    Individual* getContPartAnterior();
    void setContPartAnterior(Individual* partidaAContinuar);

    string toString();
};


#endif //PA___LABORATORIO_3_INDIVIDUAL_H
