//
// Created by Davila on 12/7/2022.
//

#ifndef MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
#define MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
#include "DT_Date.h"
#include "DT_Time.h"
#include "string"
#include <iostream>

using namespace std;

class DT_PartidasIndividualesFinalizadas {
private:
    int idPartida;
    string fecha;
    string horaComienzo;
    double horasPartida;
public:
    DT_PartidasIndividualesFinalizadas(int idPartida, string fecha, string horaComienzo, double horasPartida);

    int getIdPartida();
    string getFecha();
    string getHoraComienzo();
    double getHorasPartida();
};


#endif //MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
