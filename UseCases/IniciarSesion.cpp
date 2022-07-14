//
// Created by esteban.rosano on 27/6/2022.
//
#include "IniciarSesion.h"
#include "/Factory/Factory.h"
#include "AltaUsuario.h"
#include <iostream>
#include <string>
using namespace std;

void IniciarSesion() {
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
    cout << "Ingrese la contraseña:" << endl;
    cin >> password;
    retorno=factory->getInstance()->getInterfaceU()->iniciarSesion(email,password);

    if(retorno==0){
        cout<<"Session establecida!"<<endl;
        cout<<"La sesion estará disponible hasta que otro usuario realice un nuevo inicio de sesion"<<endl;
    }
    else {
        switch (retorno) {
            case 1:
                cout << "No hay usuarios ingresados en el sistema" << endl;
                return;
                break;
            case 2:
                cout << "El usuario con email ingresado no existe en el sistema" << endl;
                break;
            case 3:
                cout << "La contraseña no es valida";
                break;
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
                cout << "Ingrese la contraseña:" << endl;
                cin >> password;
                retorno=factory->getInstance()->getInterfaceU()->iniciarSesion(email,password);
                //switch
                switch (retorno) {
                    case 0:
                        cout << "Session establecida!" << endl;
                        cout << "La sesion estará disponible hasta que otro usuario realice un nuevo inicio de sesion"
                             << endl;
                        break;
                    case 1:
                        cout << "No hay usuarios ingresados en el sistema" << endl;
                        return;
                        break;
                    case 2:
                        cout << "El usuario con email ingresado no existe en el sistema" << endl;
                        break;
                    case 3:
                        cout << "La contraseña no es valida";
                        break;
                }
            } while (retorno != 0);
        }
        else{
            return;
        }
    }
}