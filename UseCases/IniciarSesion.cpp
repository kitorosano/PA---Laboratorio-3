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
        if(retorno==1){
            cout<<("No hay usuarios ingresados en el sistema")<<endl;
            return;
        }
        else if(retorno==2){
            throw invalid_argument("El usuario con email ingresado no existe en el sistema");
        }
        else if(retorno==3){
            throw invalid_argument("La contraseña no es valida");
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
                throw invalid_argument("Debe ingresar una opcion!");

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

                if(retorno==1){
                    cout<<("No hay usuarios ingresados en el sistema")<<endl;
                    return;
                }
                else if(retorno==2){
                    throw invalid_argument("El usuario con email ingresado no existe en el sistema");
                }
                else if(retorno==3){
                    throw invalid_argument("La contraseña no es valida");
                }
                if(retorno==0){
                    cout<<"Session establecida!"<<endl;
                    cout<<"La sesion estará disponible hasta que otro usuario realice un nuevo inicio de sesion"<<endl;
                }
            } while (retorno != 0);
        }
        else{
            return;
        }
    }
}