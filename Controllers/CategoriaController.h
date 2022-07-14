//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_CATEGORIACONTROLLER_H
#define PA___LABORATORIO_3_CATEGORIACONTROLLER_H

#include "Interfaces/ICategoria.h"
#include <string>

class CategoriaController: public ICategoria {
private:
    static CategoriaController* instance;
    CategoriaController();

    Categoria* categoriaSeleccionada;
    IDictionary* categorias;

public:
    static CategoriaController* getInstance();
    virtual ~CategoriaController();

    Categoria* getCategoriaSeleccionada();

    void agregarCategoria(string nombre, string descripcion, E_TipoCategoria tipo);
    void confirmarCategoria();
    void cancelarCategoria();

    void agregarVideojuegoACategoria(Videojuego* videojuego);
    void seleccionarCategoria(string nombre);

    IDictionary* listarCategorias();
    ICollection* listarNombreCategorias();

    IDictionary* obtenerCategoriasVideojuego(string nombre_videojuego);

};


#endif //PA___LABORATORIO_3_CATEGORIACONTROLLER_H
