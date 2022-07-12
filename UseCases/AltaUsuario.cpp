//
// Created by esteban.rosano on 27/6/2022.
//
#include "/Factory/Factory.h"
#include "AltaUsuario.h"
#include <iostream>
#include <string>
using namespace std;

void AltaUsuario(){
    Factory * factory;
    string email,password,nickname,descripcion,empresa;
    int opcion;
    int deseaReingresar=0;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                 ALTA DE USUARIO                |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el email:"<<endl;
    cin>>email;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                 ALTA DE USUARIO                |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese la contraseña:"<<endl;
    cin>>password;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Registrarse como desarrollador              |" << endl;
        cout << "| 2. Registrarse como Jugador                    |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion;
        if(opcion !=1 && opcion !=2)
            throw invalid_argument("Debe ingresar una opcion!");
    }while(opcion !=1 && opcion !=2);
    if(opcion==1) {
        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|          REGISTRO ADICIONAL JUGADOR            |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cout << "Ingrese el nickname:" << endl;
            cin >> nickname;
            cout << "|------------------------------------------------|" << endl;
            cout << "|          REGISTRO ADICIONAL JUGADOR            |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cout << "Ingrese una descripcion:" << endl;
            cin >> descripcion;
            if (!factory->getInstance()->getInterfaceU->verificarNickname(nickname)) {
                cout << "|------------------------------------------------|" << endl;
                cout << "|          REGISTRO ADICIONAL JUGADOR            |" << endl;
                cout << "|------------------------------------------------|" << endl;
                cout << "| 1. Reingresar Nickname                         |" <<endl;
                cout << "| 2. Cancelar registro                           |" <<endl;
                cout << "|------------------------------------------------|" <<endl<<endl;
                cin>>deseaReingresar;
                if(deseaReingresar==2)
                    return;
            }
        }while(deseaReingresar==1);
        factory->getInstance()->getInterfaceU->registroJugador(email,password,nickname,descripcion);

    }
    else if(opcion==2){
        cout << "|------------------------------------------------|" << endl;
        cout << "|        REGISTRO ADICIONAL DESARROLLADOR        |" << endl;
        cout << "|------------------------------------------------|" << endl<<endl;
        cout << "Ingrese el nombre de la empresa:" <<endl;
        cin >> empresa;
        factory->getInstance()->getInterfaceU->registroDesarrollador(email,password,empresa);
    }

    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar Registro                          |" << endl;
        cout << "| 2. Cancelar  registro                          |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion;
        if(opcion !=1 && opcion !=2)
            throw invalid_argument("Debe ingresar una opcion!");

    }while(opcion!=1 && opcion !=2);
    if(opcion==1){
        factory->getInstance()->getInterfaceU->confirmarRegistro();
    }
    else if(opcion==2){
        factory->getInstance()->getInterfaceU->cancelarRegistro();
    }


}