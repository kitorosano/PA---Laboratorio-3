//
// Created by Davila on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_PARTIDACONTROLLER_H
#define PA___LABORATORIO_3_PARTIDACONTROLLER_H

#include "Interfaces/IPartida.h"
#include "Classes/Partida.h"
#include "Classes/Multijugador.h"
#include "DataTypes/DT_MultijugadorVideojuego.h"
#include "DataTypes/DT_PartidasIndividualesFinalizadas.h"


#include "ColeccionesG/IDictionary.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/KeyString.h"
#include <string>
#include "Classes/Individual.h"
#include "Factory/Factory.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "DataTypes/DT_MultijugadorUnidosNoFinalizados.h"
#include "Classes/JugadorMultijugador.h"
using namespace std;

class PartidaController: public IPartida{
private:
    static PartidaController* instance;
    PartidaController();

    Partida* partidaSeleccionada; // El controlador guarda la partida pi
    Comentario* comentarioAResponder;
    Comentario* nuevoComentario;

    IDictionary* partidas;
    int idpartida;

public:
    static PartidaController * getInstance();
    virtual ~PartidaController();

    void continuarPartidaIndividual(int idPartida);
    void nuevaPartidaIndividual();
    void nuevaPartidaMultijugador(bool transmitidaEnVivo);
    void ingresarNicknameALaPartida(string nickname);
    void confirmarPartida();
    IDictionary* listarPartidasMultijugadorUnidasNoFinalizadas();
    void confirmarAbandonoPartida(int idPartida);
    IDictionary* listarPartidasIniciadasNoFinalizadas();
    void confirmarFinalizarPartida(int idPartida);
    void seleccionarPartida(int idPartida);
    IDictionary* listarComentariosDePartida();
    void seleccionarComentarioAResponder(int idComentario);
    void enviarComentario(string comentario);
    void confirmarComentario();
    IDictionary* listarHistorialPartidasFinalizadasCronologicamente(); // lugar 9
    IDictionary* listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(); // lugar 1
    void cancelarIniciarPartida();

};

#endif //PA___LABORATORIO_3_PARTIDACONTROLLER_H
