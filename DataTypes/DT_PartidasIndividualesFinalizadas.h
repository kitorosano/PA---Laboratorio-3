//
// Created by Davila on 12/7/2022.
//

#ifndef MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
#define MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
#include "DataTypes/DT_Fecha.h"
#include "string"
#include <iostream>

using namespace std;

class DT_PartidasIndividualesFinalizadas {
private:
    int idPartida;
    DT_Fecha* fechaComienzo;
    double horasPartida;
public:
    DT_PartidasIndividualesFinalizadas(int idPartida, DT_Fecha* fecha, double horasPartida);

    int getIdPartida();
    DT_Fecha* getFechaComienzo();
    double getHorasPartida();

    string toString();
};


#endif //MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
