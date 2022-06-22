cmake_minimum_required(VERSION 3.21)
project(PA___Laboratorio_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA___Laboratorio_3
        main.cpp

        Interfaces/IUsuario.h
        Interfaces/IVideojuego.h

        Controllers/UsuarioController.cpp Controllers/UsuarioController.h
        Controllers/VideojuegoController.cpp Controllers/VideojuegoController.h

        Classes/Usuario.cpp Classes/Usuario.h Classes/Jugador.cpp Classes/Jugador.h
        Classes/Gen_videojuego.h Classes/Gen_videojuego.cpp
        Classes/Categoria.h Classes/Categoria.cpp
        Classes/Suscripcion.cpp Classes/Suscripcion.h Classes/DatosSuscripcion.cpp Classes/DatosSuscripcion.h Controllers/PartidaController.cpp Controllers/PartidaController.h Interfaces/IPartida.h Classes/Partida.cpp Classes/Partida.h Classes/Individual.cpp Classes/Individual.h Classes/Multijugador.cpp Classes/Multijugador.h Classes/Comentario.cpp Classes/Comentario.h)

