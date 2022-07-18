//
// Created by esteban.rosano on 27/6/2022.
//

#include "VerInformacionDeVideojuego.h"
#include "Factory/Factory.h"
#include "DataTypes/DT_NombreDescripcion.h"
#include <iostream>
#include <string>
using namespace std;
void VerInformacionDeVideojuego() {
    Factory *factory;
    Usuario* usuarioLogueado = factory->getInstance()->getInterfaceU()->getUsuarioLogeado();
    bool validar = true;

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


    cout << endl << "Ingrese el nombre para seleccionar un videojuego: " << endl;
    cin >> nombre;
    try {
        factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(nombre);
        //cout<<"Partida abandonada"<<endl;
    } catch (exception &e) {
        cout<<e.what()<<endl;
        validar = false;
    }

    if (validar){
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"|          VER INFORMACION DE VIDEOJUEGO         |"<<endl;
        cout<<"|------------------------------------------------|"<<endl<<endl;

        Desarrollador* desarrollador = dynamic_cast<Desarrollador*>(usuarioLogueado);
        if(desarrollador) {
            factory->getInstance()->getInterfaceV()->verVideojuegoDesarrollador();
        } else {
            factory->getInstance()->getInterfaceV()->verVideojuego();
        }
    }

}