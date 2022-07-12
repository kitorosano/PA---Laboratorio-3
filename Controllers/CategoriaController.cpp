
//
// Created by esteban.rosano on 23/6/2022.
//

#include "CategoriaController.h"

using namespace std;

CategoriaController* CategoriaController::instance = NULL;

CategoriaController::CategoriaController() {
    this->categoriaSeleccionada = NULL;
    this->categorias = vector<Categoria*>();
}

CategoriaController::~CategoriaController(){}

CategoriaController* CategoriaController::getInstance() {
    if (instance == NULL) {
        instance = new CategoriaController();
    }
    return instance;
}

Categoria* CategoriaController::getCategoriaSeleccionada(){}
vector<Categoria*> CategoriaController::listadoCategorias(){}

void CategoriaController::seleccionarCategoria(string nombre){}

void CategoriaController::agregarCategoria(string nombre, string descripcinon, E_TipoCategoria tipo){}
void CategoriaController::confirmarCategoria(){}
void CategoriaController::cancelarCategoria(){}

vector<string> CategoriaController::listadoNombreCategorias(){}
void CategoriaController::agregarVideojuegoACategoria(Videojuego videojuego){}