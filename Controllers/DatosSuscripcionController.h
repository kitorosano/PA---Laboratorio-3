//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
#define PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
#include "Interfaces/IDatosSuscripcion.h"
#include "Classes/Suscripcion.h"
#include "Classes/DatosSuscripcion.h"
#include "Data Types/DT_MetodoPago.h"
#include <vector>
class DatosSuscripcionController: public IDatosSuscripcion{
private:
    static DatosSuscripcionController* instance;
    vector<Suscripcion*> suscripciones;
    vector<DatosSuscripcion*> DatosSuscripciones;
public:
    DatosSuscripcionController();
    DatosSuscripcionController* getInstance();
    virtual ~DatosSuscripcionController();

     void listarSuscripciones();
     void listarNombreVideojuegosSuscritos();
     void obtenerSuscripcionesVideojuego(string nombre_videojuego);
     void cancelarSuscripcionActiva(int idSuscripcion);
     void crearDatosSuscripcion(int idSuscripcion, DT_MetodoPago metodo_pago);
     void confirmarDatosSuscripcion();
     void listarNicknameJugadoresSuscritos();
};
#endif //PA___LABORATORIO_3_DATOSSUSCRIPCIONCONTROLLER_H
