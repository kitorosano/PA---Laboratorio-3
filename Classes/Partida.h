//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_PARTIDA_H
#define PA___LABORATORIO_3_PARTIDA_H

#include "string"
#include <iostream>
using namespace std;

class Partida {
private:
    string idPartida;
    DT_Date fecha;
    DT_Time horaComienzo;
    double horasPartida;
    // atributo que tenga el puntaje de la partida ?

public:
    Partida(string idPartida, DT_Date fecha, DT_Time horaComienzo, double horasPartida);

    void setIdPartida(string idPartida);
    void setFecha(DT_Date fecha);
    void setHoraComienzo(DT_Time horaCominezo);
    void setHorasPartida(double horasPartida);

    string getIdPartida();
    DT_Date getFecha();
    DT_Time getHoraComienzo();
    double getHorasPartida();

};


#endif //PA___LABORATORIO_3_PARTIDA_H
