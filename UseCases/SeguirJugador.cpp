//
// Created by esteban.rosano on 27/6/2022.
//

#include "SeguirJugador.h"
#include "Factory/Factory.h"
#include <iostream>
#include <string>
using namespace std;
void SeguirJugador(){
    Factory* factory;
    string nickname;
    bool retorno;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 SEGUIR JUGADOR                 |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cout << "Listado de jugadores en el sistema:" << endl;
        factory->getInstance()->getInterfaceU()->listarJugadores();

        cout << "Seleccione un jugador ingresando su nickname" << endl;
        cin >> nickname;
        retorno=factory->getInstance()->getInterfaceU()->verificarNickname(nickname);
        if(!retorno)
            cout<<"El nickname ingresado es incorrecto"<<endl;
    }while(!retorno);
            cout<<"Usteded sigue al jugador "<<nickname<<"!"<<endl;
}