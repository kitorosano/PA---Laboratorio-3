//
// Created by esteban.rosano on 27/6/2022.
//

#include "AgregarCategoria.h"
#include "Factory/Factory.h"
#include "DataTypes/DT_NombreDescripcion.h"
#include <iostream>
#include <string>

using namespace std;

void AgregarCategoria() {
    Factory * factory;
    Desarrollador* desarrolladorLogueado = dynamic_cast<Desarrollador*>(factory->getInstance()->getInterfaceU()->getUsuarioLogeado());

    IDictionary *nombresCategoria = factory->getInstance()->getInterfaceC()->listarNombreCategorias();

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|              CATEGORIAS EXISTENTES             |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;

    IIterator *iterador = nombresCategoria->getIteratorObj();
    while(iterador->hasNext()) {
        DT_NombreDescripcion* nombre = dynamic_cast<DT_NombreDescripcion*>(iterador->next());
        cout << "|  " << nombre->getNombre() <<endl;
    }
    cout<<"|------------------------------------------------|"<<endl<<endl;

     bool repetir;
    string nombreCategoria;
    do {
      cout<<"|------------------------------------------------|"<<endl;
      cout<<"|                AGREGAR CATEGORIA               |"<<endl;
      cout<<"|------------------------------------------------|"<<endl<<endl;
      cout<<"Ingrese el nombre de la nueva categoria:"<<endl;
      //cin>>nombreCategoria;
      cin.ignore();
      getline(cin, nombreCategoria);


      repetir = false;
      KeyString *keyNombreCategoria = new KeyString(nombreCategoria);
      if(nombresCategoria->member(keyNombreCategoria)) {
          cout << "Esa categoria ya existe, ingrese otra"<<endl;
          repetir = true;
      }
    } while(repetir == true);


    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                AGREGAR CATEGORIA               |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese la descripcion de la nueva categoria:"<<endl;
    string descripcionCategoria;
    //cin>>descripcionCategoria;
    cin.ignore();
    getline(cin, descripcionCategoria);

    int opcion = 0;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                AGREGAR CATEGORiA               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Agregar categoria de plataforma             |" << endl;
        cout << "| 2. Agregar categoria de genero                 |" << endl;
        cout << "| 3. Agregar categoria de otro tipo              |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cout<<"Ingrese una opcion:";
        cin >> opcion;

        switch (opcion) {
            case 1:
                factory->getInstance()->getInterfaceC()->agregarCategoria(nombreCategoria, descripcionCategoria, E_TipoCategoria::PLATAFORMA, desarrolladorLogueado);
                break;
            case 2:
                factory->getInstance()->getInterfaceC()->agregarCategoria(nombreCategoria, descripcionCategoria, E_TipoCategoria::GENERO, desarrolladorLogueado);
                break;
            case 3:
                factory->getInstance()->getInterfaceC()->agregarCategoria(nombreCategoria, descripcionCategoria, E_TipoCategoria::OTRO, desarrolladorLogueado);
                break;
            default:
                cout << "Opcion invalida!" << endl;
                break;
        }
    } while(opcion !=1 && opcion !=2 && opcion !=3);


    cout<<endl<<"|------------------------------------------------|"<<endl<<endl;

    opcion = 0;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                AGREGAR CATEGORIA               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar categoria                         |" << endl;
        cout << "| 2. Cancelar categoria                          |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cout<<"Ingrese una opcion:";
        cin >> opcion;

        switch (opcion) {
            case 1:
                factory->getInstance()->getInterfaceC()->confirmarCategoria();
                break;
            case 2:
                factory->getInstance()->getInterfaceC()->cancelarCategoria();
                break;
            default:
                cout << "Opcion invalida!" << endl;
                break;
        }
    }while(opcion!=1 && opcion !=2);

}
