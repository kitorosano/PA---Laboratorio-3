//
// Created by esteban.rosano on 27/6/2022.
//

#include "AgregarCategoria.h"
#include "/Factory/Factory.h"
#include <iostream>
#include <string>
using namespace std;

void AgregarCategoria() {
    Factory * factory;

    try {
        ICollection *nombresCategoria = factory->getInstance()->getInterfaceC()->listarNombreCategorias();

        cout<<"|------------------------------------------------|"<<endl;
        cout<<"|              CATEGORÍAS EXISTENTES             |"<<endl;
        cout<<"|------------------------------------------------|"<<endl<<endl;

        IIterator *iterador = nombresCategoria->iterator();
        while(iterador->hasNext()) {
            cout << "|  " << iterador->next() <<endl;
        }

        cout<<"|------------------------------------------------|"<<endl<<endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
        return;
    }

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                AGREGAR CATEGORÍA               |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el nombre de la nueva categoría:"<<endl;
    string nombreCategoria;
    cin>>nombreCategoria;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                AGREGAR CATEGORÍA               |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese la descripción de la nueva categoría:"<<endl;
    string descripcionCategoria;
    cin>>descripcionCategoria;

    int opcion;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                AGREGAR CATEGORÍA               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Agregar categoría de plataforma             |" << endl;
        cout << "| 2. Agregar categoría de género                 |" << endl;
        cout << "| 2. Agregar categoría de otro tipo              |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                factory->getInstance()->getInterfaceC()->agregarCategoria(nombreCategoria, descripcionCategoria, E_TipoCategoria::PLATAFORMA);
                break;
            case 2:
                factory->getInstance()->getInterfaceC()->agregarCategoria(nombreCategoria, descripcionCategoria, E_TipoCategoria::GENERO);
                break;
            case 3:
                factory->getInstance()->getInterfaceC()->agregarCategoria(nombreCategoria, descripcionCategoria, E_TipoCategoria::OTRO);
                break;
            default:
                cout << "Opción inválida!" << endl;
                break;
        }
    }while(opcion !=1 && opcion !=2 && opcion !=3);

    cout<<endl<<"|------------------------------------------------|"<<endl<<endl;

    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                AGREGAR CATEGORÍA               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar categoría                         |" << endl;
        cout << "| 2. Cancelar categoría                          |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                factory->getInstance()->getInterfaceC()->confirmarCategoria();
                break;
            case 2:
                factory->getInstance()->getInterfaceC()->cancelarCategoria();
                break;
            default:
                cout << "Opción inválida!" << endl;
                break;
        }
    }while(opcion!=1 && opcion !=2);

}
