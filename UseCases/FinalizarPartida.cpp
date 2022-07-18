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
#include "ColeccionesG/KeyInt.h"
using namespace std;

void FinalizarPartida() {
    Factory *factory;
    bool trans, repetir;
    int idpartida;
    Jugador *jugadorLogueado = dynamic_cast<Jugador *>(factory->getInstance()->getInterfaceU()->getUsuarioLogeado());

    cout << "|------------------------------------------------|" << endl;
    cout << "|          FINALIZAR PARTIDA                     |" << endl;
    cout << "|------------------------------------------------|" << endl << endl;
    IDictionary *lista = factory->getInstance()->getInterfaceP()->listarPartidasIniciadasNoFinalizadas(jugadorLogueado);
    Partida *partida = NULL;
    Individual *individual = NULL;
    Multijugador *multijugador = NULL;
    JugadorMultijugador *jugadorMulti = NULL;
    IIterator *it = lista->getIteratorObj();

    while (it->hasNext()) {
        partida = dynamic_cast<Partida *>(it->getCurrent());
        cout << "ID: " << partida->getIdPartida() << endl;
        cout << "Fecha Comienzo: " << partida->getFechaComienzo()->toString() << endl;
        cout << "Nombre Videojuego: " << partida->getVideojuego()->getNombre() << endl;

        individual = dynamic_cast<Individual *>(it->getCurrent());
        multijugador = dynamic_cast<Multijugador *>(it->getCurrent());
        if (individual) {
            if (individual->getContPartAnterior() == NULL) {
                cout << "Continuacion de otra partida: No" << endl;
            } else {
                cout << "Continuacion de otra partida: Si" << endl;
            }
        }
        if (multijugador) {
            trans = multijugador->isTransmitidaEnVivo();
            if ((trans) || (trans == 240)) {
                cout << "Transmitida en vivo: Si" << endl;
            } else {
                cout << "Transmitida en vivo: No" << endl;
            }
            IDictionary *jugadoresDeLaPartida = multijugador->getJugadoresEnLaPartida();
            IIterator *it2 = jugadoresDeLaPartida->getIteratorObj();
            // IIterator *it = lista->             getIteratorObj()
            cout << "Jugadores en la partida: " << endl;
            while (it2->hasNext()) {
                jugadorMulti = dynamic_cast<JugadorMultijugador *>(it2->getCurrent());
                cout << "      " << jugadorMulti->getJugador()->getNickname() << endl;
                it2->next();
            }
        }
        cout << "|------------------------------------------------|" << endl << endl;
        it->next();
    }

    cout << "|------------------------------------------------|" << endl;
    cout << "|          FINALIZAR PARTIDA                     |" << endl;
    cout << "|------------------------------------------------|" << endl << endl;

    do {
        cout << "Ingrese ID de la partida:" << endl;
        cin >> idpartida;
        repetir = false;
        KeyInt *keyidpartida = new KeyInt(idpartida);
        if (lista->member(keyidpartida)) {
            factory->getInstance()->getInterfaceP()->confirmarFinalizarPartida(idpartida, jugadorLogueado, new DT_Fecha());
        } else {
            cout << idpartida << " NO ES VALIDO (no esta en la lista proporcionada anteriormente)"<< endl << endl;
            repetir = true;
        }
    } while (repetir == true);

}
