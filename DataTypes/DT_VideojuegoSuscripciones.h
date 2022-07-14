//
// Created by esteban.rosano on 14/7/2022.
//

#ifndef MAIN_CPP_DT_VIDEOJUEGOSUSCRIPCIONES_H
#define MAIN_CPP_DT_VIDEOJUEGOSUSCRIPCIONES_H
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include <string>

class DT_VideojuegoSuscripciones: public ICollectible {
private:
    string nombre;
    double costoMensual;
    double costoTrimestral;
    double costoAnual;
    double costoVitalicia;

public:
    DT_VideojuegoSuscripciones();
    DT_VideojuegoSuscripciones(string nombre, double costoMensual, double costoTrimestral, double costoAnual, double costoVitalicia);

    string getNombre();
    void setNombre(string nombre);

    double getCostoMensual();
    void setCostoMensual(double costoMensual);

    double getCostoTrimestral();
    void setCostoTrimestral(double costoTrimestral);

    double getCostoAnual();
    void setCostoAnual(double costoAnual);

    double getCostoVitalicia();
    void setCostoVitalicia(double costoVitalicia);

    string toString();
};


#endif //MAIN_CPP_DT_VIDEOJUEGOSUSCRIPCIONES_H
