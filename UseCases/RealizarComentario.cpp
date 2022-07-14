//
// Created by esteban.rosano on 27/6/2022.
//

#include "RealizarComentario.h"
#include "/Factory/Factory.h"
#include <iostream>
#include <string>
using namespace std;
void RealizarComentario(){
    Factory * factory;

    int opcion,id;
    IDictionary* aux=NULL;
    IDictionary* aux_jugadores_unidos=NULL;
    IDictionary* aux_comentario=NULL;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|              REALIZAR COMENTARIO               |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    aux=factory->getInstance()->getInterfaceP()->listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo();
    if(aux){
        IIterator *it = aux->getIteratorObj();
        while (it->hasNext()) {
            DT_MultijugadorVideojuego* dt_multijugador_videojuego = (DT_MultijugadorVideojuego*) (it->getCurrent());
            cout<<"----------------------------------------------------";
            cout<<"Id partida:"<<dt_multijugador_videojuego->getIdPartida()<<endl;
            cout<<"Nombre del videojuego "<<dt_multijugador_videojuego->getNombreVideojuego()<<endl;
            cout<<"Jugador Iniciador "<<dt_multijugador_videojuego->getJugadorIniciador()<<endl;
            cout<<"Jugadores Unidos: "<<endl;
            aux_jugadores_unidos=dt_multijugador_videojuego->getJugadoresUnidos();
            if(aux_jugadores_unidos){
                IIterator *it2 = aux_jugadores_unidos->getIteratorObj();
                while (it2->hasNext()) {
                    Jugador* aux_jug = (Jugador *) (it2);
                    cout<<"\t"<< "- " <<aux_jug->getNickname()<< endl;
                    it2->next();
                }
            }
            it->next();
        }
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"|    -Seleccione la partida ingresando su id     |"<<endl;
        cout<<"|------------------------------------------------|"<<endl<<endl;
        cin>>id;
        factory->getInstance()->getInterfaceP()->seleccionarPartida(id);
        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|              REALIZAR COMENTARIO               |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|1)Realizar un nuevo comentario                  |" << endl;
            cout << "|2)Responder uno ya existente                    |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cin>>opcion;
            if(opcion!=1 && opcion!=2)
                cout<<"Debe ingresar una opcion correcta!"<<endl;
        }while(opcion!=1 && opcion!=2);
        if(opcion==1){
            cout<<"|------------------------------------------------|"<<endl;
            cout<<"|Listado de comentarios...                       |"<<endl;
            cout<<"|------------------------------------------------|"<<endl<<endl;
            aux_comentario=factory->getInstance()->getInterfaceP()->listarComentariosDePartida();

        }
        else{

        }

    }
    else{
        cout<<"No existen partidas multijugador no finalizadas y transmitidas en vivo en el sistema"<<endl;
    }
}