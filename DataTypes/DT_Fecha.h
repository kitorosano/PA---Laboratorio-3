//
// Created by esteban.rosano on 15/7/2022.
//

#ifndef MAIN_CPP_DT_FECHA_H
#define MAIN_CPP_DT_FECHA_H
#include <string>
#include <time.h>
using namespace std;

class DT_Fecha {
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;

    time_t datetime;

public:
    DT_Fecha();
    DT_Fecha(int dia, int mes, int anio, int hora, int minuto, int segundo);
    ~DT_Fecha();

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();
    int getSegundo();
    time_t getDatetime();

    int getDiferenciaEnSegundos(DT_Fecha* fecha);
    int getDiferenciaEnMinutos(DT_Fecha* fecha);
    int getDiferenciaEnHoras(DT_Fecha* fecha);

    string toString();
};


#endif //MAIN_CPP_DT_FECHA_H
