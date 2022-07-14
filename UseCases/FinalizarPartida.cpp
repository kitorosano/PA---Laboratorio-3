//
// Created by esteban.rosano on 27/6/2022.
//
#include "Factory/Factory.h"
#include <iostream>
#include <string>
#include "ColeccionesG/IDictionary.h"
#include "Classes/Partida.h"
#include "Classes/Individual.h"
#include "Classes/Multijugador.h"
#include "Classes/JugadorMultijugador.h"
#include "FinalizarPartida.h"
using namespace std;

void FinalizarPartida() {
    Factory * factory;
    bool trans;
    int idpartida;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|          FINALIZAR PARTIDA                     |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    IDictionary* lista = factory->getInterfaceP()->listarPartidasIniciadasNoFinalizadas();
    Partida* partida = NULL;
    Individual* individual = NULL;
    Multijugador* multijugador = NULL;
    JugadorMultijugador* jugadorMulti = NULL;
    IIterator *it = lista->getIteratorObj();

    while(it->hasNext()){
        partida = dynamic_cast<Partida *>(it->getCurrent());
        individual = dynamic_cast<Individual *>(it->getCurrent());
        multijugador = dynamic_cast<Multijugador *>(it->getCurrent());
        cout<<"ID: "<<partida->getIdPartida();
        cout<<"Fecha Comienzo: "<<partida->getFecha().getDate()<<endl;
        cout<<"Nombre Videojuego: "<<partida->getVideojuego()->getNombre()<<endl;

        if (individual){
            if (individual->getContPartAnterior() == NULL){
                cout<<"Continuacion de otra partida: No"<<endl;
            }else {
                cout<<"Continuacion de otra partida: Si"<<endl;
            }
        }
        if (multijugador){
            trans = multijugador->isTransmitidaEnVivo();
            if(trans){
                cout<<"Transmitida en vivo: Si"<<endl;
            }else{
                cout<<"Transmitida en vivo: No"<<endl;
            }
            IIterator *it2 = multijugador->getJugadoresEnLaPartida()->getIteratorObj();
            cout<<"Jugadores en la partida: "<<endl;
            while(it->hasNext()) {
                jugadorMulti = dynamic_cast<JugadorMultijugador *>(it->getCurrent());
                cout << jugadorMulti->getJugador()->getNickname() << endl;
                it->next();
            }
        }
        cout << "|------------------------------------------------|" << endl << endl;
        it->next();
    }

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|          FINALIZAR PARTIDA                     |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese ID de la partida:"<<endl;
    cin>>idpartida;
    factory->getInterfaceP()->confirmarFinalizarPartida(idpartida);
}
