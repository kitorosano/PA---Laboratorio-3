//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_IPARTIDA_H
#define PA___LABORATORIO_3_IPARTIDA_H

#include "Classes/Comentario.h"
#include "Classes/Multijugador.h"
#include "DataTypes/DT_MultijugadorVideojuego.h"
#include "Classes/Individual.h"
#include <string>
#include "Classes/Jugador.h"


using namespace std;

class IPartida {
public:
    virtual Partida* getPartidaSelecionada()=0;
    virtual bool existePartida(int idPartida)=0;
    virtual void continuarPartidaIndividual(int idPartida, Jugador* jugadorIniciador) = 0;
    virtual void nuevaPartidaIndividual(Jugador* jugadorIniciador) = 0;
    virtual void nuevaPartidaMultijugador(Jugador* jugadorIniciador, bool transmitidaEnVivo) = 0;
    virtual void ingresarNicknameALaPartida(string nickname) = 0;
    virtual Partida* confirmarPartida(DT_Fecha* fecha_comienzo) = 0;
    virtual void cancelarIniciarPartida() = 0;

    virtual void confirmarAbandonoPartida(int idPartida, Jugador* jugadorAbandona, DT_Fecha* fechaFinalizacion) = 0;
    virtual void confirmarFinalizarPartida(int idPartida, Jugador* jugadorIniciador, DT_Fecha* fechaFinalizacion) = 0;
    virtual void seleccionarPartida(int idPartida) = 0;

    virtual  IDictionary* listarComentariosDePartida() = 0;
    virtual void seleccionarComentarioAResponder(int idComentario) = 0;
    virtual void enviarComentario(string comentario, Usuario* usuario_logueado) = 0;
    virtual void confirmarComentario() = 0;
    virtual void cancelarComentario()= 0;

    virtual IDictionary * listarHistorialPartidasFinalizadasCronologicamente(Jugador *jugadorlogeado) = 0;

    virtual IDictionary *  listarPartidasIniciadasNoFinalizadas(Jugador *jugadorlogeado) = 0;
    virtual IDictionary *  listarPartidasMultijugadorUnidasNoFinalizadas() = 0;
    virtual IDictionary *  listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo() = 0;

};
#endif //PA___LABORATORIO_3_IPARTIDA_H