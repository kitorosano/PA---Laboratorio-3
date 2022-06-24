//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_ICATEGORIA_H
#define PA___LABORATORIO_3_ICATEGORIA_H

#include "DataTypes/E_TipoCategoria.h"
#include "Classes/Categoria.h"
#include "Classes/Videojuego.h"
#include <string>
#include <vector>

using namespace std;

class ICategoria {
public:
    virtual void agregarCategoria(string nombre, string descripcinon, E_TipoCategoria tipo) = 0;
    virtual vector<string> listadoNombreCategorias() = 0;
    virtual void confirmarCategoria() = 0;
    virtual void cancelarCategoria() = 0;
    virtual vector<Categoria*> listadoCategorias() = 0;
    virtual void seleccionarCategoria(string nombre) = 0;
    virtual void agregarVideojuegoACategoria(Videojuego videojuego) = 0;

};

#endif //PA___LABORATORIO_3_ICATEGORIA_H
