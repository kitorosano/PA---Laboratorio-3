//
// Created by Admin on 20/06/2022.
//

#ifndef LAB_3_PROYECTO_CATEGORIA_H
#define LAB_3_PROYECTO_CATEGORIA_H

#include "DataTypes/E_TipoCategoria.h"
#include <string>
#include <iostream>
using namespace std;

class Categoria {
private:
    string nombre;
    string descripcion;
    E_TipoCategoria tipo;

public:
    Categoria(string nombre,string descripcion);
    virtual ~Categoria();

    string getNombre();
    string getDesc();
    E_TipoCategoria getTipo();

    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setTipo(E_TipoCategoria tipo);

    string toString();

};

#endif //LAB_3_PROYECTO_CATEGORIA_H
