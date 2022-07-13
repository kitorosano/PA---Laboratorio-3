//
// Created by Admin on 20/06/2022.
//

#ifndef LAB_3_PROYECTO_CATEGORIA_H
#define LAB_3_PROYECTO_CATEGORIA_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "DataTypes/E_TipoCategoria.h"
#include "Classes/Videojuego.h"
#include <string>
#include <iostream>
using namespace std;

class Categoria: public ICollectible {
private:
    string nombre;
    string descripcion;
    E_TipoCategoria tipo;

    IDictionary* videojuegos;

public:
    Categoria();
    Categoria(string nombre,string descripcion, E_TipoCategoria tipo);
    virtual ~Categoria();

    string getNombre();
    string getDescription();
    E_TipoCategoria getTipo();
    IDictionary* getVideojuegos();
    bool tieneVideojuego(string nombreVideojuego);

    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setTipo(E_TipoCategoria tipo);
    void agregarVideojuego(Videojuego* videojuego);

    string toString();

};

#endif //LAB_3_PROYECTO_CATEGORIA_H
