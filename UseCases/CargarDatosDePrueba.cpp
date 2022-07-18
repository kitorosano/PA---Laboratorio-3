//
// Created by esteban.rosano on 27/6/2022.
//

#include "CargarDatosDePrueba.h"
#include "Factory/Factory.h"

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
    factory->getInstance()->getInterfaceC()->agregarCategoria("PC","descripción libre",PLATAFORMA, NULL);
    auto C1 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("PS4","descripción libre",PLATAFORMA, NULL);
    auto C2 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Xbox One","descripción libre",PLATAFORMA, NULL);
    auto C3 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Deporte","descripción libre",GENERO, NULL);
    auto C4 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Supervivencia","descripción libre",GENERO, NULL);
    auto C5 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Estrategia","descripción libre",GENERO, NULL);
    auto C6 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Teen","Su contenido está dirigido a jóvenes de 13 años en adelante",OTRO, NULL);
    auto C7 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("E","Su contenido está dirigido para todo público",OTRO, NULL);
    auto C8 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Acción","descripción libre",GENERO, NULL);
    auto C9 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Aventura","descripción libre",GENERO, NULL);
    auto C10 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Switch","descripción libre",PLATAFORMA, NULL);
    auto C11 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("Xbox X","descripción libre",PLATAFORMA, NULL);
    auto C12 = dynamic_cast<Categoria *>(factory->getInstance()->getInterfaceC()->confirmarCategoria());

    factory->getInstance()->getInterfaceC()->agregarCategoria("PS5","descripción libre",PLATAFORMA, NULL);
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
    factory->getInstance()->getInterfaceD()->getDatoSuscripcionSeleccionado()->setFechaSuscripcion(new DT_Fecha(1,6,21,9,0,0));
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V2->getId(), E_PeriodoValidez::TRIMESTRAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J1->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Tarjeta);
    factory->getInstance()->getInterfaceD()->getDatoSuscripcionSeleccionado()->setFechaSuscripcion(new DT_Fecha(2,6,21,11,0,0));
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V2->getId(), E_PeriodoValidez::MENSUAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J2->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Paypal);
    factory->getInstance()->getInterfaceD()->getDatoSuscripcionSeleccionado()->setFechaSuscripcion(new DT_Fecha(4,6,21,9,0,0));
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V3->getId(), E_PeriodoValidez::ANUAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J2->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Tarjeta);
    factory->getInstance()->getInterfaceD()->getDatoSuscripcionSeleccionado()->setFechaSuscripcion(new DT_Fecha(11,6,21,9,0,0));
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V2->getId(), E_PeriodoValidez::MENSUAL);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J3->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Tarjeta);
    factory->getInstance()->getInterfaceD()->getDatoSuscripcionSeleccionado()->setFechaSuscripcion(new DT_Fecha(3,6,21,7,0,0));
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();

    auxSuscripcion = factory->getInstance()->getInterfaceV()->obtenerSuscripcionVideojuego(V3->getId(), E_PeriodoValidez::VITALICIA);
    factory->getInstance()->getInterfaceD()->crearDatosSuscripcion(J3->getNickname(), auxSuscripcion->getId(), E_MetodoPago::Tarjeta);
    factory->getInstance()->getInterfaceD()->getDatoSuscripcionSeleccionado()->setFechaSuscripcion(new DT_Fecha(21,12,21,15,0,0));
    factory->getInstance()->getInterfaceD()->confirmarDatosSuscripcion();
    cout << " Agregadas correctamente!" << endl;

    // Puntajes a videojuegos
//    cout << "| Agregando puntajes a videojuegos...";
    // TODO: Implementar carga de datos
//    cout << " Agregados correctamente!" << endl;

    // Partidas Individuales
    cout << "| Agregando partidas Individuales...";
    factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(V1->getNombre());
    factory->getInstance()->getInterfaceP()->nuevaPartidaIndividual(J1);
    auto* P1 = dynamic_cast<Individual *>(factory->getInstance()->getInterfaceP()->confirmarPartida(new DT_Fecha(2,6,2021,9,0,0)));
    factory->getInstance()->getInterfaceP()->confirmarFinalizarPartida(P1->getIdPartida(), J1, new DT_Fecha(2,6,2021,10,0,0));

    factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(V1->getNombre());
    factory->getInstance()->getInterfaceP()->continuarPartidaIndividual(P1->getIdPartida(), J1);
    auto* P2 = dynamic_cast<Individual *>(factory->getInstance()->getInterfaceP()->confirmarPartida(new DT_Fecha(3,6,2021,15,0,0)));
    factory->getInstance()->getInterfaceP()->confirmarFinalizarPartida(P2->getIdPartida(), J1, new DT_Fecha(3,6,2021,16,0,0));

    factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(V3->getNombre());
    factory->getInstance()->getInterfaceP()->nuevaPartidaIndividual(J2);
    auto* P3 = dynamic_cast<Individual *>(factory->getInstance()->getInterfaceP()->confirmarPartida(new DT_Fecha(12,6,2021,16,0,0)));
    cout << " Agregadas correctamente!" << endl;

    // Partidas multijugador
    cout << "| Agregando partidas multijugador...";
    factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(V2->getNombre());
    factory->getInstance()->getInterfaceP()->nuevaPartidaMultijugador(J1, true);
    factory->getInstance()->getInterfaceP()->ingresarNicknameALaPartida(J2->getNickname());
    factory->getInstance()->getInterfaceP()->ingresarNicknameALaPartida(J3->getNickname());
    auto P4 = dynamic_cast<Multijugador *>(factory->getInstance()->getInterfaceP()->confirmarPartida(new DT_Fecha(5,6,2021,17,0,0)));

    factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(V2->getNombre());
    factory->getInstance()->getInterfaceP()->nuevaPartidaMultijugador(J1, true);
    factory->getInstance()->getInterfaceP()->ingresarNicknameALaPartida(J2->getNickname());
    factory->getInstance()->getInterfaceP()->ingresarNicknameALaPartida(J3->getNickname());
    auto P5 = dynamic_cast<Multijugador *>(factory->getInstance()->getInterfaceP()->confirmarPartida(new DT_Fecha(6,6,2021,17,0,0)));

    factory->getInstance()->getInterfaceV()->seleccionarVideoJuego(V3->getNombre());
    factory->getInstance()->getInterfaceP()->nuevaPartidaMultijugador(J2, false);
    factory->getInstance()->getInterfaceP()->ingresarNicknameALaPartida(J3->getNickname());
    auto P6 = dynamic_cast<Multijugador *>(factory->getInstance()->getInterfaceP()->confirmarPartida(new DT_Fecha(12,6,2021,20,0,0)));
    cout << " Agregadas correctamente!" << endl;
/*
    // Abandonar partida multijugador
    cout << "| Agregando abandonos de partida multijugador...";
    factory->getInstance()->getInterfaceP()->confirmarAbandonoPartida(P4->getIdPartida(), J2, new DT_Fecha(5,6,21,18,0,0));
    factory->getInstance()->getInterfaceP()->confirmarAbandonoPartida(P5->getIdPartida(), J2, new DT_Fecha(6,6,21,17,30,0));
    cout << " Agregados correctamente!" << endl;*/

    // Finalizar partida multijugador
    cout << "| Finalizando partidas multijugador...";
    factory->getInstance()->getInterfaceP()->confirmarFinalizarPartida(P4->getIdPartida(), J1, new DT_Fecha(5,6,2021,19,0,0));
    factory->getInstance()->getInterfaceP()->confirmarFinalizarPartida(P5->getIdPartida(), J1, new DT_Fecha(6,6,2021,19,0,0));
    cout << " Finalizadas correctamente!" << endl;

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|       CARGAR DATOS DE PRUEBA COMPLETADA!!      |"<<endl;
    cout<<"|------------------------------------------------|"<<endl<<endl;
}
