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
    Usuario* usuario_logueado=factory->getInstance()->getInterfaceU()->getUsuarioLogeado();


    string nickname;
    bool retorno;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 SEGUIR JUGADOR                 |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cout << "Listado de jugadores en el sistema:" << endl;
        factory->getInstance()->getInterfaceU()->listarJugadores(usuario_logueado);

        cout << "Seleccione un jugador ingresando su nickname" << endl;
        cin >> nickname;
        retorno=factory->getInstance()->getInterfaceU()->verificarNicknamesIngresados(nickname);
        if(!retorno)
            cout<<"El nickname ingresado es incorrecto"<<endl;
    }while(!retorno);
            cout<<"Usteded sigue al jugador "<<nickname<<"!"<<endl;
            factory->getInstance()->getInterfaceU()->seguirJugador(nickname,usuario_logueado);
}