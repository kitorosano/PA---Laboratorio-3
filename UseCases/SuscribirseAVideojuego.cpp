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

    IDictionary *videojuegosSuscripciones = fabrica->getInstance()->getInterfaceD()->listarVideojuegoSuscripciones();
    IIterator *iterVideojuegos = videojuegosSuscripciones->getIteratorObj();
    IDictionary *videojuegosSuscritos = fabrica->getInstance()->getInterfaceD()->listarNombreVideojuegosSuscritos();

    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|              VIDEOJUEGOS SUSCRITOS             |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    while(iterVideojuegos->hasNext()) {
        DT_VideojuegoSuscripciones *videojuego = (DT_VideojuegoSuscripciones *)iterVideojuegos->next();
        if(videojuegosSuscritos->member(new KeyString(videojuego->getNombre()))) {
            cout<<"| "<<videojuego->toString()<<" |"<<endl;
        }
    }
    cout<<"|------------------------------------------------|"<<endl<<endl;

    iterVideojuegos = videojuegosSuscripciones->getIteratorObj(); // obtener un nuevo iterador para no perder el anterior
    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|            VIDEOJUEGOS DISPONIBLES             |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    while(iterVideojuegos->hasNext()) {
        DT_VideojuegoSuscripciones *videojuego = (DT_VideojuegoSuscripciones *)iterVideojuegos->next();
        if(!videojuegosSuscritos->member(new KeyString(videojuego->getNombre()))) {
            cout<<"| "<<videojuego->toString()<<" |"<<endl;
        }
    }
    delete iterVideojuegos;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el nombre del videojuego que desea suscribirse: ";
    string nombreVideojuego;
    cin>>nombreVideojuego;

    if(videojuegosSuscritos->member(new KeyString(nombreVideojuego))) {
        cout<<"|------------------------------------------------|"<<endl<<endl;
        cout << "Ya estas suscrito a este videojuego con una suscripcion ";
        IIterator* iterDatosSuscripciones = fabrica->getInstance()->getInterfaceD()->getDatosSuscripciones()->getIteratorObj();
        while(iterDatosSuscripciones->hasNext()) {
            DatosSuscripcion *datosSuscripcion = (DatosSuscripcion *)iterDatosSuscripciones->next();
            string uNickname = dynamic_cast<Jugador *>(fabrica->getInstance()->getInterfaceU()->getUsuarioLogeado())->getNickname();
            // BUSCAR EL DATO SUSCRIPCION DE ESTE JUGADOR CON ESTE VIDEOJUEGO
            if(datosSuscripcion->getNickName() == uNickname && datosSuscripcion->getSuscripcion()->getVideojuego()->getNombre() == nombreVideojuego) {
                if(datosSuscripcion->getSuscripcion()->getPeriodoValidez() == E_PeriodoValidez::VITALICIA){
                    cout << "VITALICIA" << endl;
                    cout << "|------------------------------------------------|" << endl;
                    return;
                }
                cout << Str_PeriodoValidez[datosSuscripcion->getSuscripcion()->getPeriodoValidez()] << endl;

                cout << "|------------------------------------------------|" << endl;
                cout << "Deseas renovar la suscripcion? (s/n): ";
                string respuesta;
                cin >> respuesta;

                if(respuesta == "n") {
                    cout << "|------------------------------------------------|" << endl;
                    return;
                }
                // CONTINUA ABAJO CON LA CREACION DEL NUEVO DATO SUSCRIPCION
                break;
            }
        }
        delete iterDatosSuscripciones;
    }

    // CREACION DEL NUEVO DATO SUSCRIPCION
    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|            SUSCRIBIRSE A VIDEOJUEGO            |"<<endl;
    cout<<"|------------------------------------------------|" << endl;
    cout<<"| 1. Suscripción por 1 mes                       |" << endl;
    cout<<"| 2. Suscripción por 3 mes                       |" << endl;
    cout<<"| 3. Suscripción por 1 año                       |" << endl;
    cout<<"| 4. Suscripción de por vida                     |" << endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el periodo de validez de la Suscripción: ";
    int intPeriodoValidez;
    cin >> intPeriodoValidez;
    E_PeriodoValidez periodoValidez = (E_PeriodoValidez)intPeriodoValidez;

    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|            SUSCRIBIRSE A VIDEOJUEGO            |"<<endl;
    cout<<"|------------------------------------------------|" << endl;
    cout<<"| 1. Pagar con tarjeta                           |" << endl;
    cout<<"| 2. Pagar con PayPal                            |" << endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese el metodo de pago: ";
    int intMetodoPago;
    cin >> intMetodoPago;
    E_MetodoPago metodoPago = (E_MetodoPago)intMetodoPago;

    // BUSCO LA SUSCRIPCION DEL VIDEOJUEGO CUYO PERIODO DE VALIDEZ SEA EL ELEGIDO POR EL USUARIO
    IIterator* iterSuscripciones = fabrica->getInstance()->getInterfaceV()->getSuscripciones()->getIteratorObj();
    while (iterSuscripciones->hasNext()) {
        Suscripcion *suscripcion = dynamic_cast<Suscripcion *>(iterSuscripciones->next());
        if(suscripcion->getVideojuego()->getNombre() == nombreVideojuego && suscripcion->getPeriodoValidez()==periodoValidez) {
            fabrica->getInstance()->getInterfaceD()->crearDatosSuscripcion(suscripcion->getId(), metodoPago);
            break;
        }
    }
    delete iterSuscripciones;
    cout << "|------------------------------------------------|" << endl;

    // CONFIRMAR LA SUSCRIPCION DEL VIDEOJUEGO
    int opcion = 0;
    do {
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"|            SUSCRIBIRSE A VIDEOJUEGO            |"<<endl;
        cout<<"|------------------------------------------------|" << endl;
        cout<<"| 1. Confirmar suscripción                        |" << endl;
        cout<<"| 2. Cancelar suscripción                         |" << endl;
        cout<<"|------------------------------------------------|" << endl << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                fabrica->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();
                break;
            case 2:
                fabrica->getInstance()->getInterfaceD()->cancelarDatosSuscripcion();
                break;
            default:
                cout << "Opción inválida!" << endl;
                break;
        }
    }while(opcion!=1 && opcion !=2);

};
