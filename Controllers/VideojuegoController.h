//
// Created by Admin on 20/06/2022.
//
#ifndef LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
#define LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
#include IVideojuego.h
    class VideojuegoController public:Ivideojuego{
        public:
        void datosNuevoVideojuego(nombre: string, descripcion: string, costoMensual:int, costoTrimestral:int, costoAnual:int, costoVitalicia:int);
        void seleccionarCategoriaGenero(catGenero: Cat_Genero);
        void seleccionarCategoriaPlataforma(catPlataforma: Cat_Plataforma);
        void seleccionarCategoriaOpcionales(categia: Categoria);
        void listarNomDescVideoJuegos();
        void actualizarPuntaje();
        void listarVideojuegos();
        void seleccionarVideojuego(idVideojuego);
        void listaJuegosPublicados();
        void seleccionarVideojuegoAEliminar(nombre_videojuego: string);
        void eliminarDatos();
    };
#endif //LAB_3_PROYECTO_VIDEOJUEGOCONTROLLER_H
