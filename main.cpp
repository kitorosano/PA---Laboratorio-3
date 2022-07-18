//
// Created by esteban.rosano on 20/6/2022.
//
#include "UseCases/AltaUsuario.h"
#include "UseCases/IniciarSesion.h"
#include "UseCases/CargarDatosDePrueba.h"
#include "UseCases/AgregarCategoria.h"
#include "UseCases/PublicarVideojuego.h"
#include "UseCases/EliminarVideojuego.h"
#include "UseCases/VerInformacionDeVideojuego.h"
#include "UseCases/SuscribirseAVideojuego.h"
#include "UseCases/AsignarPuntajeAVideojuego.h"
#include "UseCases/IniciarPartida.h"
#include "UseCases/AbandonarPartidaMultijugador.h"
#include "UseCases/FinalizarPartida.h"
#include "UseCases/RealizarComentario.h"
#include "UseCases/SeguirJugador.h"
#include "Utils/Utils.h"
#include <iostream>
using namespace std;

void menuPrincipal() {
    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                 MENU PRINCIPAL                 |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"| 1. Alta usuario                                |"<<endl;
    cout<<"| 2. Iniciar sesion                              |"<<endl;
    cout<<"| 3. Cargar datos de prueba                      |"<<endl;
    cout<<"| 0. Salir                                       |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"| > Ingrese una opcion: ";
}
void menuDesarrollador() {
    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|              MENU DE DESARROLLADOR             |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"| 1. Agregar categoria                           |"<<endl;
    cout<<"| 2. Publicar videojuego                         |"<<endl;
    cout<<"| 3. Eliminar videojuego                         |"<<endl;
    cout<<"| 4. Ver informacion de videojuego               |"<<endl;
    cout<<"| 0. Salir                                       |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"| > Ingrese una opcion: ";
}
void menuJugador() {
    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                 MENU DE JUGADOR                |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"| 1. Suscribirse a videojuego                    |"<<endl;
    cout<<"| 2. Asignar puntaje a videojuego                |"<<endl;
    cout<<"| 3. Iniciar partida                             |"<<endl;
    cout<<"| 4. Abandonar partida multijugador              |"<<endl;
    cout<<"| 5. Finalizar partida                           |"<<endl;
    cout<<"| 6. Ver informacion de videojuego               |"<<endl;
    cout<<"| 7. Realizar comentario                         |"<<endl;
    cout<<"| 8. Seguir jugador                              |"<<endl;
    cout<<"| 0. Salir                                       |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"| > Ingrese una opcion: ";
}

void welcomeMsg() {
    cout<<"  //==========================================\\\\"<<endl;
    cout<<"///--------------------------------------------\\\\\\"<<endl;
    cout<<"|||                BIENVENIDO!                 |||"<<endl;
    cout<<"\\\\\\--------------------------------------------///"<< endl;
    cout<<"  \\\\==========================================//"<< endl<<endl;
}
void goodbyeMsg() {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"  //==========================================\\\\"<<endl;
    cout<<"///--------------------------------------------\\\\\\"<<endl;
    cout<<"|||  MUCHAS GRACIAS POR USAR NUESTRO SISTEMA!  |||"<<endl;
    cout<<"\\\\\\--------------------------------------------///"<< endl;
    cout<<"  \\\\==========================================//"<< endl<<endl;
}


int main() {
    welcomeMsg();

    int opPrincipal;
    do {
        menuPrincipal();
        cin >> opPrincipal;
        cout << "------------------------------------------------|" << endl;
        switch (opPrincipal) {
            case 1: {
                AltaUsuario();
                break;
            }
            case 2: {
                int tipoUsuario = IniciarSesion(); // 0: Desarrollador | 1: Jugador | -1: Inicio sesion fallido
                switch (tipoUsuario) {
                    case 0: {
                      int opDesarrollador;
                        do {
                            menuDesarrollador();
                            cin >> opDesarrollador;
                            cout << "------------------------------------------------|" << endl;
                            switch (opDesarrollador) {
                                case 1:
                                    AgregarCategoria();
                                    break;
                                case 2:
                                    PublicarVideojuego();
                                    break;
                                case 3:
                                    EliminarVideojuego();
                                    break;
                                case 4:
                                    VerInformacionDeVideojuego();
                                    break;
                                case 0:
                                    cout << "Sesion Cerrada" << endl;
                                    break;
                                default:
                                    cout << "Opcion invalida" << endl;
                                    break;
                            }
                            presionaParaContinuar();
                        } while (opDesarrollador != 0);
                        break;
                    }
                    case 1: {
                        int opJugador;
                        do {
                            menuJugador();
                            cin >> opJugador;
                            cout << "------------------------------------------------|" << endl;
                            switch (opJugador) {
                                case 1:
                                    SuscribirseAVideojuego();
                                    break;
                                case 2:
                                    AsignarPuntajeAVideojuego();
                                    break;
                                case 3:
                                    IniciarPartida();
                                    break;
                                case 4:
                                    AbandonarPartidaMultijugador();
                                    break;
                                case 5:
                                    FinalizarPartida();
                                    break;
                                case 6:
                                    VerInformacionDeVideojuego();
                                    break;
                                case 7:
                                    RealizarComentario();
                                    break;
                                case 8:
                                    SeguirJugador();
                                    break;
                                case 0:
                                    cout << "Sesion Cerrada" << endl;
                                    break;
                                default:
                                    cout << "Opcion invalida" << endl;
                                    break;
                            }
                            presionaParaContinuar();
                        } while (opJugador != 0);
                        break;
                    }
                    default: {
                        cout << "Login Fallido" << endl;
                        break;
                    }
                }
                break;
            }
            case 3: {
                CargarDatosDePrueba();
                break;
            }
            case 0:
                break;
            default: break;
        }
        presionaParaContinuar();
    }while (opPrincipal != 0);

    goodbyeMsg();
    return 0;
}