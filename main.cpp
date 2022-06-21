//
// Created by esteban.rosano on 20/6/2022.
//

#include <iostream>
using namespace std;

void menu() {
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|                 MENU DE SISTEMA                |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"| 1. Alta usuario                                |"<<endl;
    cout<<"| 2. Iniciar sesion                              |"<<endl;
    cout<<"| 3. Agregar categoria                           |"<<endl;
    cout<<"| 4. Publicar videojuego                         |"<<endl;
    cout<<"| 5. Suscribirse a videojuego                    |"<<endl;
    cout<<"| 6. Asignar puntaje a videojuego                |"<<endl;
    cout<<"| 7. Iniciar partida                             |"<<endl;
    cout<<"| 8. Abandonar partida multijugador              |"<<endl;
    cout<<"| 9. Finalizar partida                           |"<<endl;
    cout<<"| 10. Realizar comentario                        |"<<endl;
    cout<<"| 11. Ver informacion de videojuego              |"<<endl;
    cout<<"| 12. Seguir jugador                             |"<<endl;
    cout<<"| 13. Eliminar videojuego                        |"<<endl;
    cout<<"| 0. Salir                                       |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese una opcion:";
}


int main() {
    int opcion;
    do {
        menu();
        cin >> opcion;
        switch (opcion) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;
            case 12:

                break;
            case 13:

                break;
            default:
                break;
        }
    }while (opcion != 0);

    return 0;
}