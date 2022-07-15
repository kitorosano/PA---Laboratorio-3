//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_DATOSSUSCRIPCION_H
#define PA___LABORATORIO_3_DATOSSUSCRIPCION_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "Suscripcion.h"
#include "Jugador.h"
#include "DataTypes/DT_Fecha.h"
#include "DataTypes/E_MetodoPago.h"

class DatosSuscripcion: public ICollectible {
private:
    int id;
    string nickname;
    Suscripcion *suscripcion;
    E_MetodoPago metodo_pago;
    DT_Fecha* fecha_suscripcion;

public:
    DatosSuscripcion();
    DatosSuscripcion(string nickname, Suscripcion *suscripcion, E_MetodoPago metodo_pago);
    DatosSuscripcion(string nickname, Suscripcion *suscripcion, DT_Fecha* fecha_suscripcion, E_MetodoPago metodo_pago);
    virtual ~DatosSuscripcion();

    int getId();
    string getNickName();
    Suscripcion *getSuscripcion();
    E_MetodoPago getMetodoPago();
    DT_Fecha* getFechaSuscripcion();
    bool isActivo();


    void setId(int id);
    void setFechaSuscripcion(DT_Fecha* fechaSuscripcion);

    void marcarExpirado();

    string toString();
};


#endif //PA___LABORATORIO_3_DATOSSUSCRIPCION_H
