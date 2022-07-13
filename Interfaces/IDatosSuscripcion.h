//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_IDATOSSUSCRIPCION_H
#define PA___LABORATORIO_3_IDATOSSUSCRIPCION_H

#include "Classes/DatosSuscripcion.h"

class IDatosSuscripcion{

public:
    virtual void listarNombreVideojuegosSuscritos()=0;
    virtual IDictionary* obtenerSuscripcionesVideojuego(string nombre_videojuego)=0;
    virtual void cancelarSuscripcionActiva(int idSuscripcion)=0;
    virtual void crearDatosSuscripcion(int idSuscripcion, E_MetodoPago metodo_pago)=0;
    virtual void confirmarDatosSuscripcion()=0;
    virtual void cancelarDatosSuscripcion()=0;
    virtual void listarNicknameJugadoresSuscritos()=0;
};
#endif //PA___LABORATORIO_3_IDATOSSUSCRIPCION_H

