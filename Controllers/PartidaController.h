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
#include "ColeccionesG/KeyInt.h"
#include <string>
#include "Classes/Individual.h"
#include "Factory/Factory.h"
#include "ColeccionesG/ListaDicc.h"
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"

#include "Classes/JugadorMultijugador.h"
#include <time.h>  /* time_t, struct tm, difftime, time, mktime */
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
    int idComentario;

public:
    static PartidaController * getInstance();
    virtual ~PartidaController();
    Partida* getPartidaSelecionada();
    bool existePartida(int idPartida);
    void continuarPartidaIndividual(int idPartida, Jugador* jugadorIniciador);
    void nuevaPartidaIndividual(Jugador* jugadorIniciador);
    void nuevaPartidaMultijugador(Jugador* jugadorIniciador, bool transmitidaEnVivo);
    void ingresarNicknameALaPartida(string nickname);
    Partida* confirmarPartida(DT_Fecha* fecha_comienzo);
    void cancelarIniciarPartida();
    
    void confirmarAbandonoPartida(int idPartida, Jugador* jugadorAbandona, DT_Fecha* fechaFinalizacion);
    void confirmarFinalizarPartida(int idPartida, Jugador* jugadorIniciador, DT_Fecha* fechaFinalizacion);
    void seleccionarPartida(int idPartida);
    
    IDictionary* listarComentariosDePartida();
    void seleccionarComentarioAResponder(int idComentario);
    void enviarComentario(string comentario, Usuario* usuario_logueado);
    void confirmarComentario();
    void cancelarComentario();
    
    IDictionary* listarHistorialPartidasFinalizadasCronologicamente(); // lugar 9
    
    IDictionary* listarPartidasIniciadasNoFinalizadas();
    IDictionary* listarPartidasMultijugadorUnidasNoFinalizadas();
    IDictionary* listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo(); // lugar 1
    void listarPartidasMultijugadorNoFinalizadasTransmitidasEnVivo2();
};

#endif //PA___LABORATORIO_3_PARTIDACONTROLLER_H
