//
// Created by esteban.rosano on 27/6/2022.
//
#include "Factory/Factory.h"
#include "AltaUsuario.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void AltaUsuario(){
    Factory * factory;
    Usuario* user=NULL;
    string email,_email,password,nickname,descripcion,empresa;
    int tipoRegistro, opcion2;
    bool ret=true;
    int deseaReingresar=0;
    char _descripcion[255];

    do {
        cout<<endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| Ingrese el email: ";
        cin >> email;
        fflush(stdin);

        ret = true;
        user=factory->getInstance()->getInterfaceU()->buscarUsuario(_email);

        if((factory->getInstance()->getInterfaceU()->getUsuarios()) && user && (email==user->getEmail())){
            cout<<endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|   Ya existe un usuario con el email ingresado  |" << endl;
            cout << "|------------------------------------------------|" << endl;
            ret=false;
        }
    }while(!ret);

    cout<<endl;
    cout << "|------------------------------------------------|" << endl;
    cout << "|                 ALTA DE USUARIO                |" << endl;
    cout << "|------------------------------------------------|" << endl;
    cout << "| Ingrese la contrasenia: ";
    cin >> password;
    fflush(stdin);

    do {
        cout<<endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Registrarse como Desarrollador              |" << endl;
        cout << "| 2. Registrarse como Jugador                    |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cin >> tipoRegistro;
        if(tipoRegistro !=1 && tipoRegistro !=2) {
            cout << "|------------------------------------------------|" << endl;
            cout << "|              Opcion invalida!                  |" << endl;
            cout << "|------------------------------------------------|" << endl;
        }
    }while(tipoRegistro !=1 && tipoRegistro !=2);

    switch(tipoRegistro) {
        case 1: {
            cout<<endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|        REGISTRO ADICIONAL DESARROLLADOR        |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| Ingrese el nombre de la empresa: ";
            cin >> empresa;
            fflush(stdin);
            factory->getInstance()->getInterfaceU()->registroDesarrollador(email, password, empresa);
            break;
        }
        case 2: {
            do {
                cout<<endl;
                cout << "|------------------------------------------------|" << endl;
                cout << "|          REGISTRO ADICIONAL JUGADOR            |" << endl;
                cout << "|------------------------------------------------|" << endl;
                cout << "| Ingrese el nickname: ";
                cin >> nickname;
                fflush(stdin);

                if (factory->getInstance()->getInterfaceU()->verificarNicknamesIngresados(nickname)) {
                    cout<<endl;
                    cout << "|------------------------------------------------|" << endl;
                    cout << "| Ya existe un jugador con el nickname ingresado |" << endl;
                    cout << "|------------------------------------------------|" << endl;
                    cout << "| 1. Reingresar Nickname                         |" << endl;
                    cout << "| 2. Cancelar registro                           |" << endl;
                    cout << "|------------------------------------------------|" << endl;
                    cin >> deseaReingresar;
                    fflush(stdin);
                    if (deseaReingresar == 2) {
                        cout<<endl;
                        cout << "|------------------------------------------------|" << endl;
                        cout << "|               REGISTRO CANCELADO               |" << endl;
                        cout << "|------------------------------------------------|" << endl;
                        return;
                    }
                }
            } while (factory->getInstance()->getInterfaceU()->verificarNicknamesIngresados(nickname));

            cout<<endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|          REGISTRO ADICIONAL JUGADOR            |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| Ingrese una descripcion: ";
            gets(_descripcion);
            descripcion=_descripcion;
            fflush(stdin);

            factory->getInstance()->getInterfaceU()->registroJugador(email, password, nickname, descripcion);
            break;
        }
        default:
            break;
    }

    do {
        cout<<endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar Registro                          |" << endl;
        cout << "| 2. Cancelar  registro                          |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cin >> opcion2;
        fflush(stdin);
        if(opcion2 !=1 && opcion2 !=2) {
            cout<<endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|          Debe ingresar una opcion!              |" << endl;
            cout << "|------------------------------------------------|" << endl;
        }

    } while(opcion2!=1 && opcion2 !=2);

    if(opcion2==1){
        factory->getInstance()->getInterfaceU()->confirmarRegistro();
        cout<<endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|               REGISTRO EXITOSO!!               |" << endl;
        cout << "|------------------------------------------------|" << endl<< endl;
    }
    else if(opcion2==2){
        factory->getInstance()->getInterfaceU()->cancelarRegistro();
        cout<<endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|               REGISTRO CANCELADO               |" << endl;
        cout << "|------------------------------------------------|" << endl<< endl;
    }
}