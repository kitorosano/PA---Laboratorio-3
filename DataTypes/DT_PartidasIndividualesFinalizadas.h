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
    string idPartida;
    string fecha;
    string horaComienzo;
    double horasPartida;
public:
    DT_PartidasIndividualesFinalizadas(string idPartida, string fecha, string horaComienzo, double horasPartida);

    string getIdPartida();
    string getFecha();
    string getHoraComienzo();
    double getHorasPartida();



};
/*class DT_NomDescVideojuego {
private:
    string nombre;
    string descripcion;
public:
    DT_NomDescVideojuego(string nombre, string descripcion);
    string getNombre();
    string getDescripcion();
};*/

#endif //MAIN_CPP_DT_PARTIDASINDIVIDUALESFINALIZADAS_H
