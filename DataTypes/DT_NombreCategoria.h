//
// Created by esteban.rosano on 13/7/2022.
//

#ifndef MAIN_CPP_DT_NOMBRECATEGORIA_H
#define MAIN_CPP_DT_NOMBRECATEGORIA_H
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include <string>

using namespace std;

class DT_NombreCategoria: public ICollectible{
private:
    string nombre;

public:
    DT_NombreCategoria();
    DT_NombreCategoria(string nombre);

    string getNombre();
    void setNombre(string nombre);

    string toString();
};


#endif //MAIN_CPP_DT_NOMBRECATEGORIA_H
