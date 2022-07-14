//
// Created by esteban.rosano on 27/6/2022.
//

#include "CargarDatosDePrueba.h"
#include "Factory/Factory.h"

void CargarDatosDePrueba() {
    Factory* factory;
  
  cout << "Agregando desarrolladores" << endl;
    // Desarrolladores
    factory->getInterfaceU()->registroDesarrollador("ironhide@mail.com","123", "Ironhide Game Studio");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroDesarrollador("epic@mail.com","123", "Epic Games");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroDesarrollador("mojang@mail.com","123", "Mojang Studios");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroDesarrollador("ea@mail.com","123", "EA Sports");
    factory->getInterfaceU()->confirmarRegistro();
  
  cout << "Agregando jugadores" << endl;
    // Jugadores
    factory->getInterfaceU()->registroJugador("gamer@mail.com","123","gamer","algo");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroJugador("ari@mail.com","123","ari","algo");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroJugador("ibai@mail.com","123","ibai","algo");
    factory->getInterfaceU()->confirmarRegistro();
    factory->getInterfaceU()->registroJugador("camila@mail.com","123","camila","algo");
    factory->getInterfaceU()->confirmarRegistro();

    cout << "Agregando categorias" << endl;
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
  
  cout << "Agregando videojuegos" << endl;
    // Videojuegos
    factory->getInterfaceV()->datosNuevoVideojuego("KingdomRush", "Un gran juego 1", 1, 2, 7, 14);
  
    cout << "Agregando videojuegos" << endl;
    factory->getInterfaceC()->seleccionarCategoria("PC");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("PS4");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("Estrategia");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("E");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceV()->confirmarVideojuego();
    cout << "Videojuego1 publicado" << endl;
    factory->getInterfaceV()->datosNuevoVideojuego("Fortnite", "Un gran juego 2", 3, 8, 30, 60);
    factory->getInterfaceC()->seleccionarCategoria("PC");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("PS4");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("Xbox One");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("Supervivencia");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("Teen");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceV()->confirmarVideojuego();
  cout << "Videojuego2 publicado" << endl;
    factory->getInterfaceV()->datosNuevoVideojuego("Minecraft", "Un gran juego 3", 2, 5, 20, 40);
    factory->getInterfaceC()->seleccionarCategoria("PC");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("Supervivencia");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("E");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceV()->confirmarVideojuego();
  cout << "Videojuego3 publicado" << endl;
    factory->getInterfaceV()->datosNuevoVideojuego("FIFA 21", "Un gran juego 4", 3, 8, 28, 50);
    factory->getInterfaceC()->seleccionarCategoria("PC");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("PS4");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("Xbox One");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("Deporte");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceC()->seleccionarCategoria("E");
    factory->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInterfaceV()->confirmarVideojuego();

    // Suscripciones
  
  cout << "Termino" << endl;
}
