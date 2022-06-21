//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_SUSCRIPCION_H
#define PA___LABORATORIO_3_SUSCRIPCION_H

#include "DatosSuscripcion.h"

class Suscripcion {
private:
    int id;
    double costo;
    bool activo;
    DatosSuscripcion datos_suscripcion;

public:
    Suscripcion();
    virtual ~Suscripcion();

    int getId();
    double getCosto();
    bool getActivo();

    void setId(int id);
    void setCosto(double costo);
    void setActivo(bool activo);

};

#endif //PA___LABORATORIO_3_SUSCRIPCION_H
