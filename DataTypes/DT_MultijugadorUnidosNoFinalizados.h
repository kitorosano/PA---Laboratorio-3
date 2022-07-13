//
// Created by Davila on 12/7/2022.
//

#ifndef MAIN_CPP_DT_MULTIJUGADORUNIDOSNOFINALIZADOS_H
#define MAIN_CPP_DT_MULTIJUGADORUNIDOSNOFINALIZADOS_H
#include "string"
#include <iostream>
#include "ColeccionesG/IDictionary.h"
using namespace std;

class DT_MultijugadorUnidosNoFinalizados {
private:
    int idPartida;
    string fecha;
    string horaComienzo;
    string nombreVideoJuego;
    bool transmitidaEnVivo;
    string nicknamejugadorIniciador;
    IDictionary* jugadoresEnLaPartida;

public:
    DT_MultijugadorUnidosNoFinalizados(int idPartida, string fecha, string horaComienzo, string nombreVideoJuego, bool transmitidaEnVivo, string nicknamejugadorIniciador, IDictionary* jugadoresEnLaPartida);

    int getidPartida();
    string getfecha();
    string gethoraComienzo();
    string getnombreVideoJuego();
    bool gettransmitidaEnVivo();
    string getnicknamejugadorIniciador();
    IDictionary* getjugadoresEnLaPartida();

};


#endif //MAIN_CPP_DT_MULTIJUGADORUNIDOSNOFINALIZADOS_H
