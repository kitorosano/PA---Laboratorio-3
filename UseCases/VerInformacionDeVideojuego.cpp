//
// Created by esteban.rosano on 27/6/2022.
//

#include "VerInformacionDeVideojuego.h"
#include "Factory/Factory.h"
#include "DataTypes/DT_NombreDescripcion.h"
#include <iostream>
#include <string>
using namespace std;
void VerInformacionDeVideojuego(int tipoUsuario) {
    Factory *factory;
    string nombre;
    Videojuego* obtenido;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|          VER INFORMACION DE VIDEOJUEGO         |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    IIterator* iterador = factory->getInstance()->getInterfaceV()->listarNombreVideojuegos()->getIteratorObj();
    while(iterador->hasNext()){
        DT_NombreDescripcion* nombreDescripcion = (DT_NombreDescripcion*)iterador->next();
        cout<<"|  "<<nombreDescripcion->getNombre()<<endl;
    }

    cout << "|--------------------------------------------------|" << endl;
    cout << "| Ingrese el nombre para seleccionar un videojuego |" << endl;
    cout << "|--------------------------------------------------|" << endl << endl;
    cin >> nombre;
    obtenido = factory->getInstance()->getInterfaceV()->obtenerVideojuegoPorNombre(nombre);
    if (obtenido){
    factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(obtenido->getId());
    }
    else{
        return;
    }
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