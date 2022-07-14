//
// Created by esteban.rosano on 27/6/2022.
//

#include "VerInformacionDeVideojuego.h"
#include "Factory/Factory.h"
#include <iostream>
#include <string>
using namespace std;
void VerInformacionDeVideojuego(int tipoUsuario){
    Factory* factory;
    string nombre;
    Videojuego* obtenido;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|          VER INFORMACION DE VIDEOJUEGO         |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    factory->getInstance()->getInterfaceV()->listarNombreVideojuegos();

    cout<<"|--------------------------------------------------|"<<endl;
    cout<<"| Ingrese el nombre para seleccionar un videojuego |"<<endl;
    cout<<"|--------------------------------------------------|"<<endl<<endl;
    cin>>nombre;
    obtenido=factory->getInstance()->getInterfaceV()->obtenerVideojuegoPorNombre(nombre);
    factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(obtenido->getId());
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|          VER INFORMACION DE VIDEOJUEGO         |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;

    switch (tipoUsuario) {
        case 0:
            factory->getInstance()->getInterfaceV()->verVideojuegoDesarrollador();
            break;
        default:
            factory->getInstance()->getInterfaceV()->verVideojuego();
    }
}