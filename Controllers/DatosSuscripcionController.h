//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
#define PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H

#include "Interfaces/IDatosSuscripcion.h"
#include "Classes/Suscripcion.h"
#include "Classes/DatosSuscripcion.h"
#include "DataTypes/E_MetodoPago.h"
#include <vector>
#include <string>

using namespace std;

class DatosSuscripcionController: public IDatosSuscripcion{
private:
    static DatosSuscripcionController* instance;
    DatosSuscripcionController();

    vector<Suscripcion*> suscripciones;
    vector<DatosSuscripcion*> datosSuscripciones;

public:
    static DatosSuscripcionController* getInstance();
    virtual ~DatosSuscripcionController();

    vector<Suscripcion*> listarSuscripciones();
    vector<Suscripcion*> obtenerSuscripcionesVideojuego(string nombre_videojuego);


    vector<string> listarNombreVideojuegosSuscritos();
    void cancelarSuscripcionActiva(int idSuscripcion);

    void crearDatosSuscripcion(int idSuscripcion, E_MetodoPago metodo_pago);
    void confirmarDatosSuscripcion();

    vector<string> listarNicknameJugadoresSuscritos();
};
#endif //PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
