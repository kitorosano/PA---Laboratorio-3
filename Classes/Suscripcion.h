//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_SUSCRIPCION_H
#define PA___LABORATORIO_3_SUSCRIPCION_H


class Suscripcion {
private:
    int id;
    double costo;

public:
    Suscripcion(double costo);
    virtual ~Suscripcion();

    int getId();
    double getCosto();

    void setId(int id);
    void setCosto(double costo);

};

#endif //PA___LABORATORIO_3_SUSCRIPCION_H
