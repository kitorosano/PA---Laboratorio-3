//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_SUSCRIPCION_H
#define PA___LABORATORIO_3_SUSCRIPCION_H


class Suscripcion {
private:
    double costo;
    bool activo;
    DatosSuscripcion datos_suscripcion;

public:
    Suscripcion(double costo, bool activo);
    virtual ~Suscripcion();

    double getCosto();
    bool getActivo();

    void setCosto(double costo);
    void setActivo(bool activo);

};

#endif //PA___LABORATORIO_3_SUSCRIPCION_H
