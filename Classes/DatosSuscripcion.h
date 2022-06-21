//
// Created by esteban.rosano on 21/6/2022.
//

#ifndef PA___LABORATORIO_3_DATOSSUSCRIPCION_H
#define PA___LABORATORIO_3_DATOSSUSCRIPCION_H


class DatosSuscripcion {
private:
    DT_metodo_pago metodo_pago;
    DT_Date fecha_suscripcion;
    DT_Time hora_suscripcion;

public:
    DatosSuscripcion(DT_metodo_pago metodo_pago, DT_Date fecha_suscripcion, DT_Time hora_suscripcion);
    virtual ~DatosSuscripcion();

    DT_metodo_pago getMetodoPago();
    DT_Date getFechaSuscripcion();
    DT_Time getHoraSuscripcion();

    void setMetodoPago(DT_metodo_pago metodo_pago);
    void setFechaSuscripcion(DT_Date fecha_suscripcion);
    void setHoraSuscripcion(DT_Time hora_suscripcion);

};


#endif //PA___LABORATORIO_3_DATOSSUSCRIPCION_H
