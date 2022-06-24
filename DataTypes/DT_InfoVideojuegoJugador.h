//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_DT_INFOVIDEOJUEGOJUGADOR_H
#define PA___LABORATORIO_3_DT_INFOVIDEOJUEGOJUGADOR_H


#include "Classes/Suscripcion.h"
#include <string>
#include <vector>

using namespace std;

class DT_InfoVideojuegoJugador {
private:
    string nombre;
    vector<string> categorias;
    vector<Suscripcion *> suscripciones;
    string empresa;
    double puntaje;

public:
    DT_InfoVideojuegoJugador(string nombre, vector<string> categorias, vector<Suscripcion *> suscripciones, string empresa, double puntaje);

    string getNombre();
    vector<string> getCategorias();
    vector<Suscripcion *> getSuscripciones();
    string getEmpresa();
    double getPuntaje();

};



#endif //PA___LABORATORIO_3_DT_INFOVIDEOJUEGOJUGADOR_H
