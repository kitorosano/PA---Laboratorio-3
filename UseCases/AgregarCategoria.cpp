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

    ICollection *nombresCategoria = factory->getInstance()->getInterfaceC()->listarNombreCategorias();

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|              CATEGORIAS EXISTENTES             |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;

    IIterator *iterador = nombresCategoria->iterator();
    while(iterador->hasNext()) {
        DT_NombreDescripcion* nombre = dynamic_cast<DT_NombreDescripcion*>(iterador->next());
        cout << "|  " << nombre->getNombre() <<endl;
    }

    cout<<"|------------------------------------------------|"<<endl<<endl;
  
  bool duplicado = false;
  string nombreCategoria;
    do {
      cout<<"|------------------------------------------------|"<<endl;
      cout<<"|                AGREGAR CATEGORÍA               |"<<endl;
      cout<<"|------------------------------------------------|"<<endl<<endl;
      cout<<"Ingrese el nombre de la nueva categoria:"<<endl;
      cin>>nombreCategoria;
  
      duplicado = factory->getInstance()->getInterfaceC()->listarNombreCategorias()->iterator();
      if(duplicado) {
        cout << "Esa categoria ya existe, ingrese otra";
      }
    } while(duplicado);

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                AGREGAR CATEGORÍA               |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese la descripcion de la nueva categoria:"<<endl;
    string descripcionCategoria;
    cin>>descripcionCategoria;

    int opcion = 0;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                AGREGAR CATEGORÍA               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Agregar categoria de plataforma             |" << endl;
        cout << "| 2. Agregar categoria de genero                 |" << endl;
        cout << "| 2. Agregar categoria de otro tipo              |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
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
        cout << "|                AGREGAR CATEGORÍA               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar categoria                         |" << endl;
        cout << "| 2. Cancelar categoria                          |" << endl;
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
                cout << "Opcion invalida!" << endl;
                break;
        }
    }while(opcion!=1 && opcion !=2);

}
