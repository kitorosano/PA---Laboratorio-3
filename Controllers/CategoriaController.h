//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_CATEGORIACONTROLLER_H
#define PA___LABORATORIO_3_CATEGORIACONTROLLER_H

#include "Interfaces/ICategoria.h"
#include <vector>


class CategoriaController {
private:
    Categoria* categoriaSeleccionada = nullptr;
    vector<Categoria *> categorias;

public:
    CategoriaController();
    static CategoriaController* getInstance();

    Categoria* getCategoriaSeleccionada();
    vector<Categoria> listadoCategorias();

    void seleccionarCategoria(string nombre);

    void agregarCategoria(string nombre, string descripcinon, E_tipoCategoria tipo);
    void confirmarCategoria();
    void cancelarCategoria();

    vector<string> listadoNombreCategorias();
    void agregarVideojuegoACategoria(Videojuego videojuego);

};


#endif //PA___LABORATORIO_3_CATEGORIACONTROLLER_H
