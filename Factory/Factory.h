//
// Created by Admin on 12/07/2022.
//

#ifndef FACTORY_H
#define FACTORY_H
#include "Interfaces/ICategoria.h"
#include "Interfaces/IDatosSuscripcion.h"
#include "Interfaces/IPartida.h"
#include "Interfaces/IUsuario.h"
#include "Interfaces/IVideojuego.h"

using namespace std;

class Factory{
private:
    static Factory * instance;
    ICategoria* interfaceC;
    IDatosSuscripcion* interfaceD;
    IPartida* interfaceP;
    IUsuario* interfaceU;
    IVideojuego* interfaceV;
    Factory();

public:
    static Factory* getInstance();
    ICategoria* getInterfaceC();
    IDatosSuscripcion* getInterfaceD();
    IPartida* getInterfaceP();
    IUsuario* getInterfaceU();
    IVideojuego* getInterfaceV();
};

#endif //FACTORY_H
