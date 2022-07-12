//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_SUSCRIPCION_H
#define PA___LABORATORIO_3_SUSCRIPCION_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "DataTypes/E_PeriodoValidez.h"
#include "Videojuego.h"
#include <string>

using namespace std;

class Suscripcion: public ICollectible {
private:
    int id;
    Videojuego* videojuego;
    E_PeriodoValidez periodoValidez;
    double costo;

public:
    Suscripcion();
    Suscripcion(Videojuego* videojuego, E_PeriodoValidez periodoValidez,double costo);
    virtual ~Suscripcion();

    int getId();
    double getCosto();
    E_PeriodoValidez getPeriodoValidez();
    Videojuego* getVideojuego();

    void setCosto(double costo);

    string toString();
};

#endif //PA___LABORATORIO_3_SUSCRIPCION_H
