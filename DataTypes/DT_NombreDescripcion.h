//
// Created by esteban.rosano on 13/7/2022.
//

#ifndef MAIN_CPP_DT_NOMBREDESCRIPCION_H
#define MAIN_CPP_DT_NOMBREDESCRIPCION_H
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include <string>

class DT_NombreDescripcion: public ICollectible{
private:
    string nombre;
    string descripcion;

public:
    DT_NombreDescripcion();
    DT_NombreDescripcion(string nombre);
    DT_NombreDescripcion(string nombre, string descripcion);

    string getNombre();
    void setNombre(string nombre);

    string getDescripcion();
    void setDescripcion(string descripcion);
};


#endif //MAIN_CPP_DT_NOMBREDESCRIPCION_H
