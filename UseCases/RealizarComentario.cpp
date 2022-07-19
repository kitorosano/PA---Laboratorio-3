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
    Individual* individual=NULL;
    string contenido,id_partida,id_comentario;
    int id_p,id_c;
    char responder;
    char _contenido[255];
    bool _individual,repetir;
    IDictionary* aux=NULL;
    IDictionary* aux_jugadores_unidos=NULL;
    IDictionary* aux_comentarios=NULL;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|              REALIZAR COMENTARIO               |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    aux=factory->getInstance()->getInterfaceP()->listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo();

    if(aux){
        factory->getInstance()->getInterfaceP()->listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo2();

        do {
            cout << "|------------------------------------------------|" << endl;
            cout << "|    -Seleccione la partida ingresando su id     |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cin >> id_partida;
            fflush(stdin);
            repetir = false;
            if(isIntegerWM(id_partida)) {
                KeyInt *keyidpartida = new KeyInt(stoi(id_partida));
                if (!aux->member(keyidpartida)) {
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
            cout << "|Responder uno ya existente? s/n                 |" << endl;
            cout << "|------------------------------------------------|" << endl << endl;
            cin>>responder;
            fflush(stdin);
        if(responder=='s'||responder=='S'){
            aux_comentarios=factory->getInstance()->getInterfaceP()->listarComentariosDePartida();

            if(aux_comentarios){
                    IIterator *it3 = aux_comentarios->getIteratorObj();
                if(it3->hasNext()) {
                    while (it3->hasNext()) {
                        DT_Comentario *dt_comentario = (DT_Comentario *) (it3->getCurrent());
                        cout << "|------------------------------------------------|" << endl;
                        cout << "|Listado de comentarios...                       |" << endl;
                        cout << "|------------------------------------------------|" << endl << endl;
                        cout << "-Id Comentario " << dt_comentario->getIdComentario() << endl;
                        cout << "-Autor " << dt_comentario->getEscritor() << endl;
                        cout << "-Fecha y hora de envio " << dt_comentario->getFechaEnvio()->toString() << endl;
                        cout << "-Contenido: " << dt_comentario->getContenido() << endl;
                        cout << "----------------------------------------------------------------" << endl;
                        it3->next();
                    }
                    do {
                        cout << "|------------------------------------------------|" << endl;
                        cout << "|Seleccione un comentario ingresando su id       |" << endl;
                        cout << "|------------------------------------------------|" << endl;
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
        cout << "|              REALIZAR COMENTARIO               |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|Escribe el contenido del comentario             |" << endl;
        cout << "|------------------------------------------------|" << endl;
        gets(_contenido);
        contenido=_contenido;
        fflush(stdin);
        factory->getInstance()->getInterfaceP()->enviarComentario(contenido,usuario_logueado);
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