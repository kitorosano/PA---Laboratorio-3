//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
#define PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H

#include "Interfaces/IDatosSuscripcion.h"
#include <string>

using namespace std;

class DatosSuscripcionController: public IDatosSuscripcion{
private:
    static DatosSuscripcionController* instance;
    DatosSuscripcionController();

    int contadorIdDatosSuscripcion = 1;
    DatosSuscripcion* controller_memory;
    IDictionary* datosSuscripciones;

public:
    static DatosSuscripcionController* getInstance();
    virtual ~DatosSuscripcionController();

    int getNuevoIdDatosSuscripcion();
    IDictionary* getDatosSuscripciones();

    IDictionary* obtenerSuscripcionesVideojuego(string nombre_videojuego);

    void listarNombreVideojuegosSuscritos();
    void cancelarSuscripcionActiva(int idSuscripcion);

    void crearDatosSuscripcion(int idSuscripcion, E_MetodoPago metodo_pago);
    void confirmarDatosSuscripcion();
    void cancelarDatosSuscripcion();

    void listarNicknameJugadoresSuscritos();
};
#endif //PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
