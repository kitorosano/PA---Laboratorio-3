//
// Created by esteban.rosano on 27/6/2022.
//

#include "CargarDatosDePrueba.h"
#include "Factory/Factory.h"
#include "Utils/Utils.h"
#include "ColeccionesG/KeyInt.h"

void CargarDatosDePrueba() {
    Factory* factory;

    cout<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|            CARGAR DATOS DE PRUEBA              |"<<endl;
    cout<<"|------------------------------------------------|"<<endl;

    // Desarrolladores
    cout << "| Agregando desarrolladores...";
    factory->getInstance()->getInterfaceU()->registroDesarrollador("ironhide@mail.com","123", "Ironhide Game Studio");
    auto D1 = dynamic_cast<Desarrollador *>(factory->getInstance()->getInterfaceU()->confirmarRegistro());

    factory->getInstance()->getInterfaceU()->registroDesarrollador("epic@mail.com","123", "Epic Games");
    auto D2 = dynamic_cast<Desarrollador *>(factory->getInstance()->getInterfaceU()->confirmarRegistro());

    factory->getInstance()->getInterfaceU()->registroDesarrollador("mojang@mail.com","123", "Mojang Studios");
    auto D3 = dynamic_cast<Desarrollador *>(factory->getInstance()->getInterfaceU()->confirmarRegistro());

    factory->getInstance()->getInterfaceU()->registroDesarrollador("ea@mail.com","123", "EA Sports");
    auto D4 = dynamic_cast<Desarrollador *>(factory->getInstance()->getInterfaceU()->confirmarRegistro());
    cout << " Agregados correctamente!" << endl;


    // Jugadores
    cout << "| Agregando jugadores...";
    factory->getInstance()->getInterfaceU()->registroJugador("gamer@mail.com","123","gamer","algo");
    auto J1 = dynamic_cast<Jugador *>(factory->getInstance()->getInterfaceU()->confirmarRegistro());

    factory->getInstance()->getInterfaceU()->registroJugador("ari@mail.com","123","ari","algo");
    auto J2 = dynamic_cast<Jugador *>(factory->getInstance()->getInterfaceU()->confirmarRegistro());

    factory->getInstance()->getInterfaceU()->registroJugador("ibai@mail.com","123","ibai","algo");
    auto J3 = dynamic_cast<Jugador *>(factory->getInstance()->getInterfaceU()->confirmarRegistro());

    factory->getInstance()->getInterfaceU()->registroJugador("camila@mail.com","123","camila","algo");
    auto J4 = dynamic_cast<Jugador *>(factory->getInstance()->getInterfaceU()->confirmarRegistro());
    cout << " Agregados correctamente!" << endl;


    // Categorias
    cout << "| Agregando categorias...";
    factory->getInstance()->getInterfaceC()->agregarCategoria("PC","descripción libre",PLATAFORMA);
    auto C1 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("PS4","descripción libre",PLATAFORMA);
    auto C2 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Xbox One","descripción libre",PLATAFORMA);
    auto C3 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Deporte","descripción libre",GENERO);
    auto C4 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Supervivencia","descripción libre",GENERO);
    auto C5 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Estrategia","descripción libre",GENERO);
    auto C6 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Teen","Su contenido está dirigido a jóvenes de 13 años en adelante",OTRO);
    auto C7 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("E","Su contenido está dirigido para todo público",OTRO);
    auto C8 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Acción","descripción libre",GENERO);
    auto C9 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Aventura","descripción libre",GENERO);
    auto C10 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Switch","descripción libre",PLATAFORMA);
    auto C11 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Xbox X","descripción libre",PLATAFORMA);
    auto C12 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("PS5","descripción libre",PLATAFORMA);
    auto C13 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());
    cout << " Agregadas correctamente!" << endl;


    // Videojuegos
    cout << "| Agregando videojuegos...";
    factory->getInstance()->getInterfaceV()->datosNuevoVideojuego("KingdomRush", "Un gran juego 1", 1, 2, 7, 14, D1);
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C1->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C2->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C6->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C8->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    auto V1 = dynamic_cast<Videojuego *>(factory->getInstance()->getInterfaceV()->confirmarVideojuego());

    factory->getInstance()->getInterfaceV()->datosNuevoVideojuego("Fortnite", "Un gran juego 2", 3, 8, 30, 60, D2);
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C1->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C2->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C3->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C5->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C7->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    auto V2 = dynamic_cast<Videojuego *>(factory->getInstance()->getInterfaceV()->confirmarVideojuego());

    factory->getInstance()->getInterfaceV()->datosNuevoVideojuego("Minecraft", "Un gran juego 3", 2, 5, 20, 40, D3);
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C1->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C5->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C8->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    auto V3 = dynamic_cast<Videojuego *>(factory->getInstance()->getInterfaceV()->confirmarVideojuego());

    factory->getInstance()->getInterfaceV()->datosNuevoVideojuego("FIFA 21", "Un gran juego 4", 3, 8, 28, 50,D4);
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C1->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C2->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C3->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C4->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    factory->getInstance()->getInterfaceC()->seleccionarCategoria(C8->getNombre());
    factory->getInstance()->getInterfaceC()->agregarVideojuegoACategoria();
    auto V4 = dynamic_cast<Videojuego *>(factory->getInstance()->getInterfaceV()->confirmarVideojuego());
    cout << " Agregados correctamente!" << endl;


    // Suscripcion a videojuegos
    cout << "| Agregando suscripcion a videojuegos...";
    Suscripcion *auxSuscripcion;
    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V1->getId(), E_PeriodoValidez::TRIMESTRAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J1->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Paypal);
//    factory->getInstance()->getInterfaceD()->getDatoSuscripcionSeleccionado()->setFechaSuscripcion();
//    factory->getInstance()->getInterfaceD()->getDatoSuscripcionSeleccionado()->setHoraSuscripcion();
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V2->getId(), E_PeriodoValidez::TRIMESTRAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J1->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Tarjeta);
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V2->getId(), E_PeriodoValidez::MENSUAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J2->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Paypal);
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V3->getId(), E_PeriodoValidez::ANUAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J2->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Tarjeta);
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V2->getId(), E_PeriodoValidez::MENSUAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J3->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Tarjeta);
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V3->getId(), E_PeriodoValidez::VITALICIA);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J3->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Tarjeta);
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    cout << " Agregadas correctamente!" << endl;

    // Puntajes a videojuegos
//    cout << "| Agregando puntajes a videojuegos...";
    // TODO: Implementar carga de datos
//    cout << " Agregados correctamente!" << endl;

    // Partidas Individuales
//    cout << "| Agregando partidas Individuales...";
    // TODO: Implementar carga de datos
//    cout << " Agregadas correctamente!" << endl;

    // Partidas multijugador
//    cout << "| Agregando partidas multijugador...";
    // TODO: Implementar carga de datos
//    cout << " Agregadas correctamente!" << endl;

    // Abandonar partida multijugador
//    cout << "| Agregando abandonos de partida multijugador...";
    // TODO: Implementar carga de datos
//    cout << " Agregados correctamente!" << endl;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|       CARGAR DATOS DE PRUEBA COMPLETADA!!      |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;

    presionaParaContinuar();
}
