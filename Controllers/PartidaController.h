//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_PARTIDACONTROLLER_H
#define PA___LABORATORIO_3_PARTIDACONTROLLER_H

#include "Interfaces/IPartida.h"
#include "Classes/Partida.h"
#include "vector"
#include "Classes/Multijugador.h"

class PartidaController : public IPartida{
public:
    PartidaController();
    PartidaController * getInstance();
    vector<Partida*> partidas;


    void continuarPartidaIndividual(string idPartida);
    void nuevaPartidaIndividual();
    void nuevaPartidaMultijugador(bool transmitidaEnVivo);
    void ingresarNicknameALaPartida(string nickname);
    void confirmarPartida();
    vector<Multijugador*> listarPartidasMultijugadorUnidasNoFinalizadas();
    void confirmarAbandonoPartida(string idPartida);
    vector<Multijugador*> listarPartidasIniciadasNoFinalizadas();
    void confirmarFinalizarPartida(string idPartida);
    void seleccionarPartida(string idPartida);
    vector<Comentario*> listarComentariosDePartida();
    void seleccionarComentarioAResponder(int idComentario);
    void enviarComentario(string comentario);
    void ConfirmarComentario();
    void listarHistorialPartidasFinalizadasCronologicamente(); // lugar 9
    vector<DT_Multijugador_Videojuego>listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(); // lugar 1

private:
    static PartidaController* instance;
    // despues hacer un metodo que deje null estos dato:
    Partida* partidaSeleccionada; // El controlador guarda la partida pi
    Comentario* comentarioAResponder;
    Comentario* nuevoComentario;

};

#endif //PA___LABORATORIO_3_PARTIDACONTROLLER_H
