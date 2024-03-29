//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_ICATEGORIA_H
#define PA___LABORATORIO_3_ICATEGORIA_H

#include "Classes/Categoria.h"
#include <string>

using namespace std;

class ICategoria {
public:
    virtual void agregarCategoria(string nombre, string descripcinon, E_TipoCategoria tipo, Desarrollador* desarrollador) = 0;
    virtual void agregarVideojuegoACategoria() = 0;
    virtual Categoria* confirmarCategoria() = 0;
    virtual void cancelarCategoria() = 0;

    virtual void seleccionarCategoria(string nombre) = 0;

    virtual IDictionary* listarNombreCategorias() = 0;
    virtual IDictionary* listarCategorias() = 0;
    virtual IDictionary* listarCategoriasPlataforma() = 0;
    virtual IDictionary* listarCategoriasGenero() = 0;
    virtual IDictionary* listarCategoriasOtro() = 0;

    virtual IDictionary* obtenerCategoriasVideojuego(string nombre_videojuego) = 0;
};

#endif //PA___LABORATORIO_3_ICATEGORIA_H
