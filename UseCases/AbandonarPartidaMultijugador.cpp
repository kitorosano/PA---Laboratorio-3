//
// Created by esteban.rosano on 27/6/2022.
//

#include "Factory/Factory.h"
#include <iostream>
#include <string>
#include "ColeccionesG/IDictionary.h"
#include "Classes/JugadorMultijugador.h"
#include "AbandonarPartidaMultijugador.h"
#include "ColeccionesG/KeyInt.h"
using namespace std;

void AbandonarPartidaMultijugador() {
    Factory * factory;
    bool trans, repetir;
    int idpartida;
    Jugador* jugadorLogueado = dynamic_cast<Jugador*>(factory->getInstance()->getInterfaceU()->getUsuarioLogeado());

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|        ABANDONAR PARTIDA MULTIJUGADOR          |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    IDictionary* lista = factory->getInstance()->getInterfaceP()->listarPartidasMultijugadorUnidasNoFinalizadas();
    Multijugador* multi = NULL;
    JugadorMultijugador* jugadorMulti = NULL;
    IIterator *it = lista->getIteratorObj();

    while(it->hasNext()){
        multi = dynamic_cast<Multijugador *>(it->getCurrent());
        cout<<"ID: "<<multi->getIdPartida()<<endl;
        cout << "Fecha Comienzo: " << multi->getFechaComienzo()->toString() << endl;
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
        while(it2->hasNext()) {
            jugadorMulti = dynamic_cast<JugadorMultijugador *>(it2->getCurrent());
            cout << "      " << jugadorMulti->getJugador()->getNickname() << endl;
            it2->next();
        }
        cout << "|------------------------------------------------|" << endl << endl;
        it->next();
    }

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|        ABANDONAR PARTIDA MULTIJUGADOR          |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;

    do {
        cout << "Ingrese ID de la partida:" << endl;
        cin >> idpartida;
        repetir = false;
        KeyInt *keyidpartida = new KeyInt(idpartida);
        if (lista->member(keyidpartida)) {
            factory->getInstance()->getInterfaceP()->confirmarAbandonoPartida(idpartida,jugadorLogueado,new DT_Fecha());
        } else {
            cout << idpartida << " NO ES VALIDO (no esta en la lista proporcionada anteriormente)"<< endl << endl;
            repetir = true;
        }
    } while (repetir == true);
}
