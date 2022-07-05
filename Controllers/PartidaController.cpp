//
// Created by Davila on 21/6/2022.
//

#include "PartidaController.h"
using namespace std;

PartidaController* PartidaController::instance = NULL;

PartidaController::PartidaController() {
    partidas = vector<Partida *>();
    partidaSeleccionada = NULL;
    comentarioAResponder = NULL;
    nuevoComentario = NULL;
}

PartidaController::~PartidaController(){}

PartidaController *PartidaController::getInstance() {
    if(instance == NULL)
        instance = new PartidaController;
    return instance;
}

void PartidaController::continuarPartidaIndividual(string idPartida){}
void PartidaController::nuevaPartidaIndividual(){}
void PartidaController::nuevaPartidaMultijugador(bool transmitidaEnVivo){}
void PartidaController::ingresarNicknameALaPartida(string nickname){}
void PartidaController::confirmarPartida(){}
vector<Multijugador*> PartidaController::listarPartidasMultijugadorUnidasNoFinalizadas(){}
void PartidaController::confirmarAbandonoPartida(string idPartida){}
vector<Multijugador*> PartidaController::listarPartidasIniciadasNoFinalizadas(){}
void PartidaController::confirmarFinalizarPartida(string idPartida){}
void PartidaController::seleccionarPartida(string idPartida){}
vector<Comentario*> PartidaController::listarComentariosDePartida(){}
void PartidaController::seleccionarComentarioAResponder(int idComentario){}
void PartidaController::enviarComentario(string comentario){}
void PartidaController::confirmarComentario(){}
void PartidaController::listarHistorialPartidasFinalizadasCronologicamente(){} // lugar 9
vector<DT_MultijugadorVideojuego> PartidaController::listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(){} // lugar 1