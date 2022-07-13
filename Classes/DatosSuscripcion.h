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
#include "DataTypes/DT_Date.h"
#include "DataTypes/DT_Time.h"
#include "DataTypes/E_MetodoPago.h"

class DatosSuscripcion: public ICollectible {
private:
    int id;
    string nickname;
    Suscripcion *suscripcion;
    E_MetodoPago metodo_pago;
    DT_Date* fecha_suscripcion;
    DT_Time* hora_suscripcion;
    bool activo = false;

public:
    DatosSuscripcion();
    DatosSuscripcion(string nickname, Suscripcion *suscripcion, E_MetodoPago metodo_pago);
    virtual ~DatosSuscripcion();

    int getId();
    void setId(int id);

    string getNickName();
    Suscripcion *getSuscripcion();
    E_MetodoPago getMetodoPago();
    DT_Date* getFechaSuscripcion();
    DT_Time* getHoraSuscripcion();
    bool isActivo();

    void marcarExpirado();

    string toString();
};


#endif //PA___LABORATORIO_3_DATOSSUSCRIPCION_H
