
//
// Created by esteban.rosano on 23/6/2022.
//

#include "CategoriaController.h"
#include "ColeccionesG/Lista.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/KeyString.h"
#include "ColeccionesG/IIterator.h"
#include "Factory/Factory.h"
#include "DataTypes/DT_NombreDescripcion.h"

using namespace std;

CategoriaController* CategoriaController::instance = NULL;

CategoriaController::CategoriaController() {
    this->categoriaSeleccionada = NULL;
    this->categorias = new ListDicc();
}

CategoriaController::~CategoriaController(){}

CategoriaController* CategoriaController::getInstance() {
    if (instance == NULL) {
        instance = new CategoriaController();
    }
    return instance;
}

void CategoriaController::agregarCategoria(string nombre, string descripcion, E_TipoCategoria tipo){
    this->categoriaSeleccionada = new Categoria(nombre, descripcion, tipo);
}

void CategoriaController::confirmarCategoria(){
this->categorias->add(this->categoriaSeleccionada, new KeyString(this->categoriaSeleccionada->getNombre()));
    this->categoriaSeleccionada = NULL;
}

void CategoriaController::cancelarCategoria(){
delete this->categoriaSeleccionada;
    this->categoriaSeleccionada = NULL;
}

Categoria* CategoriaController::getCategoriaSeleccionada(){
    return this->categoriaSeleccionada;
}

void CategoriaController::seleccionarCategoria(string nombre){
    ICollectible* categoria = this->categorias->find(new KeyString(nombre));
    if(categoria == nullptr){
      cout << "Categoria no existe";
      return;
    }
    this->categoriaSeleccionada = dynamic_cast<Categoria*>(categoria);
}

void CategoriaController::agregarVideojuegoACategoria(){
    Factory* factory;
    this->categoriaSeleccionada->agregarVideojuego(factory->getInstance()->getInterfaceV()->getVideojuegoSeleccionado());
}

IDictionary* CategoriaController::listarCategorias(){
    return this->categorias;
}
IDictionary* CategoriaController::listarCategoriasPlataforma(){
    IDictionary* categorias_plataforma = new ListDicc();
    IIterator* iterator = this->categorias->getIteratorObj();
    while (iterator->hasNext()) {
        Categoria* categoria = dynamic_cast<Categoria*>(iterator->next());
        if (categoria->getTipo() == E_TipoCategoria::PLATAFORMA) {
            categorias_plataforma->add(categoria, new KeyString(categoria->getNombre()));
        }
    }
    return categorias_plataforma;
}
IDictionary* CategoriaController::listarCategoriasGenero() {
    IDictionary* categorias_genero = new ListDicc();
    IIterator* iterator = this->categorias->getIteratorObj();
    while (iterator->hasNext()) {
        Categoria* categoria = dynamic_cast<Categoria*>(iterator->next());
        if (categoria->getTipo() == E_TipoCategoria::GENERO) {
            categorias_genero->add(categoria, new KeyString(categoria->getNombre()));
        }
    }
    return categorias_genero;
}
IDictionary* CategoriaController::listarCategoriasOtro() {
    IDictionary* categorias_otro = new ListDicc();
    IIterator* iterator = this->categorias->getIteratorObj();
    while (iterator->hasNext()) {
        Categoria* categoria = dynamic_cast<Categoria*>(iterator->next());
        if (categoria->getTipo() == E_TipoCategoria::OTRO) {
            categorias_otro->add(categoria, new KeyString(categoria->getNombre()));
        }
    }
    return categorias_otro;
}

ICollection* CategoriaController::listarNombreCategorias(){
    ICollection* nombres = new Lista();

    IIterator* it = this->categorias->getIteratorObj();
    while(it->hasNext()){
        Categoria* categoria = dynamic_cast<Categoria*>(it->getCurrent());
        DT_NombreDescripcion* nombre = new DT_NombreDescripcion(categoria->getNombre());
        nombres->add(nombre);

        it->next();
    }
    delete it;

    return nombres;
}

IDictionary* CategoriaController::obtenerCategoriasVideojuego(string nombre_videojuego){
    IDictionary* categorias_videojuego = new ListDicc();
    IIterator* it = this->categorias->getIteratorObj();
    while(it->hasNext()){
        Categoria* categoria = dynamic_cast<Categoria*>(it->next());
        if(categoria->tieneVideojuego(nombre_videojuego)){
            categorias_videojuego->add(categoria, new KeyString(categoria->getNombre()));
        }
    }
    delete it;
    return categorias_videojuego;
}