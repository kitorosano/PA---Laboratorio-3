//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_COMENTARIO_H
#define PA___LABORATORIO_3_COMENTARIO_H

#include "DataTypes/DT_Date.h"
#include "DataTypes/DT_Time.h"
#include "Classes/Jugador.h"
#include "string"
#include <iostream>
using namespace std;

class Comentario {
private:
    int idComentario;
    DT_Date fecha_envio;
    DT_Time hora_envio;
    string contenido;
    Comentario* comentarioAResponder;
    Jugador* jugador;

public:
    Comentario(int idComentario, DT_Date fecha_envio, DT_Time hora_envio, string contenido, Jugador* jugador);
    Comentario(int idComentario, DT_Date fecha_envio, DT_Time hora_envio, string contenido, Comentario* comentarioAResponder, Jugador* jugador);

    int getIdComentario();
    DT_Date getFecha_envio();
    DT_Time getHora_envio();
    string getContenido();
    Comentario* getComentarioAResponder();
    Jugador* getJugador();

    void setIdComentario(int idComentario);
    void setFecha_envio(DT_Date fecha_envio);
    void sethora_envio(DT_Time hora_envio);
    void setContenido(string contenido);
    void setComentarioAResponder(Comentario* comentarioAResponder);
    void setJugador(Jugador* jugador);

};


#endif //PA___LABORATORIO_3_COMENTARIO_H
