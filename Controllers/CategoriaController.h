//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_CATEGORIACONTROLLER_H
#define PA___LABORATORIO_3_CATEGORIACONTROLLER_H

#include "Interfaces/ICategoria.h"
#include <vector>
#include <string>


class CategoriaController: public ICategoria {
private:
    static CategoriaController* instance;
    CategoriaController();

    Categoria* categoriaSeleccionada;
    vector<Categoria *> categorias;

public:
    static CategoriaController* getInstance();
    virtual ~CategoriaController();

    Categoria* getCategoriaSeleccionada();
    vector<Categoria*> listadoCategorias();

    void seleccionarCategoria(string nombre);

    void agregarCategoria(string nombre, string descripcinon, E_TipoCategoria tipo);
    void confirmarCategoria();
    void cancelarCategoria();

    vector<string> listadoNombreCategorias();
    void agregarVideojuegoACategoria(Videojuego videojuego);

};


#endif //PA___LABORATORIO_3_CATEGORIACONTROLLER_H
