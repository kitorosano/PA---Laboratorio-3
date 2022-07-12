//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
#define PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H

#include "Interfaces/IDatosSuscripcion.h"
#include "Classes/Suscripcion.h"
#include "Classes/DatosSuscripcion.h"
#include "DataTypes/E_MetodoPago.h"
#include "../ColeccionesG/ICollectible.h"
#include "../ColeccionesG/ICollection.h"
#include "../ColeccionesG/IDictionary.h"
#include <string>

using namespace std;

class DatosSuscripcionController: public IDatosSuscripcion{
private:
    static DatosSuscripcionController* instance;
    DatosSuscripcionController();

    IDictionary* datosSuscripciones;

public:
    static DatosSuscripcionController* getInstance();
    virtual ~DatosSuscripcionController();

    IDictionary* obtenerSuscripcionesVideojuego(string nombre_videojuego);


    IDictionary* listarNombreVideojuegosSuscritos();
    void cancelarSuscripcionActiva(int idSuscripcion);

    void crearDatosSuscripcion(int idSuscripcion, E_MetodoPago metodo_pago);
    void confirmarDatosSuscripcion();

    IDictionary* listarNicknameJugadoresSuscritos();
};
#endif //PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
