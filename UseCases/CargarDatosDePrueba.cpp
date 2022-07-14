//
// Created by esteban.rosano on 27/6/2022.
//

#include "CargarDatosDePrueba.h"
#include "Factory/Factory.h"

void CargarDatosDePrueba() {
    Factory* factory;

    // Desarrolladores
    factory->getInterfaceU()->registroDesarrollador("ironhide@mail.com","123", "Ironhide Game Studio");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroDesarrollador("epic@mail.com","123", "Epic Games");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroDesarrollador("mojang@mail.com","123", "Mojang Studios");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroDesarrollador("ea@mail.com","123", "EA Sports");
    factory->getInterfaceU()->confirmarRegistro();

    // Jugadores
    factory->getInterfaceU()->registroJugador("gamer@mail.com","123","gamer","algo");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroJugador("ari@mail.com","123","ari","algo");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroJugador("ibai@mail.com","123","ibai","algo");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroJugador("camila@mail.com","123","camila","algo");
    factory->getInterfaceU()->confirmarRegistro();

    // Categorias
    factory->getInterfaceC()->agregarCategoria("PC","descripción libre",PLATAFORMA);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("PS4","descripción libre",PLATAFORMA);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Xbox One","descripción libre",PLATAFORMA);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Deporte","descripción libre",GENERO);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Supervivencia","descripción libre",GENERO);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Estrategia","descripción libre",GENERO);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Teen","Su contenido está dirigido a jóvenes de 13 años en adelante",OTRO);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("E","Su contenido está dirigido para todo público",OTRO);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Acción","descripción libre",GENERO);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Aventura","descripción libre",GENERO);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Switch","descripción libre",PLATAFORMA);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("Xbox X","descripción libre",PLATAFORMA);
    factory->getInterfaceC()->confirmarCategoria();
    factory->getInterfaceC()->agregarCategoria("PS5","descripción libre",PLATAFORMA);
    factory->getInterfaceC()->confirmarCategoria();

    // Videojuegos
    factory->getInstance()->getInterfaceV()->datosNuevoVideojuego("KingdomRush", "Un gran juego 1", 1, 2, 7, 14);
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("PC");
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("PS4");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("Estrategia");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("E");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceV()->confirmarVideojuego();
    factory->getInstance()->getInterfaceV()->datosNuevoVideojuego("Fortnite", "Un gran juego 2", 3, 8, 30, 60);
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("PC");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("PS4");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("Xbox One");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("Supervivencia");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("Teen");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceV()->confirmarVideojuego();
    factory->getInstance()->getInterfaceV()->datosNuevoVideojuego("Minecraft", "Un gran juego 3", 2, 5, 20, 40);
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("PC");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("Supervivencia");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("E");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceV()->confirmarVideojuego();
    factory->getInstance()->getInterfaceV()->datosNuevoVideojuego("FIFA 21", "Un gran juego 4", 3, 8, 28, 50);
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("PC");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("PS4");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("Xbox One");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("Deporte");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria("E");
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceV()->confirmarVideojuego();

    // Suscripciones

}
