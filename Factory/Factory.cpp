//
// Created by Admin on 12/07/2022.
//

#include "Factory.h"
#include "Controllers/CategoriaController.h"
#include "Controllers/DatosSuscripcionController.h"
#include "Controllers/PartidaController.h"
#include "Controllers/UsuarioController.h"
#include "Controllers/VideojuegoController.h"
#include<string>
using namespace std;
Factory* Factory::instance = NULL;

ICategoria* Factory::getInterfaceC() {
    CategoriaController* controller;
    return controller->getInstance();
}

IDatosSuscripcion* Factory::getInterfaceD() {
    DatosSuscripcionController* controller;
    return controller->getInstance();
}

IPartida* Factory::getInterfaceP() {
    PartidaController* controller;
    return controller->getInstance();
}
IUsuario* Factory::getInterfaceU() {
    UsuarioController* controller;
    return controller->getInstance();
}
IVideojuego* Factory::getInterfaceV() {
    VideojuegoController* controller;
    return controller->getInstance();
}

Factory::Factory() {

}
Factory* Factory::getInstance() {
    if (instance == NULL)
        instance = new Factory();
    return instance;
}