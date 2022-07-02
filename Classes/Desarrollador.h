//
// Created by esteban.rosano on 1/7/2022.
//

#ifndef PA___LABORATORIO_3_DESARROLLADOR_H
#define PA___LABORATORIO_3_DESARROLLADOR_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "./Usuario.h"

class Desarrollador: public Usuario {
private:
    int idDesarrollador;
    string nombreEmpresa;

public:
    Desarrollador(string email, string password, string nombreEmpresa);
    ~Desarrollador();

    int getIdDesarrollador();
    string getNombreEmpresa();

    void setNombreEmpresa(string nombreEmpresa);

    string toString();
};


#endif //PA___LABORATORIO_3_DESARROLLADOR_H
