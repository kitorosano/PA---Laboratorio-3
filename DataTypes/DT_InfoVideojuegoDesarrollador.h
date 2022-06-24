//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_DT_INFOVIDEOJUEGODESARROLLADOR_H
#define PA___LABORATORIO_3_DT_INFOVIDEOJUEGODESARROLLADOR_H

#include "Classes/Suscripcion.h"
#include "Classes/Categoria.h"
#include <string>
#include <vector>

using namespace std;

class DT_InfoVideojuegoDesarrollador {
private:
    string nombre;
    vector<string> categorias;
    vector<Suscripcion> suscripciones;
    string empresa;
    double totalHorasJugadas;

public:
    DT_InfoVideojuegoDesarrollador(string nombre, vector<string> categorias, vector<Suscripcion> suscripciones, string empresa, double totalHorasJugadas);

    string getNombre();
    vector<string> getCategorias();
    vector<Suscripcion> getSuscripciones();
    string getEmpresa();
    double getTotalHorasJugadas();

};


#endif //PA___LABORATORIO_3_DT_INFOVIDEOJUEGODESARROLLADOR_H
