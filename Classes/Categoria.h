//
// Created by Admin on 20/06/2022.
//

#ifndef LAB_3_PROYECTO_CATEGORIA_H
#define LAB_3_PROYECTO_CATEGORIA_H
#include <string>
#include <iostream>
using namespace std;

class Categoria {
private:
    string nombre;
    string descripcion;
public:
    Categoria(string nombre,string descripcion);
    virtual ~Categoria();
    string getNombre();
    string getDesc();
    void setNombre(string nombre);
    void setDescripcion(string descripcion);
};

#endif //LAB_3_PROYECTO_CATEGORIA_H
