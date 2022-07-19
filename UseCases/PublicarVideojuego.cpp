//
// Created by esteban.rosano on 27/6/2022.
//

#include "PublicarVideojuego.h"
#include "Factory/Factory.h"
#include "Utils/Utils.h"
#include <iostream>
#include <string>

void PublicarVideojuego() {
    Factory *fabrica;
    Desarrollador* desarrolladorLogueado = dynamic_cast<Desarrollador*>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());

    string nombre, descripcion, str_costoMensual, str_costoTrimestral, str_costoAnual, str_costoVitalicia;

    cin.ignore();
    do {
        cout << "|               PUBLICAR VIDEOJUEGO              |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| Ingrese el nombre del videojuego: ";
        getline(cin, nombre);
        if (onlyContainsNumbers(nombre)) {
            cout <<"------------------------------------------------|" << endl;
            cout << "El nombre del videojuego no puede solamente numeros!!!" << endl;
            cout << "------------------------------------------------|" << endl;
        }
    } while (onlyContainsNumbers(nombre));

    cout<<"------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"| Ingrese la descripcion del videojuego: ";
    cin>>descripcion;

    cout<<"------------------------------------------------|"<<endl;
    do {
        cout << "|               PUBLICAR VIDEOJUEGO              |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| Ingrese el costo mensual del videojuego: ";
        cin >> str_costoMensual;
        if(!isDoubleWM(str_costoMensual)){
            cout <<"------------------------------------------------|" << endl;
            cout << "El costo mensual del videojuego debe de ser un numero positivo!!!" << endl;
            cout << "------------------------------------------------|" << endl;
        }
    } while (!isDoubleWM(str_costoMensual));

    cout << endl;
    cout<<"------------------------------------------------|"<<endl;
    do {
        cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"| Ingrese el costo trimestral del videojuego: ";
        cin>>str_costoTrimestral;
        if(!isDoubleWM(str_costoTrimestral)){
            cout <<"------------------------------------------------|" << endl;
            cout << "El costo trimestral del videojuego debe de ser un numero positivo!!!" << endl;
            cout << "------------------------------------------------|" << endl;
        }
    } while (!isDoubleWM(str_costoTrimestral));

    cout << endl;
    cout<<"------------------------------------------------|"<<endl;
    do {
        cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"| Ingrese el costo anual del videojuego: ";
        cin>>str_costoAnual;
        if(!isDoubleWM(str_costoAnual)){
            cout <<"------------------------------------------------|" << endl;
            cout << "El costo anual del videojuego debe de ser un numero positivo!!!" << endl;
            cout << "------------------------------------------------|" << endl;
        }
    } while (!isDoubleWM(str_costoAnual));

    cout << endl;
    cout<<"------------------------------------------------|"<<endl;
    do {
        cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"| Ingrese el costo vitalicia del videojuego: ";
        cin>>str_costoVitalicia;
        if(!isDoubleWM(str_costoVitalicia)){
            cout <<"------------------------------------------------|" << endl;
            cout << "El costo vitalicia del videojuego debe de ser un numero positivo!!!" << endl;
            cout << "------------------------------------------------|" << endl;
        }
    } while (!isDoubleWM(str_costoVitalicia));

    double costoMensual = stod(str_costoMensual);
    double costoTrimestral = stod(str_costoTrimestral);
    double costoAnual = stod(str_costoAnual);
    double costoVitalicia = stod(str_costoVitalicia);

    // CREO EL VIDEOJUEGO CON LOS DATOS INGRESADOS Y LAS SUSCRIPCIONES, Y GUARDO TANTO EL VIDEOJUEGO COMO SUSCRIPCIONES EN MEMORIA}
    fabrica->getInstance()->getInterfaceV()->datosNuevoVideojuego(nombre, descripcion, costoMensual, costoTrimestral, costoAnual, costoVitalicia, desarrolladorLogueado);

    // AGREGAR VIDEOJUEGO A CATEGORIAS DE PLATAFORMA
    IDictionary *categorias_plataforma = fabrica->getInstance()->getInterfaceC()->listarCategoriasPlataforma();

    cout << endl;
    cout<<"|------------------------------------------------|"<<endl;// MUESTRO LAS CATEGORIAS DE PLATAFORMA Y MEDIANTE SU NOMBRE SELECCIONO UNA DE ELLAS
    cout<<"|              CATEGORIAS PLATAFORMA             |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    IIterator *iter = categorias_plataforma->getIteratorObj();
    while (iter->hasNext()) {
        Categoria *categoria = dynamic_cast<Categoria*>(iter->next());
        cout << "| " << categoria->getNombre() << ": " << categoria->getDescription() << endl;
    }
    delete iter;

    string seguirAgregandoPlataforma = "s";
    do {
        string nombre_categoria = "";
        cin.ignore();
        while(!categorias_plataforma->member(new KeyString(nombre_categoria))) {
            cout << "|------------------------------------------------|" << endl;
            cout<<"| Escriba correctamente la categoria de plataforma que desea agregarle al videojuego: ";
            getline(cin, nombre_categoria);
            cout << endl;
        }

        // SELECCIONO LA CATEGORIA INGRESADA Y LE AGREGO EL VIDEOJUEGO
        fabrica->getInstance()->getInterfaceC()->seleccionarCategoria(nombre_categoria);

        try {
            fabrica->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
            cout << "|------------------------------------------------|" << endl;
            cout << "|      Videojuego enlazado a categoria           |" << endl;
            cout << "|------------------------------------------------|" << endl;
        } catch (exception &e) {
            cout << "|------------------------------------------------|" << endl;
            cout << "|      Este videojuego ya se encuentra           |" << endl;
            cout << "|      enlazado a la categoria seleccionada.     |" << endl;
            cout << "|------------------------------------------------|" << endl;
        }
        cout<<"| Desea seguir agregando CATEGORIAS de PLATAFORMA?(s/n): ";
        cin>>seguirAgregandoPlataforma;
    } while (seguirAgregandoPlataforma == "s" || seguirAgregandoPlataforma == "S");

    // AGREGAR VIDEOJUEGO A CATEGORIAS DE GENERO
    IDictionary *categorias_genero = fabrica->getInstance()->getInterfaceC()->listarCategoriasGenero();

    // MUESTRO LAS CATEGORIAS DE GENERO Y MEDIANTE SU NOMBRE SELECCIONO UNA DE ELLAS
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               CATEGORIAS GÉNERO                |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    iter = categorias_genero->getIteratorObj();
    while (iter->hasNext()) {
        Categoria *categoria = dynamic_cast<Categoria*>(iter->next());
        cout << "| "<< categoria->getNombre() << ": " << categoria->getDescription() << endl;
    }
    delete iter;

    string seguirAgregandoGenero = "s";
    do {
        string nombre_categoria = "";
        cin.ignore();
        while(!categorias_genero->member(new KeyString(nombre_categoria))) {
            cout << "|------------------------------------------------|" << endl;
            cout<<"| Escriba correctamente la categoria de genero que desea agregarle al videojuego: ";
            getline(cin, nombre_categoria);
            cout << endl;
        }

        // SELECCIONO LA CATEGORIA INGRESADA Y LE AGREGO EL VIDEOJUEGO
        fabrica->getInstance()->getInterfaceC()->seleccionarCategoria(nombre_categoria);
        try {
            fabrica->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
            cout << "|------------------------------------------------|" << endl;
            cout << "|      Videojuego enlazado a categoria           |" << endl;
            cout << "|------------------------------------------------|" << endl;
        } catch (exception &e) {
            cout << "|------------------------------------------------|" << endl;
            cout << "|      Este videojuego ya se encuentra           |" << endl;
            cout << "|      enlazado a la categoria seleccionada.     |" << endl;
            cout << "|------------------------------------------------|" << endl;
        }

        cout<<"Desea seguir agregando CATEGORIAS de GENERO?(s/n): ";
        cin>>seguirAgregandoGenero;
    } while (seguirAgregandoGenero == "s" || seguirAgregandoGenero == "S");

    // AGREGAR VIDEOJUEGO A CATEGORIAS EXTRAS
    IDictionary *categorias_otro = fabrica->getInstance()->getInterfaceC()->listarCategoriasOtro();

    string agregarOtros = "s";

    // MUESTRO LAS CATEGORIAS EXTRAS Y MEDIANTE SU NOMBRE SELECCIONO UNA DE ELLAS
    cout<<"Desea agregar alguna OTRA categoria?(s/n): ";
    cin>>agregarOtros;

    if (agregarOtros == "s" || agregarOtros == "S") {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 OTRAS CATEGORIAS               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        iter = categorias_otro->getIteratorObj();
        while (iter->hasNext()) {
            Categoria *categoria = dynamic_cast<Categoria *>(iter->next());
            cout << "| " << categoria->getNombre() << ": " << categoria->getDescription() << endl;
        }
        delete iter;

        string seguirAgregandoGenero = "s";
        do {
            string nombre_categoria = "";
            cin.ignore();
            while (!categorias_otro->member(new KeyString(nombre_categoria))) {
                cout << "|------------------------------------------------|" << endl;
                cout << "| Escriba correctamente la categoria de otro que desea agregarle al videojuego: ";
                getline(cin, nombre_categoria);
                cout << endl;
            }

            // SELECCIONO LA CATEGORIA INGRESADA Y LE AGREGO EL VIDEOJUEGO
            fabrica->getInstance()->getInterfaceC()->seleccionarCategoria(nombre_categoria);
            try {
                fabrica->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
                cout << "|------------------------------------------------|" << endl;
                cout << "|      Videojuego enlazado a categoria           |" << endl;
                cout << "|------------------------------------------------|" << endl;
            } catch (exception &e) {
                cout << "|------------------------------------------------|" << endl;
                cout << "|      Este videojuego ya se encuentra           |" << endl;
                cout << "|      enlazado a la categoria seleccionada.     |" << endl;
                cout << "|------------------------------------------------|" << endl;
            }

            cout << "Desea seguir agregando CATEGORIAS OPCIONALES?(s/n): ";
            cin >> seguirAgregandoGenero;
        } while (seguirAgregandoGenero == "s" || seguirAgregandoGenero == "S");
    }


    // MOSTRAR INFORMACION DEL VIDEOJUEGO
    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    Videojuego * videojuegoEnProceso= fabrica->getInstance()->getInterfaceV()->getVideojuegoSeleccionado();
    cout << "| Nombre: " << videojuegoEnProceso->getNombre() << endl;
    cout << "| Descripcion: " << videojuegoEnProceso->getDescripcion() << endl;
    cout << "| Costo Mensual: " << costoMensual << endl;
    cout << "| Costo Trimestral: " << costoTrimestral << endl;
    cout << "| Costo Anual: " << costoAnual << endl;
    cout << "| Costo Vitalicia: " << costoVitalicia << endl;
    cout << "| Categorias: " << endl;
    IIterator *iterCat = fabrica->getInstance()->getInterfaceC()->obtenerCategoriasVideojuego(videojuegoEnProceso->getNombre())->getIteratorObj();
    while (iterCat->hasNext()) {
        Categoria *categoria = dynamic_cast<Categoria*>(iterCat->next());
        cout << "| \t- " << categoria->getNombre() << endl;
    }
    delete iterCat;

    // CONFIRMAR LA PUBLICACION DEL VIDEOJUEGO
    int opcion = 0;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|               PUBLICAR VIDEOJUEGO              |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar videojuego                        |" << endl;
        cout << "| 2. Cancelar videojuego                         |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                fabrica->getInstance()->getInterfaceV()->confirmarVideojuego();
                cout<<endl;
                cout << "|------------------------------------------------|" << endl;
                cout << "|              PUBLICACION EXITOSA!!             |" << endl;
                cout << "|------------------------------------------------|" << endl;
                break;
            case 2:
                fabrica->getInstance()->getInterfaceV()->cancelarVideojuego();
                cout<<endl;
                cout << "|------------------------------------------------|" << endl;
                cout << "|             PUBLICACION CANCELADA              |" << endl;
                cout << "|------------------------------------------------|" << endl;
                break;
            default:
                cout << "Opcion invalida!" << endl;
                break;
        }
    }while(opcion!=1 && opcion !=2);

};