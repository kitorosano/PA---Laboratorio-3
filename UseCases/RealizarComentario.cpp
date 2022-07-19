//
// Created by esteban.rosano on 27/6/2022.
//

#include "RealizarComentario.h"
#include "Factory/Factory.h"
#include "ColeccionesG/KeyInt.h"
#include "Utils/Utils.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
void RealizarComentario(){
    Factory * factory;


    int opcion;
    Multijugador* multijugador=NULL;
    Usuario* usuario_logueado=factory->getInstance()->getInterfaceU()->getUsuarioLogeado();
    string contenido,id_partida,id_comentario;
    int id_p,id_c;
    string responder;
    bool repetir;
    IDictionary* aux_jugadores_unidos=NULL;
    IDictionary* aux_comentarios=NULL;

    cout << endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|              REALIZAR COMENTARIO               |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    IDictionary* multiNoFinVivo = factory->getInstance()->getInterfaceP()->listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo();
    IIterator* itMultiNoFinVivo=multiNoFinVivo->getIteratorObj();

    if(itMultiNoFinVivo->hasNext()){
        while(itMultiNoFinVivo->hasNext()){
            DT_MultijugadorVideojuego* dt_multivideojuego= dynamic_cast<DT_MultijugadorVideojuego *>(itMultiNoFinVivo->next());
            cout<<"| #"<<dt_multivideojuego->getIdPartida()<<" > "<<dt_multivideojuego->getMultijugador()->getVideojuego()->getNombre()<<endl;
            cout<<"| Jugador iniciador: "<<dt_multivideojuego->getMultijugador()->getJugador()->getNickname()<<endl;
            cout<<"| Jugadores unidos: "<<endl;
            aux_jugadores_unidos=dt_multivideojuego->getJugadoresUnidos();
            if(aux_jugadores_unidos){
                IIterator *it2 = aux_jugadores_unidos->getIteratorObj();
                while (it2->hasNext()) {
                    JugadorMultijugador* aux_jug = dynamic_cast<JugadorMultijugador *>(it2->getCurrent());
                    if(aux_jug)
                        cout<<"| \t"<< "- " <<aux_jug->getJugador()->getNickname()<< endl;
                    it2->next();
                }
            }
        }
        delete itMultiNoFinVivo;

        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "| Seleccione el numero de la partida a comentar: #";
            cin >> id_partida;
            repetir = false;
            if(isIntegerWM(id_partida)) {
                KeyInt *keyidpartida = new KeyInt(stoi(id_partida));
                if (!multiNoFinVivo->member(keyidpartida)) {
                    cout << id_partida << " NO ES VALIDO (no esta en la lista proporcionada anteriormente)" << endl
                         << endl;
                    repetir = true;
                }
            }
        }while(!isInteger(id_partida) || repetir);
        id_p = stoi(id_partida);
        factory->getInstance()->getInterfaceP()->seleccionarPartida(id_p);

        cout << "|------------------------------------------------|" << endl;
        cout << "|              REALIZAR COMENTARIO               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "| Responder uno ya existente? (s/n):";
        cin>>responder;
        if(responder=="s"||responder=="S"){
            cout << "|------------------------------------------------|" << endl;
            cout << "|         Listado de comentarios...              |" << endl;
            cout << "|------------------------------------------------|" << endl;
            aux_comentarios=factory->getInstance()->getInterfaceP()->listarComentariosDePartida();

            if(aux_comentarios){
                    IIterator *it3 = aux_comentarios->getIteratorObj();
                if(it3->hasNext()) {
                    while (it3->hasNext()) {
                        DT_Comentario *dt_comentario = (DT_Comentario *) (it3->getCurrent());
                        cout << "| Id Comentario: " << dt_comentario->getIdComentario() << endl;
                        cout << "| Autor: " << dt_comentario->getEscritor() << endl;
                        cout << "| Fecha y hora de envio: " << dt_comentario->getFechaEnvio()->toString() << endl;
                        cout << "| Contenido: " << dt_comentario->getContenido() << endl;
                        it3->next();
                    }
                    do {
                        cout << "|------------------------------------------------|" << endl;
                        cout << "| Seleccione el numero del comentario a responder: #";
                        cin >> id_comentario;
                        multijugador=dynamic_cast<Multijugador*>(factory->getInstance()->getInterfaceP()->getPartidaSelecionada());

                    }while(!isInteger(id_comentario)|| !multijugador->obtenerComentario(stoi(id_comentario) ));
                    id_c=stoi(id_comentario);
                    factory->getInstance()->getInterfaceP()->seleccionarComentarioAResponder(id_c);
                }
                else{
                    cout<<"No hay comentarios en esta partida!!"<<endl;
                }
            }
        }
        cout << "|------------------------------------------------|" << endl;
        cout << "|      Escribe el contenido del comentario       |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cin.ignore();
        getline(cin, contenido);
        cout << endl;

        factory->getInstance()->getInterfaceP()->enviarComentario(contenido,usuario_logueado);
        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|              REALIZAR COMENTARIO               |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Confirmar envio                             |" << endl;
            cout << "| 2. Cancelar  envio                             |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cin >> opcion;
            if(opcion !=1 && opcion !=2)
                cout<<"Debe ingresar una opcion correcta!"<<endl;

        }while(opcion!=1 && opcion !=2);
        if(opcion==1){
            factory->getInstance()->getInterfaceP()->confirmarComentario();
            cout << "|------------------------------------------------|" << endl;
            cout << "|            COMENTARIO REALIZADO!!              |" << endl;
            cout << "|------------------------------------------------|" << endl;
        }
        else if(opcion==2){
            factory->getInstance()->getInterfaceP()->cancelarComentario();
            cout << "|------------------------------------------------|" << endl;
            cout << "|            COMENTARIO CANCELADO                |" << endl;
            cout << "|------------------------------------------------|" << endl;
        }
    }
    else{
        cout<<"No existen partidas multijugador no finalizadas y transmitidas en vivo en el sistema"<<endl;
    }
}