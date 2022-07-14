//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_IPARTIDA_H
#define PA___LABORATORIO_3_IPARTIDA_H

#include "Classes/Comentario.h"
#include "Classes/Multijugador.h"
#include "DataTypes/DT_MultijugadorVideojuego.h"
#include <string>


using namespace std;

class IPartida {
public:
    virtual void continuarPartidaIndividual(int idPartida) = 0;

    virtual void nuevaPartidaIndividual() = 0;

    virtual void nuevaPartidaMultijugador(bool transmitidaEnVivo) = 0;

    virtual void ingresarNicknameALaPartida(string nickname) = 0;

    virtual void confirmarPartida() = 0;

    virtual IDictionary *  listarPartidasMultijugadorUnidasNoFinalizadas() = 0;

    virtual void confirmarAbandonoPartida(int idPartida) = 0;

    virtual IDictionary *  listarPartidasIniciadasNoFinalizadas() = 0;

    virtual void confirmarFinalizarPartida(int idPartida) = 0;

    virtual void seleccionarPartida(int idPartida) = 0;

    virtual  IDictionary* listarComentariosDePartida() = 0;

    virtual void seleccionarComentarioAResponder(int idComentario) = 0;

    virtual void enviarComentario(string comentario) = 0;

    virtual void confirmarComentario() = 0;

    virtual void cancelarComentario()= 0;

    virtual IDictionary * listarHistorialPartidasFinalizadasCronologicamente() = 0;

    virtual IDictionary *  listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo() = 0;

    virtual void cancelarIniciarPartida() = 0;
};
#endif //PA___LABORATORIO_3_IPARTIDA_H