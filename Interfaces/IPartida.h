//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_IPARTIDA_H
#define PA___LABORATORIO_3_IPARTIDA_H

#include "Classes/Comentario.h"
#include "Classes/Multijugador.h"
#include "DataTypes/DT_MultijugadorVideojuego.h"
#include <string>
#include "vector"
using namespace std;

class IPartida {
public:
    virtual void continuarPartidaIndividual(string idPartida) = 0;

    virtual void nuevaPartidaIndividual() = 0;

    virtual void nuevaPartidaMultijugador(bool transmitidaEnVivo) = 0;

    virtual void ingresarNicknameALaPartida(string nickname) = 0;

    virtual void confirmarPartida() = 0;

    virtual vector<Multijugador *> listarPartidasMultijugadorUnidasNoFinalizadas() = 0;

    virtual void confirmarAbandonoPartida(string idPartida) = 0;

    virtual vector<Multijugador *> listarPartidasIniciadasNoFinalizadas() = 0;

    virtual void confirmarFinalizarPartida(string idPartida) = 0;

    virtual void seleccionarPartida(string idPartida) = 0;

    virtual vector<Comentario *> listarComentariosDePartida() = 0;

    virtual void seleccionarComentarioAResponder(int idComentario) = 0;

    virtual void enviarComentario(string comentario) = 0;

    virtual void confirmarComentario() = 0;

    virtual void listarHistorialPartidasFinalizadasCronologicamente() = 0;

    virtual vector<DT_MultijugadorVideojuego> listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo() = 0;
};
#endif //PA___LABORATORIO_3_IPARTIDA_H