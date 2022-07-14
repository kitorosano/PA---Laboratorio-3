//
// Created by esteban.rosano on 27/6/2022.
//

#include "RealizarComentario.h"
#include "Factory/Factory.h"
#include <iostream>
#include <string>
using namespace std;
void RealizarComentario(){
    Factory * factory;

    int opcion,id_partida,id_comentario;
    string contenido;
    char responder;
    IDictionary* aux=NULL;
    IDictionary* aux_jugadores_unidos=NULL;
    IDictionary* aux_comentarios=NULL;
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
                    Jugador* aux_jug = (Jugador *) (it2->getCurrent());
                    cout<<"\t"<< "- " <<aux_jug->getNickname()<< endl;
                    it2->next();
                }
            }
            it->next();
        }
        cout<<"|------------------------------------------------|"<<endl;
        cout<<"|    -Seleccione la partida ingresando su id     |"<<endl;
        cout<<"|------------------------------------------------|"<<endl<<endl;
        cin>>id_partida;
        factory->getInstance()->getInterfaceP()->seleccionarPartida(id_partida);

            cout << "|------------------------------------------------|" << endl;
            cout << "|              REALIZAR COMENTARIO               |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|Responder uno ya existente? s/n                 |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cin>>responder;

        if(responder=='s'||responder=='S'){

            cout<<"|------------------------------------------------|"<<endl;
            cout<<"|Listado de comentarios...                       |"<<endl;
            cout<<"|------------------------------------------------|"<<endl<<endl;
            aux_comentarios=factory->getInstance()->getInterfaceP()->listarComentariosDePartida();
            if(aux_comentarios){
                IIterator *it3 = aux_comentarios->getIteratorObj();
                while (it3->hasNext()) {
                    DT_Comentario* dt_comentario = (DT_Comentario*) (it3->getCurrent());
                    cout<< "-Id Comentario" <<dt_comentario->getIdComentario()<< endl;
                    cout<< "-Autor "<<dt_comentario->getEscritor()<<endl;
                    cout<< "-Fecha de envio" <<dt_comentario->getFechaEnvio()->getDate()<< endl;
                    cout<< "-Hora de envio" <<dt_comentario->getHoraEnvio()->getTime()<< endl;
                    cout<< "-Contenido: "<<dt_comentario->getContenido()<<endl;
                    cout<<"----------------------------------------------------------------"<<endl;
                    it3->next();
                }
                cout<<"|------------------------------------------------|"<<endl;
                cout<<"|Seleccione un comentario ingresando su id       |"<<endl;
                cout<<"|------------------------------------------------|"<<endl;
                cin>>id_comentario;
                factory->getInterfaceP()->seleccionarComentarioAResponder(id_comentario);
            }
        }
        cout << "|------------------------------------------------|" << endl;
        cout << "|              REALIZAR COMENTARIO               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|Escribe el contenido del comentario             |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cin>>contenido;
        factory->getInstance()->getInterfaceP()->enviarComentario(contenido);
        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|              REALIZAR COMENTARIO               |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "| 1. Confirmar Envío                             |" << endl;
            cout << "| 2. Cancelar  Envío                             |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cin >> opcion;
            if(opcion !=1 && opcion !=2)
                cout<<"Debe ingresar una opcion correcta!"<<endl;

        }while(opcion!=1 && opcion !=2);
        if(opcion==1){
            factory->getInstance()->getInterfaceP()->confirmarComentario();
        }
        else if(opcion==2){
            factory->getInstance()->getInterfaceP()->cancelarComentario();
        }
    }
    else{
        cout<<"No existen partidas multijugador no finalizadas y transmitidas en vivo en el sistema"<<endl;
    }
}