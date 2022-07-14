//
// Created by esteban.rosano on 27/6/2022.
//

#include "PublicarVideojuego.h"
#include "Factory/Factory.h"
#include <iostream>
#include <string>

void PublicarVideojuego() {
    Factory *fabrica;

    string nombre, descripcion;
    double costoMensual, costoTrimestral, costoAnual, costoVitalicia;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el nombre del videojuego: ";
    cin>>nombre;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese la descripcion del videojuego: ";
    cin>>descripcion;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el costo mensual del videojuego: ";
    cin>>costoMensual;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el costo trimestral del videojuego: ";
    cin>>costoTrimestral;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el costo anual del videojuego: ";
    cin>>costoAnual;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el costo vitalicia del videojuego: ";
    cin>>costoVitalicia;

    // CREO EL VIDEOJUEGO CON LOS DATOS INGRESADOS Y LAS SUSCRIPCIONES, Y GUARDO TANTO EL VIDEOJUEGO COMO SUSCRIPCIONES EN MEMORIA
    fabrica->getInstance()->getInterfaceV()->datosNuevoVideojuego(nombre, descripcion, costoMensual, costoTrimestral, costoAnual, costoVitalicia);

    cout << "|------------------------------------------------|" << endl<<endl<<endl;
    // AGREGAR VIDEOJUEGO A CATEGORIAS DE PLATAFORMA
    IDictionary *categorias_plataforma = fabrica->getInstance()->getInterfaceC()->listarCategoriasPlataforma();

    char seguirAgregandoPlataforma = 's';
    do {
        // MUESTRO LAS CATEGORIAS DE PLATAFORMA Y MEDIANTE SU NOMBRE SELECCIONO UNA DE ELLAS
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"|              CATEGORÍAS PLATAFORMA             |"<<endl;
        cout<<"|------------------------------------------------|"<<endl<<endl;
        IIterator *iter = categorias_plataforma->getIteratorObj();
        while (iter->hasNext()) {
            Categoria *categoria = dynamic_cast<Categoria*>(iter->next());
            cout << categoria->getNombre() << ": " << categoria->getDescription() << endl;
        }
        delete iter;
        cout << "|------------------------------------------------|" << endl<<endl;

        cout<<"Escriba una de las categorías de plataforma para agregarle al videojuego: ";
        string nombre_categoria;
        cin>>nombre_categoria;

        // SELECCIONO LA CATEGORIA INGRESADA Y LE AGREGO EL VIDEOJUEGO
        fabrica->getInstance()->getInterfaceC()->seleccionarCategoria(nombre_categoria);
        try {
            fabrica->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
            cout << "|------------------------------------------------|" << endl<<endl;
            cout << "|      Videojuego enlazado a categoría           |" << endl;
            cout << "|------------------------------------------------|" << endl<<endl;
        } catch (exception &e) {
            cout << "|------------------------------------------------|" << endl<<endl;
            cout << "|      Este videojuego ya se encuentra           |" << endl;
            cout << "|      enlazado a la categoría seleccionada.     |" << endl;
            cout << "|------------------------------------------------|" << endl<<endl;
        }

        cout << "|------------------------------------------------|" << endl<<endl;
        cout<<"Desea seguir agregando categorías de PLATAFORMA?(s/n): ";
        cin>>seguirAgregandoPlataforma;
    } while (seguirAgregandoPlataforma == 's' || seguirAgregandoPlataforma == 'S');


    cout << "|------------------------------------------------|" << endl<<endl<<endl;

    // AGREGAR VIDEOJUEGO A CATEGORIAS DE GENERO
    IDictionary *categorias_genero = fabrica->getInstance()->getInterfaceC()->listarCategoriasGenero();

    char seguirAgregandoGenero = 's';
    do {
        // MUESTRO LAS CATEGORIAS DE GENERO Y MEDIANTE SU NOMBRE SELECCIONO UNA DE ELLAS
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"|               CATEGORÍAS GÉNERO                |"<<endl;
        cout<<"|------------------------------------------------|"<<endl<<endl;
        IIterator *iter = categorias_genero->getIteratorObj();
        while (iter->hasNext()) {
            Categoria *categoria = dynamic_cast<Categoria*>(iter->next());
            cout << categoria->getNombre() << ": " << categoria->getDescription() << endl;
        }
        delete iter;
        cout << "|------------------------------------------------|" << endl<<endl;

        cout<<"Escriba una de las categorías de genero para agregarle al videojuego: ";
        string nombre_categoria;
        cin>>nombre_categoria;

        // SELECCIONO LA CATEGORIA INGRESADA Y LE AGREGO EL VIDEOJUEGO
        fabrica->getInstance()->getInterfaceC()->seleccionarCategoria(nombre_categoria);
        try {
            fabrica->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
            cout << "|------------------------------------------------|" << endl<<endl;
            cout << "|      Videojuego enlazado a categoría           |" << endl;
            cout << "|------------------------------------------------|" << endl<<endl;
        } catch (exception &e) {
            cout << "|------------------------------------------------|" << endl<<endl;
            cout << "|      Este videojuego ya se encuentra           |" << endl;
            cout << "|      enlazado a la categoría seleccionada.     |" << endl;
            cout << "|------------------------------------------------|" << endl<<endl;
        }

        cout << "|------------------------------------------------|" << endl<<endl;
        cout<<"Desea seguir agregando categorías de GENERO?(s/n): ";
        cin>>seguirAgregandoGenero;
    } while (seguirAgregandoGenero == 's' || seguirAgregandoGenero == 'S');


    cout << "|------------------------------------------------|" << endl<<endl<<endl;

    // AGREGAR VIDEOJUEGO A CATEGORIAS EXTRAS
    IDictionary *categorias_otro = fabrica->getInstance()->getInterfaceC()->listarCategoriasOtro();

    char seguirAgregandoOtro = 's';
    do {
        // MUESTRO LAS CATEGORIAS EXTRAS Y MEDIANTE SU NOMBRE SELECCIONO UNA DE ELLAS
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"|                 OTRAS CATEGORÍAS               |"<<endl;
        cout<<"|------------------------------------------------|"<<endl<<endl;
        cout<<"Desea agregar alguna OTRA categoría?(s/n): ";
        cin>>seguirAgregandoOtro;

        if (seguirAgregandoOtro == 's' || seguirAgregandoOtro == 'S') {
            cout<<"|------------------------------------------------|"<<endl;
            cout<<"|                 OTRAS CATEGORÍAS               |"<<endl;
            cout<<"|------------------------------------------------|"<<endl<<endl;
            IIterator *iter = categorias_otro->getIteratorObj();
            while (iter->hasNext()) {
                Categoria *categoria = dynamic_cast<Categoria*>(iter->next());
                cout << categoria->getNombre() << ": " << categoria->getDescription() << endl;
            }
            delete iter;
            cout << "|------------------------------------------------|" << endl<<endl;

            cout<<"Escriba el nombre de la categoría a agregar: ";
            string nombre_categoria;
            cin>>nombre_categoria;

            // SELECCIONO LA CATEGORIA INGRESADA Y LE AGREGO EL VIDEOJUEGO
            fabrica->getInstance()->getInterfaceC()->seleccionarCategoria(nombre_categoria);
            try {
                fabrica->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
                cout << "|------------------------------------------------|" << endl<<endl;
                cout << "|      Videojuego enlazado a categoría           |" << endl;
                cout << "|------------------------------------------------|" << endl<<endl;
            } catch (exception &e) {
                cout << "|------------------------------------------------|" << endl<<endl;
                cout << "|      Este videojuego ya se encuentra           |" << endl;
                cout << "|      enlazado a la categoría seleccionada.     |" << endl;
                cout << "|------------------------------------------------|" << endl<<endl;
            }
        }
    } while (seguirAgregandoOtro == 's' || seguirAgregandoOtro == 'S');


    cout << "|------------------------------------------------|" << endl<<endl<<endl;

    // MOSTRAR INFORMACION DEL VIDEOJUEGO
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|               PUBLICAR VIDEOJUEGO              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    Videojuego * videojuegoEnProceso= fabrica->getInstance()->getInterfaceV()->getVideojuegoSeleccionado();
    cout << "Nombre: " << videojuegoEnProceso->getNombre() << endl;
    cout << "Descripción: " << videojuegoEnProceso->getDescripcion() << endl;
    cout << "Costo Mensual: " << costoMensual << endl;
    cout << "Costo Trimestral: " << costoTrimestral << endl;
    cout << "Costo Anual: " << costoAnual << endl;
    cout << "Costo Vitalicia: " << costoVitalicia << endl;
    cout << "Categorias: " << endl;
    IIterator *iterCat = fabrica->getInstance()->getInterfaceC()->obtenerCategoriasVideojuego(videojuegoEnProceso->getNombre())->getIteratorObj();
    while (iterCat->hasNext()) {
        Categoria *categoria = dynamic_cast<Categoria*>(iterCat->next());
        cout << "\t*" << categoria->getNombre() << endl;
    }
    delete iterCat;

    cout<<endl<<"|------------------------------------------------|"<<endl<<endl;

    // CONFIRMAR LA PUBLICACION DEL VIDEOJUEGO
    int opcion = 0;
    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|               PUBLICAR VIDEOJUEGO              |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar videojuego                        |" << endl;
        cout << "| 2. Cancelar videojuego                         |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                fabrica->getInstance()->getInterfaceV()->confirmarVideojuego();
                break;
            case 2:
                fabrica->getInstance()->getInterfaceV()->cancelarVideojuego();
                break;
            default:
                cout << "Opción inválida!" << endl;
                break;
        }
    }while(opcion!=1 && opcion !=2);

};