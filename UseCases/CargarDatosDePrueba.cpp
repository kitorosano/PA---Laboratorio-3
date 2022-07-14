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


}
