//
// Created by Admin on 21/06/2022.
//

#ifndef PA___LABORATORIO_3_VIDEOJUEGO_H
#define PA___LABORATORIO_3_VIDEOJUEGO_H
#include "ColeccionesG/ICollectible.h"
#include "ColeccionesG/ICollection.h"
#include "ColeccionesG/IDictionary.h"
#include "Suscripcion.h"
#include "Categoria.h"
#include "DataTypes/DT_NomDescVideojuego.h"
#include "Classes/Desarrollador.h"

#include <string>
#include <iostream>
using namespace std;

class Videojuego: public ICollectible{
private:
    int idVideojuego;
    string nombre;
    string descripcion;
    double total_horas_jugadas;
    double puntaje;
    int cantidad_votos;
    Desarrollador* desarrollador;

public:
    Videojuego();
    Videojuego(string nombre,string descripcion, Desarrollador *desarrollador);
    virtual ~Videojuego();

    int getIdVideojuego();
    string getNombre();
    string getDescripcion();
    DT_NomDescVideojuego getNomDescVideojuego();
    double getTotalHorasJugadas();
    double getPuntaje();
    int getCantidad_votos();
    string getNombreEmpresa();

    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setTotal_horas_jugadas(double totalHorasJugadas);
    void setPuntaje(double puntaje);
    void setCantidad_votos(int cantidad_votos);
    void setDesarrollador(Desarrollador* desarrollador);

    string toString();
};
#endif //PA___LABORATORIO_3_VIDEOJUEGO_H
