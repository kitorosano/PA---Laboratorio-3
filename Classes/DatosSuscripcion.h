//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_DATOSSUSCRIPCION_H
#define PA___LABORATORIO_3_DATOSSUSCRIPCION_H

#include "Suscripcion.h"
#include "Jugador.h"
#include "Data Types/DT_Date.h";

class DatosSuscripcion {
private:
    Jugador *jugador;
    Suscripcion *suscripcion;
    DT_metodo_pago metodo_pago;
    DT_Date fecha_suscripcion;
    DT_Time hora_suscripcion;
    bool activo = false;

public:
    DatosSuscripcion(Jugador *jugador, Suscripcion *suscripcion, DT_metodo_pago metodo_pago, DT_Date fecha_suscripcion, DT_Time hora_suscripcion);
    virtual ~DatosSuscripcion();

    Jugador *getJugador();
    Suscripcion *getSuscripcion();
    DT_metodo_pago getMetodoPago();
    DT_Date getFechaSuscripcion();
    DT_Time getHoraSuscripcion();
    bool getActivo();

    void setJugador(Jugador *jugador);
    void setSuscripcion(Suscripcion *suscripcion);
    void setMetodoPago(DT_metodo_pago metodo_pago);
    void setFechaSuscripcion(DT_Date fecha_suscripcion);
    void setHoraSuscripcion(DT_Time hora_suscripcion);
    void setActivo(bool activo);

};


#endif //PA___LABORATORIO_3_DATOSSUSCRIPCION_H
