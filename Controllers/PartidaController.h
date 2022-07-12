//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_PARTIDACONTROLLER_H
#define PA___LABORATORIO_3_PARTIDACONTROLLER_H

#include "Interfaces/IPartida.h"
#include "Classes/Partida.h"
#include "Classes/Individual.h"
#include "Classes/Multijugador.h"
#include "Classes/Jugador.h"
#include "Classes/Usuario.h"
#include "DataTypes/DT_MultijugadorVideojuego.h"
#include "Controllers/VideoJuegoController.h"
#include "Controllers/UsuarioController.h"
#include "ColeccionesG/IDictionary.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/KeyString.h"
#include <string>

using namespace std;

class PartidaController: public IPartida{
private:
    static PartidaController* instance;
    PartidaController();

    Partida* partidaSeleccionada; // El controlador guarda la partida pi
    Comentario* comentarioAResponder;
    Comentario* nuevoComentario;
    IDictionary* partidas;
    Individual* partidaAContinuar;
    int idpartida;

public:
    static PartidaController * getInstance();
    virtual ~PartidaController();

    void continuarPartidaIndividual(string idPartida);
    void nuevaPartidaIndividual();
    void nuevaPartidaMultijugador(bool transmitidaEnVivo);
    void ingresarNicknameALaPartida(string nickname);
    void confirmarPartida();
    IDictionary* listarPartidasMultijugadorUnidasNoFinalizadas();
    void confirmarAbandonoPartida(string idPartida);
    IDictionary* listarPartidasIniciadasNoFinalizadas();
    void confirmarFinalizarPartida(string idPartida);
    void seleccionarPartida(string idPartida);
    IDictionary* listarComentariosDePartida();
    void seleccionarComentarioAResponder(int idComentario);
    void enviarComentario(string comentario);
    void confirmarComentario();
    void listarHistorialPartidasFinalizadasCronologicamente(); // lugar 9
    IDictionary* listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(); // lugar 1


};

#endif //PA___LABORATORIO_3_PARTIDACONTROLLER_H
