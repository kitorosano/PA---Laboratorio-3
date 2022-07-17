//
// Created by esteban.rosano on 27/6/2022.
//
#include "Factory/Factory.h"
#include "AltaUsuario.h"
#include <iostream>
#include <string>
using namespace std;

void AltaUsuario(){
    Factory * factory;
    Usuario* user=NULL;
    string email,password,nickname,descripcion,empresa;
    int opcion, opcion2;
    bool ret=true;
    int deseaReingresar=0;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cout << "Ingrese el email:" << endl;
        cin >> email;
        ret =true;
        user=factory->getInstance()->getInterfaceU()->buscarUsuario(email);

        if((factory->getInstance()->getInterfaceU()->getUsuarios()) && user && (email==user->getEmail())){
            cout<<"Ya existe un usuario con el email ingresado!"<<endl;
            ret=false;
        }
    }while(!ret);
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cout << "Ingrese la contrasenia:" << endl;
        cin >> password;


    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Registrarse como desarrollador              |" << endl;
        cout << "| 2. Registrarse como Jugador                    |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion;
        if(opcion !=1 && opcion !=2)
            cout<<"Debe ingresar una opcion!"<<endl;
    }while(opcion !=1 && opcion !=2);
    if(opcion==2) {
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
            if (!factory->getInstance()->getInterfaceU()->verificarNickname(nickname)) {
                cout<<"El nickname ingresado ya está en uso!!"<<endl;
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
        factory->getInstance()->getInterfaceU()->registroJugador(email,password,nickname,descripcion);

    }
    else if(opcion==1){
        cout << "|------------------------------------------------|" << endl;
        cout << "|        REGISTRO ADICIONAL DESARROLLADOR        |" << endl;
        cout << "|------------------------------------------------|" << endl<<endl;
        cout << "Ingrese el nombre de la empresa:" <<endl;
        cin >> empresa;
        factory->getInstance()->getInterfaceU()->registroDesarrollador(email,password,empresa);
    }

    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 ALTA DE USUARIO                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar Registro                          |" << endl;
        cout << "| 2. Cancelar  registro                          |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion2;
        if(opcion2 !=1 && opcion2 !=2)
            cout<<"Debe ingresar una opcion!"<<endl;

    }while(opcion2!=1 && opcion2 !=2);
    if(opcion2==1){
        factory->getInstance()->getInterfaceU()->confirmarRegistro();
        cout<<"Se ha registrado con exito!!";
    }
    else if(opcion2==2){
        factory->getInstance()->getInterfaceU()->cancelarRegistro();
    }


}