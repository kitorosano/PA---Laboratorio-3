//
// Created by esteban.rosano on 27/6/2022.
//

#include "IniciarPartida.h"
#include "/Factory/Factory.h"
#include <iostream>
#include <string>
#include "DataTypes/DT_PartidasIndividualesFinalizadas.h"
#include "ColeccionesG/IDictionary.h"
using namespace std;


void IniciarPartida() {
    Factory * factory;
    string nombreVideojuego,nickname,descripcion,empresa;
    Videojuego* videojuego;
    int opcion, opcion2, idpartida;
    int deseaReingresar=0;
    bool trans;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                 INICIAR PARTIDA                |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    factory->getInterfaceD()->listarNombreVideojuegosSuscritos(); // muestra los nombres de los videojuegos del jugador logeado

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                 INICIAR PARTIDA                |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese nombre videoJuego:"<<endl;
    cin>>nombreVideojuego;
    videojuego = factory->getInterfaceV()->obtenerVideojuegoPorNombre(nombreVideojuego);
    factory->getInterfaceV()->seleccionarVideoJuego(videojuego->getId());

    do {
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 INICIAR PARTIDA                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Individual                                  |" << endl;
        cout << "| 2. Multijugador                                |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion;
        if(opcion !=1 && opcion !=2)
            throw invalid_argument("Debe ingresar una opcion!");
    }while(opcion !=1 && opcion !=2);


    if(opcion==1) {
        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|          INICIAR PARTIDA INDIVIDUAL            |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Es una continuacion                         |" << endl;
            cout << "| 2. No es una continuacion                      |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cin >> opcion2;
        }while(opcion2 !=1 && opcion2 !=2);

        if(opcion2==1){
            IDictionary* partidasFinalizadas = factory->getInterfaceP()->listarHistorialPartidasFinalizadasCronologicamente();
            DT_PartidasIndividualesFinalizadas * dt_partida = NULL;
            IIterator *it = partidasFinalizadas->getIteratorObj();
            while(it->hasNext()){
                dt_partida = dynamic_cast<DT_PartidasIndividualesFinalizadas *>(it->getCurrent());
                cout<<"ID: "<<dt_partida->getIdPartida()<<endl;
                cout<<"Fecha Comienzo: "<<dt_partida->getFecha()<<endl;
                cout<<"Hora Comienzo: "<<dt_partida->getHoraComienzo()<<endl;
                cout<<"Duracion: "<<dt_partida->getHorasPartida()<<endl;
                cout << "|------------------------------------------------|" << endl << endl;

                it->next();
            }
            cout<<"|------------------------------------------------|"<<endl;
            cout<<"|      CONTINUAR UNA PARTIDA INDIVIDUAL          |"<<endl;
            cout<<"|------------------------------------------------|"<<endl<<endl;
            cout<<"Ingrese ID de la partida a continuar:"<<endl;
            cin>>idpartida;
            factory->getInterfaceP()->continuarPartidaIndividual(idpartida);

        }else if (opcion2==2){
            cout<<"Se creara una nueva partida individual"<<endl<<endl;
        }
    }
    else if(opcion==2){
        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|          INICIAR PARTIDA MULTIJUGADOR          |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Es transmitida en vivo                      |" << endl;
            cout << "| 2. No es transmitida en vivo                   |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cin >> opcion2;
        }while(opcion2 !=1 && opcion2 !=2);

        if(opcion2==1){
            trans = true;
        }else if(opcion2==2){
            trans = false;
        }
        factory->getInterfaceD()->listarNicknameJugadoresSuscritos();

        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|  AGREGAR JUGADOR A LA PARTIDA MULTIJUGADOR     |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout<<"Ingrese el nickname del jugador:"<<endl;
            cin >> nickname;
            cout << "|------------------------------------------------|" << endl;
            cout << "| AGREGAR OTRO JUGADOR A LA PARTIDA MULTIJUGADOR |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. SI                                          |" << endl;
            cout << "| 2. NO                                          |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cin >> opcion2;
        }while(opcion2 !=1 && opcion2 !=2);
    }

    do{
        cout << "|------------------------------------------------|" << endl;
        cout << "|                 INICIAR PARTIDA                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| 1. Confirmar                                   |" << endl;
        cout << "| 2. Cancelar                                    |" << endl;
        cout << "|------------------------------------------------|" << endl << endl;
        cin >> opcion;
            if(opcion !=1 && opcion !=2)
                throw invalid_argument("Debe ingresar una opcion!");

    }while(opcion!=1 && opcion !=2);

    if(opcion==1){
        factory->getInstance()->getInterfaceP()->confirmarPartida();
    }
    else if(opcion==2){
        factory->getInstance()->getInterfaceP()->cancelarIniciarPartida();
    }

}
