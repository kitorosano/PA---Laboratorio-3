//
// Created by Admin on 23/06/2022.
//

#ifndef PA___LABORATORIO_3_IDATOSSUSCRIPCION_H
#define PA___LABORATORIO_3_IDATOSSUSCRIPCION_H

#include "../ColeccionesG/ICollectible.h"
#include "../ColeccionesG/ICollection.h"
#include "../ColeccionesG/IDictionary.h"
#include "DataTypes/E_MetodoPago.h"
#include "Classes/Suscripcion.h"
#include <string>

using namespace std;


class IDatosSuscripcion{

public:
    virtual IDictionary* listarNombreVideojuegosSuscritos()=0;
    virtual IDictionary* obtenerSuscripcionesVideojuego(string nombre_videojuego)=0;
    virtual void cancelarSuscripcionActiva(int idSuscripcion)=0;
    virtual void crearDatosSuscripcion(int idSuscripcion, E_MetodoPago metodo_pago)=0;
    virtual void confirmarDatosSuscripcion()=0;
    virtual IDictionary* listarNicknameJugadoresSuscritos()=0;
};
#endif //PA___LABORATORIO_3_IDATOSSUSCRIPCION_H

