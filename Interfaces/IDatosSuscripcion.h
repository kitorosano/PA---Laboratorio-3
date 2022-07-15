//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_IDATOSSUSCRIPCION_H
#define PA___LABORATORIO_3_IDATOSSUSCRIPCION_H

#include "Classes/DatosSuscripcion.h"

class IDatosSuscripcion{

public:
    virtual DatosSuscripcion* getDatoSuscripcionSeleccionado()=0;
    virtual IDictionary* getDatosSuscripciones() = 0;
    virtual IDictionary* listarVideojuegoSuscripciones() = 0;
    virtual IDictionary* listarNombreVideojuegosSuscritos()=0;
    virtual void cancelarSuscripcionActiva(int idSuscripcion)=0;
    virtual void crearDatosSuscripcion(string nickname, int idSuscripcion, E_MetodoPago metodo_pago)=0;
    virtual void confirmarDatosSuscripcion()=0;
    virtual void cancelarDatosSuscripcion()=0;
    virtual void listarNicknameJugadoresSuscritos()=0;
};
#endif //PA___LABORATORIO_3_IDATOSSUSCRIPCION_H

