//
// Created by Admin on 21/06/2022.
//

#ifndef PA___LABORATORIO_3_VIDEOJUEGO_H
#define PA___LABORATORIO_3_VIDEOJUEGO_H
#include <string>
#include <iostream>
#include <vector>

#include "Suscripcion.h"
#include "Categoria.h"
using namespace std;

class Videojuego{
private:
    int idVideojuego;
    string nombre;
    string descripcion;
    double total_horas_jugadas;
    double puntaje;
    int cantidad_votos;
    vector<Categoria *> categorias;
    vector<Suscripcion> suscripciones;

public:
    Videojuego(string nombre,string descripcion);
    virtual ~Videojuego();

    int getIdVideojuego();
    string getNombre();
    string getDescripcion();
    double getTotal_horas_jugadas();
    double getPuntaje();
    int getCantidad_votos();

    void setIdVideojuego(int idVideojuego);
    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setTotal_horas_jugadas(double total_horas_jugadas);
    void setPuntaje(double puntaje);
    void setCantidad_votos(int cantidad_votos);
    void agregarCategoria(Categoria * categorias);
    void agregarSuscripcion(Suscripcion suscripcion);
    void eliminarSuscripcion(Suscripcion suscripcion);
};
#endif //PA___LABORATORIO_3_VIDEOJUEGO_H
