//
// Created by Admin on 20/06/2022.
//

#ifndef LAB_3_PROYECTO_IVIDEOJUEGO_H
#define LAB_3_PROYECTO_IVIDEOJUEGO_H
    class Ivideojuego{
        public:
        virtual void datosNuevoVideojuego(nombre: string, descripcion: string, costoMensual:int, costoTrimestral:int, costoAnual:int, costoVitalicia:int)=0;
        virtual void seleccionarCategoriaGenero(catGenero: Cat_Genero)=0;
        virtual void seleccionarCategoriaPlataforma(catPlataforma: Cat_Plataforma)=0;
        virtual void seleccionarCategoriaOpcionales(categia: Categoria)=0;
        virtual void listarNomDescVideoJuegos()=0;
        virtual void actualizarPuntaje()=0;
        virtual void listarVideojuegos()=0;
        virtual void seleccionarVideojuego(idVideojuego)=0;
        virtual void seleccionarVideojuegoDesarrollador(idVideojuego)=0;
        virtual void listaJuegosPublicados()=0;
        virtual void seleccionarVideojuegoAEliminar(nombre_videojuego: string)=0;
        virtual void eliminarDatos()=0;
    };
#endif //LAB_3_PROYECTO_IVIDEOJUEGO_H
