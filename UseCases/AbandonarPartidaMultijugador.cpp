//
// Created by esteban.rosano on 27/6/2022.
//

#include "/Factory/Factory.h"
#include <iostream>
#include <string>
#include "ColeccionesG/IDictionary.h"
#include "Classes/JugadorMultijugador.h"
#include "AbandonarPartidaMultijugador.h"
using namespace std;

void AbandonarPartidaMultijugador() {
    Factory * factory;
    bool trans;
    int idpartida;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|        ABANDONAR PARTIDA MULTIJUGADOR          |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    IDictionary* lista = factory->getInterfaceP()->listarPartidasMultijugadorUnidasNoFinalizadas();
    Multijugador* multi = NULL;
    JugadorMultijugador* jugadorMulti = NULL;
    IIterator *it = lista->getIteratorObj();

    while(it->hasNext()){
        multi = dynamic_cast<Multijugador *>(it->getCurrent());
        cout<<"ID: "<<multi->getIdPartida();
        cout<<"Fecha Comienzo: "<<multi->getFecha().getDate()<<endl;
        cout<<"Hora Comienzo: "<<multi->getHoraComienzo().getTime()<<endl;
        cout<<"Nombre Videojuego: "<<multi->getVideojuego()->getNombre()<<endl;
        trans = multi->isTransmitidaEnVivo();
        if(trans){
            cout<<"Transmitida en vivo: Si"<<endl;
        }else{
            cout<<"Transmitida en vivo: No"<<endl;
        }
        cout<<"Jugador Iniciador: "<<multi->getJugador()->getNickname()<<endl;
        IIterator *it2 = multi->getJugadoresEnLaPartida()->getIteratorObj();
        cout<<"Jugadores en la partida: "<<endl;
        while(it->hasNext()) {
            jugadorMulti = dynamic_cast<JugadorMultijugador *>(it->getCurrent());
            cout << jugadorMulti->getJugador()->getNickname() << endl;
            it->next();
        }
        cout << "|------------------------------------------------|" << endl << endl;
        it->next();
    }

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|        ABANDONAR PARTIDA MULTIJUGADOR          |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese ID de la partida:"<<endl;
    cin>>idpartida;
    factory->getInterfaceP()->confirmarAbandonoPartida(idpartida);
}
