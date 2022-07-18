//
// Created by esteban.rosano on 27/6/2022.
//

#include "SuscribirseAVideojuego.h"
#include "Factory/Factory.h"
#include "DataTypes/DT_VideojuegoSuscripciones.h"
#include <iostream>
#include <string>

void SuscribirseAVideojuego() {
    Factory *fabrica;
    Jugador *jugadorLogueado = dynamic_cast<Jugador*>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado());

    IDictionary *videojuegosSuscripciones = fabrica->getInstance()->getInterfaceD()->listarVideojuegoSuscripciones();
    IIterator *iterVideojuegos = videojuegosSuscripciones->getIteratorObj();
    IDictionary *videojuegosSuscritos = fabrica->getInstance()->getInterfaceD()->listarNombreVideojuegosSuscritos(jugadorLogueado);

    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|              VIDEOJUEGOS SUSCRITOS             |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    while(iterVideojuegos->hasNext()) {
        DT_VideojuegoSuscripciones *videojuego = (DT_VideojuegoSuscripciones *)iterVideojuegos->next();
        cout<<videojuego->toString()<<endl;
    }
    delete iterVideojuegos;

    string nombreVideojuego = "";;
    cin.ignore();
    while(!videojuegosSuscripciones->member(new KeyString(nombreVideojuego))){
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"| Ingrese el nombre del videojuego que desea suscribirse correctamente: ";
        getline(cin,nombreVideojuego);
        cout<<endl;
    }

    if(videojuegosSuscritos->member(new KeyString(nombreVideojuego))) {
        cout<<"|------------------------------------------------|"<<endl;
        cout << "| Ya estas suscrito a este videojuego con una suscripcion " ;
        IIterator* iterDatosSuscripciones = fabrica->getInstance()->getInterfaceD()->getDatosSuscripciones()->getIteratorObj();
        while(iterDatosSuscripciones->hasNext()) {
            DatosSuscripcion *datosSuscripcion = dynamic_cast<DatosSuscripcion*>(iterDatosSuscripciones->next());
            // BUSCAR EL DATO SUSCRIPCION DE ESTE JUGADOR CON ESTE VIDEOJUEGO
            if(datosSuscripcion->getNickName() == jugadorLogueado->getNickname() && datosSuscripcion->getSuscripcion()->getVideojuego()->getNombre() == nombreVideojuego) {
                if(datosSuscripcion->getSuscripcion()->getPeriodoValidez() == E_PeriodoValidez::VITALICIA){
                    cout << "VITALICIA" << endl;
                    cout << "|------------------------------------------------|" << endl;
                    return;
                }
                cout << Str_PeriodoValidez[datosSuscripcion->getSuscripcion()->getPeriodoValidez()] << endl;

                cout << "|------------------------------------------------|" << endl;
                cout << "| Deseas renovar la suscripcion? (s/n): ";
                string respuesta;
                cin >> respuesta;

                if(respuesta == "n") {
                    cout << "|------------------------------------------------|" << endl;
                    return;
                }
                // CONTINUA ABAJO CON LA CREACION DEL NUEVO DATO SUSCRIPCION
                goto creacion_nuevo_datos_suscripcion;
            }
        }
        delete iterDatosSuscripciones;
    }
    else {
        creacion_nuevo_datos_suscripcion:
        // CREACION DEL NUEVO DATO SUSCRIPCION
        int intPeriodoValidez;
        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|            SUSCRIBIRSE A VIDEOJUEGO            |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Suscripcion por 1 mes                       |" << endl;
            cout << "| 2. Suscripcion por 3 mes                       |" << endl;
            cout << "| 3. Suscripcion por 1 año                       |" << endl;
            cout << "| 4. Suscripcion de por vida                     |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cout << "Ingrese el periodo de validez de la Suscripcion: ";
            cin >> intPeriodoValidez;
            if(intPeriodoValidez < 1 || intPeriodoValidez > 4) {
                cout << endl;
                cout << "|------------------------------------------------|" << endl;
                cout << "|  El periodo de validez ingresado no es valido  |" << endl;
                cout << "|------------------------------------------------|" << endl;
            }
        } while(intPeriodoValidez < 1 || intPeriodoValidez > 4);
        E_PeriodoValidez periodoValidez = (E_PeriodoValidez)(intPeriodoValidez-1);

        int intMetodoPago;
        do {
            cout << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|            SUSCRIBIRSE A VIDEOJUEGO            |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Pagar con tarjeta                           |" << endl;
            cout << "| 2. Pagar con PayPal                            |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| Ingrese el metodo de pago: ";
            cin >> intMetodoPago;

            if(intMetodoPago < 1 || intMetodoPago > 2) {
                cout << endl;
                cout << "|------------------------------------------------|" << endl;
                cout << "|    El metodo de pago ingresado no es valido    |" << endl;
                cout << "|------------------------------------------------|" << endl;
            }
        } while(intMetodoPago < 1 || intMetodoPago > 2);
        E_MetodoPago metodoPago = (E_MetodoPago)(intMetodoPago-1);

        // BUSCO LA SUSCRIPCION DEL VIDEOJUEGO CUYO PERIODO DE VALIDEZ SEA EL ELEGIDO POR EL USUARIO
        IIterator* iterSuscripciones = fabrica->getInstance()->getInterfaceV()->getSuscripciones()->getIteratorObj();
        while (iterSuscripciones->hasNext()) {
            Suscripcion *suscripcion = dynamic_cast<Suscripcion *>(iterSuscripciones->next());
            if(suscripcion->getVideojuego()->getNombre() == nombreVideojuego && suscripcion->getPeriodoValidez()==periodoValidez) {
                fabrica->getInstance()->getInterfaceD()->crearDatosSuscripcion(jugadorLogueado->getNickname(), suscripcion->getId(), metodoPago);
                break;
            }
        }
        delete iterSuscripciones;

        // CONFIRMAR LA SUSCRIPCION DEL VIDEOJUEGO
        int opcion = 0;
        do {
            cout << endl;
            cout<<"|------------------------------------------------|"<<endl;
            cout<<"|            SUSCRIBIRSE A VIDEOJUEGO            |"<<endl;
            cout<<"|------------------------------------------------|" << endl;
            cout<<"| 1. Confirmar suscripcion                        |" << endl;
            cout<<"| 2. Cancelar suscripcion                         |" << endl;
            cout<<"|------------------------------------------------|" << endl;
            cin >> opcion;

            switch (opcion) {
                case 1:
                    fabrica->getInstance()->getInterfaceD()->confirmarDatosSuscripcion(new DT_Fecha());
                    cout<<endl;
                    cout << "|------------------------------------------------|" << endl;
                    cout << "|              SUSCRIPCION EXITOSA!!             |" << endl;
                    cout << "|------------------------------------------------|" << endl<< endl;
                    break;
                case 2:
                    fabrica->getInstance()->getInterfaceD()->cancelarDatosSuscripcion();
                    cout<<endl;
                    cout << "|------------------------------------------------|" << endl;
                    cout << "|             SUSCRIPCION CANCELADA              |" << endl;
                    cout << "|------------------------------------------------|" << endl<< endl;
                    break;
                default:
                    cout << "Opcion invalida!";
                    break;
            }
        }while(opcion!=1 && opcion !=2);
    }
};
