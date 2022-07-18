//
// Created by esteban.rosano on 27/6/2022.
//
#include "IniciarSesion.h"
#include "Factory/Factory.h"
#include "AltaUsuario.h"
#include <iostream>
#include <string>
using namespace std;

int IniciarSesion() {
    Factory *factory;
    string email, password, nickname, descripcion, empresa;
    int opcion,retorno;

    cout << "|------------------------------------------------|" << endl;
    cout << "|                INICIAR SESSION                 |" << endl;
    cout << "|------------------------------------------------|" << endl << endl;
    cout << "Ingrese el email:" << endl;
    cin >> email;
    cout << "|------------------------------------------------|" << endl;
    cout << "|                INICIAR SESSION                 |" << endl;
    cout << "|------------------------------------------------|" << endl << endl;
    cout << "Ingrese la contrasenia:" << endl;
    cin >> password;
    retorno=factory->getInstance()->getInterfaceU()->iniciarSesion(email,password);

    if(retorno==0){
        cout<<"Session establecida!"<<endl;
        cout<<"La sesion estara disponible hasta que otro usuario realice un nuevo inicio de sesion"<<endl;
    }
    else {
        switch (retorno) {
            case 1:
                cout << "No hay usuarios ingresados en el sistema" << endl;
                return -1;
            case 2:
                cout << "El usuario con email ingresado no existe en el sistema" << endl;
                return -1;
            case 3:
                cout << "La contraseniaa no es valida";
                return -1;
        }
        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|                INICIAR SESSION                 |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Reingresar los datos                        |" << endl;
            cout << "| 2. Cancelar                                    |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cin >> opcion;
            if (opcion != 1 && opcion != 2)
                cout<<"Debe ingresar una opcion!"<<endl;

        } while (opcion != 1 && opcion != 2);

        if (opcion == 1) {
            do {
                cout << "|------------------------------------------------|" << endl;
                cout << "|                INICIAR SESSION                 |" << endl;
                cout << "|------------------------------------------------|" << endl << endl;
                cout << "Ingrese el email:" << endl;
                cin >> nickname;
                cout << "|------------------------------------------------|" << endl;
                cout << "|                INICIAR SESSION                 |" << endl;
                cout << "|------------------------------------------------|" << endl << endl;
                cout << "Ingrese la contrasenia:" << endl;
                cin >> password;
                retorno=factory->getInstance()->getInterfaceU()->iniciarSesion(email,password);
                //switch
                switch (retorno) {
                    case 0:
                        cout << "Session establecida!" << endl;
                        cout << "La sesion estara disponible hasta que otro usuario realice un nuevo inicio de sesion" << endl;
                        break;
                    case 1:
                        cout << "No hay usuarios ingresados en el sistema" << endl;
                        return -1;
                    case 2:
                        cout << "El usuario con email ingresado no existe en el sistema" << endl;
                        return -1;
                    case 3:
                        cout << "La contrasenia no es valida";
                        return -1;
                }
            } while (retorno != 0);
        }
        else{
            return 3;
        }
    }

    //Desarrollador* desarrollador= dynamic_cast<Desarrollador*>(factory->getInstance()->getInterfaceU()->getUsuarioLogeado());
   // if(desarrollador) return 0;
   // return 1;
   return factory->getInstance()->getInterfaceU()->tipoUsuario(factory->getInstance()->getInterfaceU()->getUsuarioLogeado());

}