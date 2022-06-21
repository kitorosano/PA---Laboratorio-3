//
// Created by Admin on 20/06/2022.
//

#ifndef LAB_3_PROYECTO_GEN_VIDEOJUEGO_H
#define LAB_3_PROYECTO_GEN_VIDEOJUEGO_H
#include "Classes/Categoria.h"

enum Cat_Genero { Accion,Aventura,Estrategia,Deporte };
static const char* Cat_Genero_str[] = {"Accion",  "Aventura", "Estrategia", "Deporte"};

class Gen_videojuego: public Categoria{

};
#endif //LAB_3_PROYECTO_GEN_VIDEOJUEGO_H
