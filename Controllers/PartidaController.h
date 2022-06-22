//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_PARTIDACONTROLLER_H
#define PA___LABORATORIO_3_PARTIDACONTROLLER_H

#include "Interfaces/IPartida.h"

class PartidaController : public IPartida{
public:
    PartidaController();
    PartidaController * getInstance();

    void seleccionarPartidaAContinuar(string idPartida);
    void nuevaPartidaIndividual();
    void indicarTransmision();
    void ingresarNicknameALaPartida(string nickname);
    void confirmarRegistro();
    Set<DT_Multijugador_Videojuego> listarPartidasMultijugadorUnidasNoFinalizadas();
    void confirmarAbandonoPartida(string idPartida);
    Set<DT_Partida_Videojuego> listarPartidasIniciadasNoFinalizadas();
    void confirmarPartida(string idPartida);
    void seleccionarPartida(string idPartida);
    Set<Comentario> listarComentariosDePartida();
    void seleccionarComentarioAResponder(string idComentario);
    void enviarComentario(string comentario);

private:
    static PartidaController* instance;
    Comentario* comentarioSeleccionado;
    Partida* partidaSeleccionada;

};

#endif //PA___LABORATORIO_3_PARTIDACONTROLLER_H
