//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_INDIVIDUAL_H
#define PA___LABORATORIO_3_INDIVIDUAL_H

#include "Classes/Partida.h"

class Individual : public Partida{
private:
    bool contPartAnterior;

public:
    Individual(string idPartida, DT_Date fecha, DT_Time horaComienzo, double horasPartida, bool contPartAnterior);

    void setContPartAnterior(bool contPartAnterior);
    bool getContPartAnterior();

};


#endif //PA___LABORATORIO_3_INDIVIDUAL_H
