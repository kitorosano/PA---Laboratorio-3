//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_PARTIDACONTROLLER_H
#define PA___LABORATORIO_3_PARTIDACONTROLLER_H

#include "Interfaces/IPartida.h"
#include "Classes/Partida.h"
#include "Classes/Multijugador.h"
#include "DataTypes/DT_MultijugadorVideojuego.h"
#include "vector"
#include <string>

using namespace std;

class PartidaController: public IPartida{
private:
    static PartidaController* instance;
    PartidaController();

    Partida* partidaSeleccionada; // El controlador guarda la partida pi
    Comentario* comentarioAResponder;
    Comentario* nuevoComentario;
    vector<Partida*> partidas;

public:
    static PartidaController * getInstance();
    virtual ~PartidaController();

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
    void confirmarComentario();
    void listarHistorialPartidasFinalizadasCronologicamente(); // lugar 9
    vector<DT_MultijugadorVideojuego>listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(); // lugar 1


};

#endif //PA___LABORATORIO_3_PARTIDACONTROLLER_H
