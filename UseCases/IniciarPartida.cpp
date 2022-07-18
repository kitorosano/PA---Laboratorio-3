//
// Created by esteban.rosano on 27/6/2022.
//

#include "IniciarPartida.h"
#include "Factory/Factory.h"
#include <iostream>
#include <string>
#include "DataTypes/DT_PartidasIndividualesFinalizadas.h"
#include "DataTypes/DT_NombreDescripcion.h"
#include "ColeccionesG/IDictionary.h"
#include "ColeccionesG/KeyInt.h"
using namespace std;


void IniciarPartida() {
    Factory * factory;
    string nombreVideojuego,nickname,descripcion,empresa;
    Videojuego* videojuego;
    Jugador *jugadorLogueado = dynamic_cast<Jugador*>(factory->getInstance()->getInterfaceU()->getUsuarioLogeado());
    int opcion, opcion2, idpartida;
    //int deseaReingresar=0;
    bool trans, repetir, repetir2, repetir3;
    bool validar = false;


    cout << endl << endl << endl << endl;
    cout << "|------------------------------------------------|" << endl;
    cout << "|                 INICIAR PARTIDA                |" << endl;
    cout << "|------------------------------------------------|" << endl << endl;
    cout << "| Videojuegos: " << endl;
    IDictionary *listaDeNombresDeVideojuegos = factory->getInstance()->getInterfaceD()->listarNombreVideojuegosSuscritos(jugadorLogueado);
    IIterator *iter = listaDeNombresDeVideojuegos->getIteratorObj();
    while (iter->hasNext()) {
        DT_NombreDescripcion *nombreVideojuego = dynamic_cast<DT_NombreDescripcion *>(iter->next());
        cout << "              | " << nombreVideojuego->getNombre() << endl;
    }

    cout << "|------------------------------------------------|" << endl;
    do{
        cout << "Ingrese nombre videojuego al que desea jugar:";
        cin >> nombreVideojuego;
        repetir = false;
        KeyString *nombrevideojuego = new KeyString(nombreVideojuego);
        if (listaDeNombresDeVideojuegos->member(nombrevideojuego)) {
            factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(nombreVideojuego);
        } else {
            cout << "ATENCION: '"<< nombreVideojuego <<"' NO ES VALIDO (no esta en la lista proporcionada anteriormente)" << endl << endl;
            repetir = true;
        }
    }while(repetir == true);



    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|            ELEGIR TIPO DE PARTIDA              |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Individual                                  |" << endl;
        cout << "| 2. Multijugador                                |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cout<<"Ingrese una opcion:";
        cin >> opcion;
        if(opcion !=1 && opcion !=2)
            cout<<"Debe ingresar una opcion!"<<endl;
    }while(opcion !=1 && opcion !=2);

//INDIVIDUAL
    if(opcion==1) {
        do {
            cout<<endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|          INICIAR PARTIDA INDIVIDUAL            |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Es una continuacion                         |" << endl;
            cout << "| 2. No es una continuacion                      |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cout<<"Ingrese una opcion:";
            cin >> opcion2;
        }while(opcion2 !=1 && opcion2 !=2);

//        CONTINUACION
        if(opcion2==1){
            IDictionary* partidasFinalizadas = factory->getInstance()->getInterfaceP()->listarHistorialPartidasFinalizadasCronologicamente(jugadorLogueado);
            if (partidasFinalizadas->size() > 0){

                DT_PartidasIndividualesFinalizadas * dt_partida = NULL;
                IIterator *it = partidasFinalizadas->getIteratorObj();

                while(it->hasNext()){
                    dt_partida = dynamic_cast<DT_PartidasIndividualesFinalizadas *>(it->getCurrent());
                    cout << "ID: "<<dt_partida->getIdPartida()<<endl;
                    cout << "Fecha Comienzo: " << dt_partida->getFechaComienzo()->toString() << endl;
                    cout << "Duracion: "<<dt_partida->getHorasPartida()<<endl;
                    cout << "|------------------------------------------------|" << endl << endl;

                    it->next();
                }
                cout<<endl;
                cout<<"|------------------------------------------------|"<<endl;
                cout<<"|      CONTINUAR UNA PARTIDA INDIVIDUAL          |"<<endl;
                cout<<"|------------------------------------------------|"<<endl<<endl;
                do{
                    cout<<"Ingrese ID de la partida a continuar:";
                    cin>>idpartida;
                    repetir3 = false;
                    KeyInt *id = new KeyInt(idpartida);
                    if(partidasFinalizadas->member(id)){
                        factory->getInstance()->getInterfaceP()->continuarPartidaIndividual(idpartida, jugadorLogueado);
                        validar = true;
                    }else{
                        cout << "ATENCION: '"<< idpartida <<"' NO ES VALIDO (no esta en la lista proporcionada anteriormente)" << endl << endl;
                        repetir3 = true;
                    }

                }while(repetir3 == true);

            }else{
                cout<<"No tiene ninguna partida finalizada para el videojuego: "<<nombreVideojuego<<endl;
            }
        }
//        NUEVA PARTIDA INDIVIDUAL
        else if (opcion2==2){
            factory->getInstance()->getInterfaceP()->nuevaPartidaIndividual(jugadorLogueado);
            validar = true;
        }
    }
//    MULTIJUGADOR
    else if(opcion==2){
        do {
            cout<<endl<<endl<<endl<<endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|          INICIAR PARTIDA MULTIJUGADOR          |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Es transmitida en vivo                      |" << endl;
            cout << "| 2. No es transmitida en vivo                   |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cout<<"Ingrese una opcion:";
            cin >> opcion2;
        }while(opcion2 !=1 && opcion2 !=2);

        if(opcion2==1){
            trans = true;
        }else if(opcion2==2){
            trans = false;
        }
        factory->getInstance()->getInterfaceP()->nuevaPartidaMultijugador(jugadorLogueado, trans);
        validar = true;

        do {
            cout<<endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|  AGREGAR JUGADOR A LA PARTIDA MULTIJUGADOR     |" << endl;
            cout << "|------------------------------------------------|" << endl;
            IDictionary * listaDeJugadores = factory->getInstance()->getInterfaceD()->listarNicknameJugadoresSuscritosConRetorno();
            if (listaDeJugadores != NULL) {
                DT_NombreDescripcion *dt_nickname = NULL;
                IIterator *it = listaDeJugadores->getIteratorObj();
                while (it->hasNext()) {
                    dt_nickname = dynamic_cast<DT_NombreDescripcion *>(it->getCurrent());
                    cout << dt_nickname->getNombre() << endl;
                    it->next();
                }
            }
            cout << "|------------------------------------------------|" << endl;
            do{
                cout << "| Ingrese el nickname del jugador:"<<endl;
                cin >> nickname;
                repetir2 = false;
                KeyString *nick = new KeyString(nickname);
                if (listaDeJugadores->member(nick)) {
                    factory->getInstance()->getInterfaceP()->ingresarNicknameALaPartida(nickname);
                } else {
                    cout << "ATENCION: '"<< nickname <<"' NO ES VALIDO (no esta en la lista proporcionada anteriormente)" << endl << endl;
                    repetir2 = true;
                }
            }while(repetir2 == true);


            cout << "|------------------------------------------------|" << endl;
            cout << "| AGREGAR OTRO JUGADOR A LA PARTIDA MULTIJUGADOR |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. SI                                          |" << endl;
            cout << "| 2. NO                                          |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cout<<"Ingrese una opcion:";
            cin >> opcion2;
        }while(opcion2 ==1);
    }

    if(validar){
        do{
            cout<<endl<<endl<<endl<<endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|                 INICIAR PARTIDA                |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Confirmar                                   |" << endl;
            cout << "| 2. Cancelar                                    |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cout<<"Ingrese una opcion:";
            cin >> opcion;
            if(opcion !=1 && opcion !=2)
                cout<<"Debe ingresar una opcion!"<<endl;

        }while(opcion!=1 && opcion !=2);

        if(opcion==1)
            factory->getInstance()->getInterfaceP()->confirmarPartida(new DT_Fecha());
        else if(opcion==2)
            factory->getInstance()->getInterfaceP()->cancelarIniciarPartida();
    }



}
