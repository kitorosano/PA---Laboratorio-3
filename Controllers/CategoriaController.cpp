
//
// Created by esteban.rosano on 23/6/2022.
//

#include "CategoriaController.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/KeyString.h"
#include "ColeccionesG/IIterator.h"

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
    this->categoriaSeleccionada = dynamic_cast<Categoria*>(this->categorias->find(new KeyString(nombre)));
}

void CategoriaController::agregarVideojuegoACategoria(Videojuego* videojuego){
    this->categoriaSeleccionada->agregarVideojuego(videojuego);
}


void CategoriaController::listarCategorias(){
    IIterator* it = this->categorias->getIteratorObj();
    while(it->hasNext()){
        Categoria* categoria = dynamic_cast<Categoria*>(it->getCurrent());
        cout<<categoria->toString()<<endl;
    }
    delete it;
}
void CategoriaController::listarNombreCategorias(){
    IIterator* it = this->categorias->getIteratorObj();
    while(it->hasNext()){
        Categoria* categoria = dynamic_cast<Categoria*>(it->getCurrent());
        cout<<categoria->getNombre()<<endl;
    }
    delete it;
}

IDictionary* CategoriaController::obtenerCategoriasVideojuego(string nombre_videojuego){
    IDictionary* categorias_videojuego = new ListDicc();
    IIterator* it = this->categorias->getIteratorObj();
    while(it->hasNext()){
        Categoria* categoria = dynamic_cast<Categoria*>(it->getCurrent());
        if(categoria->tieneVideojuego(nombre_videojuego)){
            categorias_videojuego->add(categoria, new KeyString(categoria->getNombre()));
        }
    }
    delete it;
    return categorias_videojuego;
}