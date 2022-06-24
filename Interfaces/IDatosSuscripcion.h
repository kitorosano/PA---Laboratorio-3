//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_IDATOSSUSCRIPCION_H
#define PA___LABORATORIO_3_IDATOSSUSCRIPCION_H
#include <string>
using namespace std;

#endif //PA___LABORATORIO_3_IDATOSSUSCRIPCION_H

class IDatosSuscripcion{

public:
    virtual void listarSuscripciones()=0;
    virtual void listarNombreVideojuegosSuscritos()=0;
    virtual void obtenerSuscripcionesVideojuego(string nombre_videojuego)=0;
    virtual void cancelarSuscripcionActiva(int idSuscripcion)=0;
    virtual void crearDatosSuscripcion(int idSuscripcion, DT_MetodoPago metodo_pago)=0;
    virtual void confirmarDatosSuscripcion()=0;
    virtual void listarNicknameJugadoresSuscritos()=0;
};