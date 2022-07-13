//
// Created by esteban.rosano on 23/6/2022.
//

#ifndef PA___LABORATORIO_3_DT_INFOVIDEOJUEGO_H
#define PA___LABORATORIO_3_DT_INFOVIDEOJUEGO_H

#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "Classes/Suscripcion.h"
#include "Classes/Categoria.h"
#include <string>

using namespace std;

class DT_InfoVideojuego: public ICollectible {
private:
    string nombre;
    IDictionary* categorias;
    IDictionary* suscripciones;
    string empresa;
    double puntaje;
    double totalHorasJugadas;

public:
    DT_InfoVideojuego();
    ~DT_InfoVideojuego();

    string getNombre();
    IDictionary* getCategorias();
    IDictionary* getSuscripciones();
    string getEmpresa();
    double getPuntaje();
    double getTotalHorasJugadas();

    void setNombre(string nombre);
    void setCategorias(IDictionary* categorias);
    void setSuscripciones(IDictionary* suscripciones);
    void setEmpresa(string empresa);
    void setPuntaje(double puntaje);
    void setTotalHorasJugadas(double totalHorasJugadas);

    string toString();
    string categoriasToString();
    string suscripcionesToString();
};



#endif //PA___LABORATORIO_3_DT_INFOVIDEOJUEGO_H
