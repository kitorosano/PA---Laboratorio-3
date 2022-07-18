//
// Created by Davila on 12/7/2022.
//

#ifndef MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
#define MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
#include "DataTypes/DT_Fecha.h"
#include "string"
#include <iostream>
#include "ColeccionesG/ICollectible.h"

using namespace std;

class DT_PartidasIndividualesFinalizadas : public ICollectible {
private:
    int idPartida;
    DT_Fecha* fechaComienzo;
    int horasPartida;
public:
    DT_PartidasIndividualesFinalizadas(int idPartida, DT_Fecha* fecha, int horasPartida);

    int getIdPartida();
    DT_Fecha* getFechaComienzo();
    int getHorasPartida();

    string toString();
};


#endif //MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
