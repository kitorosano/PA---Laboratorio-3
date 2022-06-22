//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_IPARTIDA_H
#define PA___LABORATORIO_3_IPARTIDA_H

#include "Classes/Comentario.h"
#include <string>
using namespace std;

class IPartida {
public:
    virtual void seleccionarPartidaAContinuar(string idPartida) = 0;
    virtual void nuevaPartidaIndividual() = 0;
    virtual void indicarTransmision() = 0;
    virtual void ingresarNicknameALaPartida(string nickname) = 0;
    virtual void confirmarRegistro() = 0;
    virtual Set<DT_Multijugador_Videojuego> listarPartidasMultijugadorUnidasNoFinalizadas() = 0;
    virtual void confirmarAbandonoPartida(string idPartida) = 0;
    virtual Set<DT_Partida_Videojuego> listarPartidasIniciadasNoFinalizadas() = 0;
    virtual void confirmarPartida(string idPartida) = 0;
    virtual void seleccionarPartida(string idPartida) = 0;
    virtual Set<Comentario> listarComentariosDePartida() = 0;
    virtual void seleccionarComentarioAResponder(string idComentario) = 0;
    virtual void enviarComentario(string comentario) = 0;

};
#endif //PA___LABORATORIO_3_IPARTIDA_H
